#include <iostream>
#include <string>
#include <sstream>

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

template<typename T>
std::string format(T first)
{
	return first;
}

template<typename T, typename... Rest>
std::string format(const char *s, T first, Rest... rest)
{
	std::stringstream result;
	for (; *s != '\0'; s++)
	{
		if (*s == '{' && *(s + 1) == '}')
		{
			result << first;
			s += 2;
			break;
		}
		else
		{
			result << *s;
		}
	}
	result << format(s, rest...);
	return result.str();
}

int main()
{
	std::cout << sum(1, 2, 3, 4, 5) << std::endl;
	std::string s = format("{} {} {}", "hello", 1, 5.2f);
	std::cout << s;
	return 0;
}