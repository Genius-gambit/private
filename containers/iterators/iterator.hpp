#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <exception>
# include <stdexcept>
# include <memory>
# include <cstddef>
# include <algorithm>
# include <iostream>
# include "../utils/container_utils.hpp"

namespace ft
{
	//! -------------------------------------------- My Iterator Class -------------------------------------------- !//
	template <class T>
	class Iterator
	{
		public:
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag		iterator_category;

			Iterator() : _it(NULL) {}
			Iterator(pointer ptr) : _it(ptr) {}
			template <typename U>
			Iterator(const Iterator<U>&	other) : _it(other.getPtr()) {}
			Iterator	&operator=(const Iterator &rhs)
			{
				_it = rhs._it;
				return (*this);
			}
			pointer	getPtr() const { return (_it); }
			reference	operator*() const { return (*_it); }
			pointer		operator->() const { return (_it); }
			Iterator	&operator++() {_it++; return (*this); }
			Iterator	operator++(int) { Iterator	tmp = *this; ++(*this); return (tmp); }
			Iterator	&operator--() {_it--; return (*this); }
			Iterator	operator--(int) { Iterator	tmp = *this; --(*this); return (tmp); }
			Iterator	operator+(difference_type n) const { return (_it + n); }
			Iterator	operator-(difference_type n) const { return (_it - n); }
			Iterator	&operator+=(difference_type n) { _it += n; return (*this); }
			Iterator	&operator-=(difference_type n) { _it -= n; return (*this); }
			value_type	&operator[](difference_type n) { return (*(_it + n)); }
		
		private:
			pointer	_it;
	};

	template<typename T>
	typename ft::Iterator<T>::difference_type operator==(const ft::Iterator<T> lhs,
		const ft::Iterator<T> rhs) { return (lhs.getPtr() == rhs.getPtr()); }
	template<typename T1, typename T2>
	typename ft::Iterator<T1>::difference_type operator==(const ft::Iterator<T1> lhs,
		const ft::Iterator<T2> rhs) { return (lhs.getPtr() == rhs.getPtr()); }

	template<typename T>
	bool	operator!=(const ft::Iterator<T> lhs,
		const ft::Iterator<T> rhs) { return (lhs.getPtr() != rhs.getPtr()); }
	template<typename T1, typename T2>
	bool	operator!=(const ft::Iterator<T1> lhs,
		const ft::Iterator<T2> rhs) { return (lhs.getPtr() != rhs.getPtr()); }

	template<typename T>
	bool	operator>(const ft::Iterator<T> lhs,
		const ft::Iterator<T> rhs) { return (lhs.getPtr() > rhs.getPtr()); }
	template<typename T1, typename T2>
	bool	operator>(const ft::Iterator<T1> lhs,
		const ft::Iterator<T2> rhs) { return (lhs.getPtr() > rhs.getPtr()); }

	template<typename T>
	bool	operator<(const ft::Iterator<T> lhs,
		const ft::Iterator<T> rhs) { return (lhs.getPtr() < rhs.getPtr()); }
	template<typename T1, typename T2>
	bool	operator<(const ft::Iterator<T1> lhs,
		const ft::Iterator<T2> rhs) { return (lhs.getPtr() < rhs.getPtr()); }

	template<typename T>
	bool	operator>=(const ft::Iterator<T> lhs,
		const ft::Iterator<T> rhs) { return (!(lhs.getPtr() < rhs.getPtr())); }
	template<typename T1, typename T2>
	bool	operator>=(const ft::Iterator<T1> lhs,
		const ft::Iterator<T2> rhs) { return (!(lhs.getPtr() < rhs.getPtr())); }

	template<typename T>
	bool	operator<=(const ft::Iterator<T> lhs,
		const ft::Iterator<T> rhs) { return (!(lhs.getPtr() > rhs.getPtr())); }
	template<typename T1, typename T2>
	bool	operator<=(const ft::Iterator<T1> lhs,
		const ft::Iterator<T2> rhs) { return (!(lhs.getPtr() > rhs.getPtr())); }

	template<typename T>
	typename ft::Iterator<T>::difference_type operator-(const ft::Iterator<T> lhs,
		const ft::Iterator<T> rhs) { return (lhs.getPtr() - rhs.getPtr()); }
	template<typename T1, typename T2>
	typename ft::Iterator<T1>::difference_type operator-(const ft::Iterator<T1> lhs,
		const ft::Iterator<T2> rhs) { return (lhs.getPtr() - rhs.getPtr()); }

	template<typename T>
	typename ft::Iterator<T>::difference_type operator+(const ft::Iterator<T> lhs,
		const ft::Iterator<T> rhs) { return (lhs.getPtr() + rhs.getPtr()); }
	template<typename T1, typename T2>
	typename ft::Iterator<T1>::difference_type operator+(const ft::Iterator<T1> lhs,
		const ft::Iterator<T2> rhs) { return (lhs.getPtr() + rhs.getPtr()); }

	template<typename T> ft::Iterator<T>	operator+(typename ft::Iterator<T>::difference_type x,
		typename ft::Iterator<T> &rhs) { return (&(*rhs) + x); }
}

#endif