#include <atomic>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <syncstream>

template <typename T>
class LockFreeStack
{
private:
    struct Node
    {
        T data;
        std::shared_ptr<Node> next;
        Node(T d) : data(d) {}
    };
    std::atomic<std::shared_ptr<Node>> head;

public:
    LockFreeStack() = default;
    LockFreeStack(const LockFreeStack &) = delete;
    LockFreeStack &operator=(const LockFreeStack &) = delete;

    void push(T val)
    {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(val); 
        newNode->next = head.load();                                 
        while (!head.compare_exchange_strong(newNode->next, newNode)); 
        std::osyncstream(std::cout) << "Pushed: " << val << "\n";
    }

    bool pop(T &result)
    {
        std::shared_ptr<Node> oldHead = head.load();
        if (oldHead == nullptr)
        {
            std::osyncstream(std::cout) << "Pop failed - stack is empty.\n";
            return false;
        }

        while (oldHead && !head.compare_exchange_strong(oldHead, oldHead->next))
            ;
        if (oldHead)
        {
            result = oldHead->data;
            std::osyncstream(std::cout) << "Popped: " << result << "\n";
            return true;
        }
        else
            return false;
    }
};

void pushItems(LockFreeStack<int> &stack, int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        stack.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Add delay
    }
}

void popItems(LockFreeStack<int> &stack, int count)
{
    int value;
    for (int i = 0; i < count; ++i)
    {
        stack.pop(value);
        std::this_thread::sleep_for(std::chrono::milliseconds(30)); // Add delay
    }
}

int main()
{
    LockFreeStack<int> stack;

    // Create multiple threads for push and pop operations
    std::thread t1(pushItems, std::ref(stack), 1, 10);
    std::thread t2(popItems, std::ref(stack), 7);
    std::thread t3(pushItems, std::ref(stack), 10, 20);
    std::thread t4(popItems, std::ref(stack), 7);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
