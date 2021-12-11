#ifndef _MAP_HPP
#define _MAP_HPP
#include <iostream>
#include "pair.hpp"
namespace ft
{
	template < class Key, class T, class Compare = std::less<Key> , class Alloc = std::allocator<ft::pair<const Key, T> > > 
	class map
	{
		public:
		typedef Key     key_type;
		typedef T       mapped_type;
		typedef ft::pair<key_type, mapped_type> value_type;
		typedef Compare     key_compare;
		private:

	};
}



#endif