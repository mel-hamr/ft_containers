#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator.hpp"

namespace ft
{
    template <class Iterator>
class reverse_Iterator
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
	reverse_Iterator()
	{
		// p=nullptr;
	}
	reverse_Iterator (iterator_type it)
	{
		*this = it;
	}
		// VectorIterator(T* x) :p(x) {}
		// VectorIterator(const VectorIterator& mit) : p(mit.p) {}
		// VectorIterator& operator++()
		// {
		// 	++p;
		// 	return *this;
		// }
		// VectorIterator operator++(int)
		// {
		// 	VectorIterator tmp(*this);
		// 	++p;
		// 	return tmp;
		// }
		// bool operator==(const VectorIterator& rhs) const
		// {
		// 	return p==rhs.p;
		// }
		// bool operator!=(const VectorIterator& rhs) const
		// {
		// 	return p!=rhs.p;
		// }
		// int& operator*()
		// {
		// 	return *p;
		// }
};
}
#endif