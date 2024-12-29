#include <type_traits>

template<typename T>
struct my_is_integral_helper: std::false_type{};

template<>
struct my_is_integral_helper<int>: std::true_type{};

template<>
struct my_is_integral_helper<bool>: std::true_type{};

template<>
struct my_is_integral_helper<char>: std::true_type{};

template<>
struct my_is_integral_helper<long>: std::true_type{};

template<>
struct my_is_integral_helper<long long>: std::true_type{};

template<>
struct my_is_integral_helper<unsigned char>: std::true_type{};

template<>
struct my_is_integral_helper<unsigned long>: std::true_type{};

template<>
struct my_is_integral_helper<unsigned long long>: std::true_type{};

template<>
struct my_is_integral_helper<signed char>: std::true_type{};


template<typename T>
struct my_is_integral:public my_is_integral_helper<typename std::remove_cv<T>::type>{};

template <typename T>
constexpr bool my_is_integral_v{my_is_integral<T>::value};

