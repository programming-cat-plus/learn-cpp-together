/////////////////////////////////////////////////////////////////
//
// <<一起来学C++ 29.函数封装与绑定>>视频配套例程
// customfunction.cpp
// 自定义的简化版函数封装示例
//
/////////////////////////////////////////////////////////////////

#include <bits/move.h>
#include <iostream>
template <class, class = void>
struct callback;

template <class Func, class Ret, class... Args>
struct callback<Func, Ret(Args...)>
{
	using func_t = Func;

	constexpr callback(const Func &func)
		: _func(func)
	{
	}
	constexpr callback(Func &&func)
		: _func(std::move(func))
	{
	}

	constexpr Ret operator()(Args... args) const
	{
		return _func(std::forward<Args>(args)...);
	}

private:
	Func _func;
};

struct Multiply
{
	double operator()(double a, double b) const { return a * b; };
};

int main(void)
{
	Multiply mul;
	callback<Multiply, double(double, double)> func = mul;
	double res = func(0.1, 0.2);
	std::cout<<res<<std::endl;
}