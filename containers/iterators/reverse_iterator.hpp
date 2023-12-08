#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <exception>
# include <stdexcept>
# include <memory>
# include <cstddef>
# include <algorithm>
# include <iostream>
# include "iterator.hpp"

namespace ft
{
	//! -------------------------------------------- My Iterator Class -------------------------------------------- !//
	template <class Iterator>
	class reverse_Iterator
	{
		public:
			typedef Iterator								iterator_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef ptrdiff_t								difference_type;
			typedef typename Iterator::iterator_category	iterator_category;

			reverse_Iterator() : _it(NULL) {}
			reverse_Iterator(iterator_type it) : _it(it) {}

			template <typename U>
			reverse_Iterator(const reverse_Iterator<U> &other) : _it(other.base()) {}
			
			reverse_Iterator	&operator=(const reverse_Iterator &rhs)
			{
				_it = rhs._it;
				return (*this);
			}

			iterator_type	base() const { return (_it); }

			reference	operator*() const { return (*(_it - 1)); }

			pointer		operator->() const { return (&operator*()); }

			reverse_Iterator	&operator++() { --_it; return (*this); }

			reverse_Iterator	operator++(int) { reverse_Iterator	tmp
				= *this; ++(*this); return (tmp); }

			reverse_Iterator	&operator--() { ++_it; return (*this); }

			reverse_Iterator	operator--(int) { reverse_Iterator	tmp
				= *this; ++(*this); return (tmp); }

			reverse_Iterator	operator+(difference_type n) const
				{ return (_it - n); }
			
			reverse_Iterator	operator-(difference_type n) const
				{ return (_it + n); }

			reverse_Iterator	&operator+=(difference_type n)
				{ _it -= n; return (*this); }

			reverse_Iterator	&operator-=(difference_type n)
				{ _it += n; return (*this); }

			value_type	&operator[](difference_type n) { return (*(_it
				- n - 1)); }

		private:
			iterator_type	_it;

	};

	template<typename T>
	bool	operator==(const ft::reverse_Iterator<T> lhs,
		const ft::reverse_Iterator<T> rhs) { return (lhs.base()
		== rhs.base()); }

	template<typename T1, typename T2>
	bool	operator==(const ft::reverse_Iterator<T1> lhs,
		const ft::reverse_Iterator<T2> rhs) { return (lhs.base()
		== rhs.base()); }

	template<typename T>
	bool	operator!=(const ft::reverse_Iterator<T> lhs,
		const ft::reverse_Iterator<T> rhs) { return (lhs.base()
		== rhs.base()); }

	template<typename T1, typename T2>
	bool	operator!=(const ft::reverse_Iterator<T1> lhs,
		const ft::reverse_Iterator<T2> rhs) { return (!(lhs.base()
		== rhs.base())); }

	template<typename T>
	bool	operator>(const ft::reverse_Iterator<T> lhs,
		const ft::reverse_Iterator<T> rhs) { return (lhs.base()
		< rhs.base()); }

	template<typename T1, typename T2>
	bool	operator>(const ft::reverse_Iterator<T1> lhs,
		const ft::reverse_Iterator<T2> rhs) { return (!(lhs.base()
		< rhs.base())); }

	template<typename T>
	bool	operator<(const ft::reverse_Iterator<T> lhs,
		const ft::reverse_Iterator<T> rhs) { return (lhs.base()
		> rhs.base()); }

	template<typename T1, typename T2>
	bool	operator<(const ft::reverse_Iterator<T1> lhs,
		const ft::reverse_Iterator<T2> rhs) { return (!(lhs.base()
		> rhs.base())); }

	template<typename T>
	bool	operator>=(const ft::reverse_Iterator<T> lhs,
		const ft::reverse_Iterator<T> rhs) { return (lhs.base()
		<= rhs.base()); }

	template<typename T1, typename T2>
	bool	operator>=(const ft::reverse_Iterator<T1> lhs,
		const ft::reverse_Iterator<T2> rhs) { return (!(lhs.base()
		<= rhs.base())); }

	template<typename T>
	bool	operator<=(const ft::reverse_Iterator<T> lhs,
		const ft::reverse_Iterator<T> rhs) { return (lhs.base()
		>= rhs.base()); }

	template<typename T1, typename T2>
	bool	operator<=(const ft::reverse_Iterator<T1> lhs,
		const ft::reverse_Iterator<T2> rhs) { return (!(lhs.base()
		>= rhs.base())); }

	template<typename T>
	typename ft::reverse_Iterator<T>::difference_type operator-(const ft::reverse_Iterator<T> lhs,
		const ft::reverse_Iterator<T> rhs)
		{ return (rhs.base() - lhs.base()); }
	
	template<typename T1, typename T2>
	typename ft::reverse_Iterator<T1>::difference_type operator-(const ft::reverse_Iterator<T1> lhs,
		const ft::reverse_Iterator<T2> rhs)
		{ return (rhs.base() - lhs.base()); }

	template<typename T>
	typename ft::reverse_Iterator<T>::difference_type operator+(const ft::reverse_Iterator<T> lhs,
		const ft::reverse_Iterator<T> rhs)
		{ return (rhs.base() + lhs.base()); }
	
	template<typename T1, typename T2>
	typename ft::reverse_Iterator<T1>::difference_type operator+(const ft::reverse_Iterator<T1> lhs,
		const ft::reverse_Iterator<T2> rhs)
		{ return (rhs.base() + lhs.base()); }

	template<typename T> ft::reverse_Iterator<T>	operator+(
		typename ft::reverse_Iterator<T>::difference_type x,
		typename ft::reverse_Iterator<T> &rhs
	) { return (rhs + x); }
}

#endif