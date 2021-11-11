#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR
#include "vector.hpp"
namespace ft
{

template <class Iterator>
class reverse_VectorIterator
{
	typedef typename	iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename	iterator_traits<Iterator>::value_type		value_type;
	typedef typename	iterator_traits<Iterator>::difference_type	difference_type; 
	typedef	typename	iterator_traits<Iterator>::pointer			pointer;
	typedef typename	iterator_traits<Iterator>::reference			reference;
	typedef				Iterator	iterator_type;
	
	private :
	iterator_type	i;
	public:
	reverse_VectorIterator()
	{
		i = nullptr;
	}
	reverse_VectorIterator (iterator_type it)
	{
		i = it;
	}
	reverse_VectorIterator& operator++()
	{
		i--;
		return *this;
	}
	reverse_VectorIterator operator++(int)
	{
		reverse_VectorIterator tmp;

		tmp = *this;
		i--;
		return tmp;
	}
	reverse_VectorIterator& operator--()
	{
		i++;
		return *this;
	}
	reverse_VectorIterator operator--(int)
	{
		reverse_VectorIterator tmp;

		tmp = *this;
		i++;
		return tmp;
	}
	reverse_VectorIterator operator+=(int n)
	{
		i -= n;
		return *this;
	}
	reverse_VectorIterator operator-=(int n)
	{
		i += n;
		return *this;
	}

	bool operator==(const iterator_type& rhs) const
	{
		return i==rhs.p;
	}
	bool operator!=(const iterator_type& rhs) const
	{
		return i!=rhs.p;
	}
	int& operator*()
	{
		return *i;
	}
	reference operator*() const
	{
		return (*i);
	}

};

}

#endif