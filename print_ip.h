#pragma once

#include "tupleToVector.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

template<bool B, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if<true, T>
{
	typedef T type;
};

template<bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;

namespace pip
{

	template<
			template <typename, typename> typename C,
			typename T,
			typename alloc = std::allocator<T>
			>
	void PrintIP(const C<T, alloc>&);

	//string
	template<
			typename T,
			typename = std::enable_if_t<std::is_same<T, std::string>::value>
			>
	void PrintIP(const T& str)
	{
		cout << str;
	}

	// integer
	template<
			typename T,
			typename = std::enable_if_t<std::is_integral<T>::value>
			>
	void PrintIP(const T t)
	{
		auto size = sizeof(T);
		if (size == 1)
		{
			if (t < 0)
			{
				cout << 256 + t;
			}
			else
			{
				cout << t;
			}
		}
		else
		{
			std::vector<int> v(size, 0);
			T num = abs(t);
			unsigned int i = size - 1;
			while (num > 256)
			{
				int min = int(num % 256);
				v[i] = min;
				num = num / 256;
				--i;
			}
			v[i] = int(num);
			PrintIP(v);
		}
	}

	// containers
	template<
			template <typename, typename> typename C,
			typename T,
			typename alloc
			>
	void PrintIP(const C<T, alloc>& container)
	{
		auto cit = container.begin();
		while (cit != container.end())
		{
			cout << *cit;
			if (cit != prev(container.end()))
			{
				cout << '.';
			}
			++cit;
		}
	}

	// tuple
	template<typename... T>
	void PrintIP(const std::tuple<T... >& t)
	{
		std::vector<int> v;
		ttv::tupleToVector(t, v, ttv::callback());
		PrintIP(v);
	}
}