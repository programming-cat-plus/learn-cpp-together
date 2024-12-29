#include <type_traits>
template<typename T>
struct my_is_integral: std::false_type{};

template <typename T>
constexpr bool my_is_integral_v{my_is_integral<T>::value};

template<>
struct my_is_integral<int>: std::true_type{};

template<>
struct my_is_integral<bool>: std::true_type{};

template<>
struct my_is_integral<char>: std::true_type{};

template<>
struct my_is_integral<long>: std::true_type{};

template<>
struct my_is_integral<long long>: std::true_type{};

template<>
struct my_is_integral<unsigned char>: std::true_type{};

template<>
struct my_is_integral<unsigned long>: std::true_type{};

template<>
struct my_is_integral<unsigned long long>: std::true_type{};

template<>
struct my_is_integral<signed char>: std::true_type{};


