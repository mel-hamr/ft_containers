#ifndef VECTOR_HPP
#define VECTOR_HPP

#include<iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
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
			typedef typename ft::VectorIterator<T> iterator;
			typedef size_t size_type;
		private:
			allocator_type _Alloc;
			T* _Container;
			int _size;
			int _capacity;
		public:
			explicit vector (const allocator_type& alloc = allocator_type()) :_Alloc(alloc), _Container(nullptr) , _size(0) , _capacity(0)
			{
				;
			}
			explicit vector (size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_capacity = n;
				_size = 0;
				_Container = _Alloc.allocate(n);
				while (_size < _capacity)
				{
					_Container[_size] = val;
					_size++;
				}
			}
			void	push_back(T	val)
			{
				if(_size >= _capacity)
				{
					if(_size == 0)
					{
						_capacity = 1;
						_Container = _Alloc.allocate(1);
					}
					else
					{
						T* tmp;
						_capacity = _capacity * 2;
						tmp = _Alloc.allocate(_capacity);
						for(int i= 0 ; i < _size; i++)
							tmp[i] = _Container[i];
						delete [] _Container;
						_Container = tmp;
					}
				}
				_Container[_size] = val;
				_size++;
			}
			void pop_back()
			{
				_Alloc.destroy(&_Container[_size - 1]);
				_size -= 1;
			}
			void reserve(size_type n)
			{
				if(n > _capacity)
				{
					_capacity = n;
					T	*new_container = _Alloc.allocate(_capacity);
					for (size_t i = 0; i < _size; i++)
					{
						new_container[i] = _Container[i];
					}
					delete [] _Container;
					_Container = new_container;
				}
			}
			void resize (size_type n, value_type val = value_type())
			{
				if(n > _capacity)
				{

				}
				else
				{
					while (_size > n)
					{
						_size--;
						_Alloc.destroy(&_Container[_size]);
					}
				}
			}
			iterator begin()
			{
				iterator it(&_Container[0]);
				return (it);
			}
			iterator end()
			{
				iterator it(&_Container[_size]);
				return (it);
			}
			size_type size() const
			{
				return (_size);
			}

			size_type max_size() const
			{
				return (_Alloc.max_size());
			}
			size_type capacity() const
			{
				return (_capacity);
			}
			T& operator[](size_type n)
			{
				return ((_Container[n]));
			}

			const T& operator[](size_type n) const
			{
				return ((_Container[n]));
			}
			T& back()
			{
				return (_Container[_size - 1]);
			}

			const T& back() const
			{
				return (_Container[_size - 1]);
			}
			bool empty() const
			{
				if (!_size)
					return (true);
				return false;
			}
			~vector()
			{
					;
			}
	};

}
#endif