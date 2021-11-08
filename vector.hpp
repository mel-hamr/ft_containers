
#include<iostream>

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
	private:
		allocator_type _Alloc;
		T* _Containers;
		int _size;
		int _capacity;
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
		~vector();
};

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
	private :
		T *p;
	public:
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
		// p=nullptr;
	}
	reverse_VectorIterator (iterator_type it)
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
