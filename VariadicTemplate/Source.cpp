#include <iostream>

template<typename T>
int sum(const T& first)
{
	return first;
}

template<typename T, typename... Rest>
int sum(const T& first, const Rest&... rest)
{
	return first + sum(rest...);
}

int main()
{
	std::cout << sum(1, 2, 3);
	//sum(1, 2, 3) = 1 + sum(2, 3)
	//sum(2, 3) = 2 + sum(3) = 5
	//sum(3) = 3
	//result => 1+2+3=6
	return 0;
}