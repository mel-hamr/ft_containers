#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair() : first(), second(){};

		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second){};

		pair(const first_type &a, const second_type &b) : first(a), second(b){};

		pair &operator=(const pair &rhs)
		{
			if (this == &rhs)
				return *this;
			this->second = rhs.second;
			this->second = rhs.second;
			return *this;
		}

		// void swap(pair &pr) noexcept(noexcept(swap(first, pr.first)) &&
		// 							 noexcept(swap(second, pr.second)))
		// {
		// 	swap(first, pr.first);
		// 	swap(second, pr.second);
		// }
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}

#endif