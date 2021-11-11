#ifndef VECTOR_HPP
#define VECTOR_HPP

#include<iostream>
#include "Iterator.hpp"
#include "Reverse_iterator.hpp"


namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
		class vector
		{

			public:
				typedef Alloc allocator_type;
				typedef T   value_type;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference    const_reference;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer  const_pointer;
				typedef VectorIterator<T> iterator;
			private:
				allocator_type _Alloc;
				T* _Containers;
				int _size;
				int _capacity;
				// VectorIterator<T>	it;
			public:
				explicit vector (const allocator_type& alloc = allocator_type()) : _Containers(nullptr) , _size(0) , _capacity(0){;};
				explicit vector (size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				{


					_capacity = n;
					_size = 0;
					_Containers = _Alloc.allocate(n);
					while (_size < _capacity)
					{
						_Containers[_size] = val;
						_size++;
					}

				}
				void	push_back(T	i)
				{
					_Containers[_size] = i;
					_size++;
				}
				void reserve (size_t n)
				{
					_capacity = n;
					_Containers = _Alloc.allocate(n);
				}
				iterator	begin()
				{
					iterator it(_Containers);
					return(it);
				}
				// ~vector();
		};
}
#endif
