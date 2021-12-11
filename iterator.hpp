#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
namespace ft
{
		template <class Iterator>
	class iterator_traits
	{
		typedef typename	Iterator::difference_type	difference_type; 
		typedef typename	Iterator::value_type		value_type;
		typedef	typename	Iterator::pointer			pointer;
		typedef typename	Iterator::reference			reference;
		typedef typename	Iterator::iterator_category	iterator_category;
	};

	template <class	T>
	class iterator_traits<T*>
	{
		typedef	ptrdiff_t									difference_type; 
		typedef T											value_type;
		typedef	T*											pointer;
		typedef T&											reference;
		typedef typename	std::random_access_iterator_tag	iterator_category;
	};

	template <class T> 
	class iterator_traits<const T*>
	{
		typedef	ptrdiff_t									difference_type; 
		typedef	T											value_type;
		typedef	const T*									pointer;
		typedef	T&											reference;
		typedef typename	std::random_access_iterator_tag	iterator_category;
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <typename T>
	class VectorIterator : public iterator<std::input_iterator_tag , T >
	{
		// private :
		public:
			T *p;
			// VectorIterator() :p(nullptr) {}
			VectorIterator(T* x) :p(x) {}
			VectorIterator(const VectorIterator& mit) : p(mit.p) {}
			T*	base()const 
			{
				return (*p);
			}
			T* operator+(T n) const
			{
				return (p + n);
			}
			T* operator-(T n) const
			{
				return (p - n);
			}
			T* operator++()
			{
				p++;
				return (p);
			};
			T* operator++(int)
			{
				T *temp;

				temp = p;
				p++;
				return(temp);
			}
			T* operator--()
			{
				p--;
				return (p);
			};
			T* operator-=(T	n)
			{
				p = p - n;
				return (p);
			};
			T* operator+=(T	n)
			{
				p = p + n;
				return (p);
			};
			T* operator--(int)
			{
				T	*temp;

				temp = p;
				p--;
				return(temp);
			}
			bool operator==(const VectorIterator& rhs) const
			{
				return p==rhs.p;
			}
			bool operator!=(const VectorIterator& rhs) const
			{
				return p!=rhs.p;
			}
			int& operator*()
			{
				return *p;
			}
			T	operator[](int n)
			{
				return (p[n]);
			}
	};
}

#endif