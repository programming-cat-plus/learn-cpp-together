/***************************** 
 * 获得值的类别
 * 
*/
#pragma once 

template<typename T>
struct value_category {
    // Or can be an integral or enum value
    static constexpr auto value = "prvalue";
};

template<typename T>
struct value_category<T&> {
    static constexpr auto value = "lvalue";
};

template<typename T>
struct value_category<T&&> {
    static constexpr auto value = "xvalue";
};

// Double parens for ensuring we inspect an expression,
// not an entity
#define VALUE_CATEGORY(expr) value_category<decltype((expr))>::value

