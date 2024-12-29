template<typename T>
struct my_is_integral_helper{
    static const bool value{false};
};

template<>
struct my_is_integral_helper<int>{
    static const bool value{true};
};

template<>
struct my_is_integral_helper<bool>{
    static const bool value{true};
};

template<>
struct my_is_integral_helper<char>{
    static const bool value{true};
};

template<>
struct my_is_integral_helper<long>{
    static const bool value{true};
};

template<>
struct my_is_integral_helper<long long>{
    static const bool value{true};
};

template<>
struct my_is_integral_helper<unsigned char>{
    static const bool value{true};
};

template<>
struct my_is_integral_helper<unsigned long>{
    static const bool value{true};
};

template<>
struct my_is_integral_helper<unsigned long long>{
    static const bool value{true};
};

template<>
struct my_is_integral_helper<signed char>{
    static const bool value{true};
};

template<>
struct my_is_integral_helper<signed long>{
    static const bool value{true};
};

template<>
struct my_is_integral_helper<signed long long>{
    static const bool value{true};
};

