#pragma once

#include <tuple>
#include <vector>

namespace ttv
{
	struct callback
	{
		template<typename T>
		T operator()(T& element)
		{
			return element;
		}
	};

	template<int index, typename Callback, typename U, typename... T>
	struct tuple_to_vector
	{
		static void next(const std::tuple<T...>& t, std::vector<U>& v, Callback callback)
		{
			tuple_to_vector<index - 1, Callback, U, T...>::next(t, v, callback);
			auto element = callback(std::get<index>(t));
			v.push_back(element);
		}
	};

	template<typename Callback, typename U, typename... T>
	struct tuple_to_vector<0, Callback, U, T...>
	{
		static void next(const std::tuple<T...>& t, std::vector<U>& v, Callback callback)
		{
			auto element = callback(std::get<0>(t));
			v.push_back(element);
		}
	};

	template<typename Callback, typename U, typename... T>
	struct tuple_to_vector<-1, Callback, U, T...>
	{
		static void next(const std::tuple<T...>& t, std::vector<U>& v, Callback callback) {}
	};

	template<typename Callback, typename U, typename... T>
	void tupleToVector(const std::tuple<T...>& t, std::vector<U>& v, Callback callback)
	{
		int const size = std::tuple_size<std::tuple<T...>>::value;
		tuple_to_vector<size - 1, Callback, U, T...>::next(t, v, callback);
	}

}