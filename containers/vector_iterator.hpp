#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

# include <iterator>
# include <vector>
# include <cstddef>
# include "utils/iterator_traits.hpp"

namespace ft
{
	template<class T>
	class vectorIterator
	{
	//! ----------------------- Iterator Defined Types -------------------------- !//
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type	value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::const_pointer		const_pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

	//! ----------------------- Iterator Constructors -------------------------- !//
			iterator() : _it() {}
			iterator(pointer it) : _it(it) {}
			iterator(const iterator &it) : _it(it._it) {}
			~iterator() {}
			iterator	operator=(const iterator &r)
			{
				_it = r.base();
				return (*this);
			};
			pointer	base() const { return (_it); }
			reference	operator*() { return (*_it); }
			iterator	operator+(difference_type n) const { return iterator(_it + n); }

	//! ----------------------- Iterator Modifiers -------------------------- !//

			iterator	operator++() { return (_it++); }
			iterator	operator++(int)
			{
				iterator	old;
				old = *this;
				++(_it);
				return (old);
			}
			iterator	operator+=(difference_type n) const
			{
				_it += n;
				return iterator(_it);
			}
			iterator	operator-(difference_type n) const { return iterator(_it - n); }
			iterator	operator--() { return (_it--); }
			iterator	operator--(int)
			{
				iterator	old;
				old = *this;
				--(_it);
				return (old);
			}
			iterator	operator-=(difference_type n) const
			{
				_it -= n;
				return iterator(_it);
			}
			pointer		operator->() const { return (_it); }
			reference	operator*() const { return (*_it); }
		private:
			pointer	_it;
		//! ----------------------- Iterators Relational Operators -------------------------- !//	
		template	<class Iter1, class Iter2>
		bool	operator !=(const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() != second.base()); }

		template	<class Iter1, class Iter2>
		bool	operator >(const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() > second.base()); }

		template	<class Iter1, class Iter2>
		bool	operator ==(const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() == second.base()); }

		template	<class Iter1, class Iter2>
		bool	operator >=(const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() >= second.base()); }

		template	<class Iter1, class Iter2>
		bool	operator <=(const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() <= second.base()); }

		template	<class Iter1, class Iter2>
		bool	operator <(const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() < second.base()); }
	};

	template < class U >
	class reverse_iterator
	{
		public:

		//! ----------------------- Reverse Iterator Defined Types -------------------------- !//
			
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type	value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::const_pointer		const_pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			
		//! ----------------------- Reverse Iterator Constructors -------------------------- !//

			reverse_iterator() : _it() {}
			reverse_iterator(pointer it) : _it(it) {}
			~reverse_iterator() {}
			reverse_iterator	operator=(const reverse_iterator &r)
			{
				_it = r.base();
				return (*this);
			};
			pointer	base() const { return (_it); }
			reverse_iterator	operator+(difference_type n) const { return reverse_iterator(_it - n); }

		//! ----------------------- Reverse Iterator Modifiers -------------------------- !//

			reverse_iterator	operator++() { return (_it--); }
			reverse_iterator	operator++(int)
			{
				reverse_iterator	old;
				old = *this;
				--(_it);
				return (old);
			}
			reverse_iterator	operator+=(difference_type n) const
			{
				_it -= n;
				return reverse_iterator(_it);
			}

			reverse_iterator	operator-(difference_type n) const { return reverse_iterator(_it + n); }
			reverse_iterator	operator--() { return (_it++); }
			reverse_iterator	operator--(int)
			{
				reverse_iterator	old;
				old = *this;
				++(_it);
				return (old);
			}
			reverse_iterator	operator-=(difference_type n) const
			{
				_it += n;
				return reverse_iterator(_it);
			}
			pointer		operator->() const { return (_it); }
			reference	operator*() const { return (*_it); }
		private:
			pointer	_it;
	};

	//! ----------------------- Reverse Iterators Relational Operators -------------------------- !//

	template	<class Iter1, class Iter2>
	bool	operator !=(const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() != second.base()); }

	template	<class Iter1, class Iter2>
	bool	operator >(const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() > second.base()); }

	template	<class Iter1, class Iter2>
	bool	operator ==(const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() == second.base()); }

	template	<class Iter1, class Iter2>
	bool	operator >=(const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() >= second.base()); }

	template	<class Iter1, class Iter2>
	bool	operator <=(const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() <= second.base()); }

	template	<class Iter1, class Iter2>
	bool	operator <(const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() < second.base()); }
}

#endif