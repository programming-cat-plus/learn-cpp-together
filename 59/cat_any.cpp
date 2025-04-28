#include <iostream>
#include <typeinfo>
namespace cat_cpp
{
    class any
    {
    public:
        any() : data(nullptr), helperfunc(nullptr) {}
        ~any()
        {
            if (helperfunc != nullptr)
                helperfunc(Destroy, *this, nullptr);
        }
        template <typename T>
        any(const T &value)
        {
            data = new T(value);
            using DecayedType = typename std::decay<T>::type;
            helperfunc = &any::manager<DecayedType>;
        }              

        any &operator=(const any &other)
        {
            if (this != &other)
            {
                if (helperfunc != nullptr)
                    helperfunc(Destroy, *this, nullptr);

                if (other.helperfunc)
                    other.helperfunc(Copy, *this, &other);
            }
            return *this;
        }

        void print()
        {
            if(helperfunc)
                helperfunc(Print, *this, nullptr);
            else
                std::cout << "No data" << std::endl;
        }

    private:
        void *data;
        enum operation
        {
            Destroy,
            Copy,
            AnyCast,
            Typeinfo,
            Print
        };
        typedef void *(*Helperfunction)(operation op, any &left, const any *right);
        Helperfunction helperfunc;

    private:
        template <typename T>
        static void *manager(operation op, any &left, const any *right)
        {
            switch (op)
            {
            case Destroy:
                delete static_cast<T *>(left.data);
                break;
            case Copy:
                left.data = new T(*static_cast<const T *>(right->data));
                left.helperfunc = right->helperfunc;
                break;
            case Typeinfo:
                return const_cast<void *>(static_cast<const void *>(&typeid(T)));
            case AnyCast:
                return static_cast<T *>(left.data);
            case Print:
                if (left.data)
                    std::cout << "Data: " << *static_cast<T *>(left.data) << std::endl;
                else
                    std::cout << "No data" << std::endl;
                break;
            }
            return 0;
        }
        template <typename T>
        friend T any_cast(any &a)
        {
            if (a.helperfunc == nullptr)
                throw std::bad_cast();
            return *static_cast<T *>(a.helperfunc(AnyCast, a, nullptr));
        }
    };
}

using namespace cat_cpp;
int main()
{

    any a(1);
    a.print();

    std::string s{"hello world"};
    a = s;
    a.print();

    a = 3.14;
    a.print();
    
    any b(666);
    a = b;
    b.print();

    try
    {
        std::cout << "a = " << any_cast<int>(a) << std::endl; 
    }
    catch (const std::bad_cast &e)
    {
        std::cout << "Bad any cast: " << e.what() << std::endl;
    }

    return 0;
}