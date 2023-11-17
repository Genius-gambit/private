#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <memory>
#include <cstddef>
#include "vector_iterator.hpp"
#include "enable_if.hpp"
#include "algorithm.hpp"
#include "valid_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

		//! -------------------------------------------- Defined Types -------------------------------------------- !//

			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::pointer  			pointer;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::const_pointer  	const_pointer;
			typedef std::size_t									size_type;
			typedef ft::iterator<T>								iterator;
			typedef const ft::iterator<T>						const_iterator;
			typedef ft::reverse_iterator<T>						reverse_iterator;
			typedef const ft::reverse_iterator<T>				const_reverse_iterator;

		//! -------------------------------------------- Constructors & Destructor -------------------------------------------- !//

			explicit vector(const allocator_type& alloc = allocator_type()) : _arr(NULL), _alloc(alloc), _capacity(0), _size(0) {};
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_capacity = this->_new_capacity(n);
				_arr = _alloc.allocate(_capacity);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_arr[i], val);
				_size = n;
			}

			vector (const vector& x)
			{
				this->_alloc = x.get_allocator();
				_capacity = this->_new_capacity(x.size());
				this->_arr = _alloc.allocate(_capacity);
				for (size_type i = 0; i < x.size(); i++)
					_alloc.construct(&_arr[i], x._arr[i]);
				this->_size = x.size();
			}

			template <class InputIterator>
			explicit vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				this->_alloc = alloc;
				this->_arr = NULL;
				this->_size = 0;
				this->_capacity = 0;
				iterator	position = first;
				insert(position, first, last);
			}

			vector& operator= (const vector& x)
			{
				if (*this != x)
				{
					this->_arr = x._arr;
					this->_capacity = x.capacity();
					this->_alloc = x.get_allocator();
					this->_size = x.size();
				}
				return (*this);
			}

			~vector()
			{
				clear();
				_alloc.deallocate(_arr, _capacity);
				_capacity = 0;
			}

		//! -------------------------------------------- Iterators Functions -------------------------------------------- !//

			iterator	begin() { return (iterator(_arr)); }
			const_iterator	begin() const { return (const_iterator(_arr)); }
			iterator	end() { return (iterator(_arr + _size)); }
			const_iterator	end() const { return (const_iterator(_arr + _size)); }
			reverse_iterator rbegin() { return (reverse_iterator(_arr + _size - 1)); }
			const_reverse_iterator	rbegin() const { return (const_reverse_iterator(_arr + _size - 1)); }
			reverse_iterator	rend() { return (reverse_iterator(_arr - 1)); }
			const_iterator	rend() const { return (const_reverse_iterator(_arr - 1)); }
		
		//! --------------------------------------------- Member Functions --------------------------------------------- !//

			size_type	max_size() const { return (_alloc.max_size()); }
			
			size_type	size() const { return (_size); }

			size_type	capacity() const { return (_capacity); }

			bool	empty() const { return (this->_size == 0); }

			allocator_type	get_allocator() const { return (_alloc); }
			
			void	reserve(size_type n)
			{
				if (n <= _capacity)
					return ;
				if (n > max_size())
					throw std::length_error("Allocation size is greater than the max size");
				T*	new_vec = _alloc.allocate(_new_capacity(n));
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&new_vec[i], _arr[i]);
					_alloc.destroy(&_arr[i]);
				}
				_alloc.deallocate(_arr, _capacity);
				_arr = new_vec;
				_capacity = _new_capacity(n);
			}

			void resize (size_type n, value_type val = value_type())
			{
				if (n >= max_size())
					throw std::length_error("Allocation size is greater than the max size");
				T	*_new;
				size_type	i = 0;

				_new = _alloc.allocate(_new_capacity(n));
				for (i = 0; i < n && i < size(); i++)
					_alloc.construct(&_new[i], _arr[i]);
				if (n == size())
					_alloc.construct(&_new[size() - 1], _arr[size() - 1]);
				else if (n > size())
					for (; i < n; i++)
						_alloc.construct(&_new[i], val);
				clear();
				_alloc.deallocate(_arr, _capacity);
				_size = n;
				_capacity = _new_capacity(n);
				_arr = _new;
			}

			void shrink_to_fit()
			{
				T	*_new;
				size_type	tmp = size();

				_new = _alloc.allocate(size());
				for (size_type i = 0; i < size(); i++)
					_alloc.construct(&_new[i], _arr[i]);
				clear();
				_alloc.deallocate(_arr, _capacity);
				_size = tmp;
				_capacity = _size;
				_arr = _new;
			}

		//! -------------------------------------------- Element Access -------------------------------------------- !//

			reference	operator[](size_type n) { return (_arr[n]); }

			const_reference	operator[](size_type n) const { return (_arr[n]); }

			reference	at(size_type n)
			{
				if (n < _size)
					return (_arr[n]);
				throw(std::out_of_range("Element out of range"));
			}

			const_reference	at(size_type n) const
			{
				if (n < _size)
					return (_arr[n]);
				throw(std::out_of_range("Element out of range"));
			}

			reference	front() { return (_arr[0]); }

			const_reference	front() const { return (_arr[0]); }

			reference	back() { return (_arr[_size - 1]); }

			const_reference	back() const { return (_arr[_size - 1]); }

		//! -------------------------------------------- Modifiers -------------------------------------------- !//

			void	push_back(const value_type&	val)
			{
				if (_size == _capacity && _capacity + 1 > max_size())
					throw std::length_error("Allocation size is greater than the max size");
				if (_size == _capacity)
					reserve(_new_capacity(_size + 1));
				_alloc.construct(_arr + _size, val);
				_size++;
			}

			void	clear()
			{
				for (size_type	i = 0; i < _size; i++)
					_alloc.destroy(&_arr[i]);
				_size = 0;
			}

			void	pop_back() { _alloc.destroy(_arr + _size); _size--;}

			iterator	insert(iterator position, const value_type& val)
			{
				T*	new_alloc;
				size_type	new_size = 0;
				size_type	new_cap = _new_capacity(_size + 1);
				iterator	res;
				new_alloc = _alloc.allocate((_size + 1) * 2);
				if (position >= end())
				{
					for (iterator it = begin(); it != end(); it++)
						_alloc.construct(&new_alloc[new_size++], *it);
					_alloc.construct(&new_alloc[new_size++], val);
					res = end();
				}
				else if (position > begin())
				{
					for (iterator it = begin(); it != position; it++)
						_alloc.construct(&new_alloc[new_size++], *it);
					_alloc.construct(&new_alloc[new_size++], val);
					for (iterator it = position; it != end(); it++)
						_alloc.construct(&new_alloc[new_size++], *it);
				}
				else if (position <= begin())
				{
					_alloc.construct(&new_alloc[new_size++], val);
					for (iterator it = begin(); it != end(); it++)
						_alloc.construct(&new_alloc[new_size++], *it);
				}
				for (size_type	i = 0; i < _size; i++)
					_alloc.destroy(&_arr[i]);
				_alloc.deallocate(_arr, _capacity);
				_arr = new_alloc;
				_capacity = new_cap;
				_size = new_size;
				res = begin();
				while (*res != val)
					res++;
				return(++res);
			}

			void	insert(iterator position, size_type n, const value_type& val)
			{
				if (n == 0)
					return ;
				if (n == max_size() || n + _size == max_size())
					throw std::length_error("Allocation size is greater than the max size");
				T*	new_alloc;
				size_type	new_size = 0;
				size_type	new_cap = _new_capacity(_size + n);
				new_alloc = _alloc.allocate(new_cap);
				if (position >= end())
				{
					for (iterator it = begin(); it != end(); it++)
						_alloc.construct(&new_alloc[new_size++], *it);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&new_alloc[new_size++], val);
				}
				else if (position > begin())
				{
					for (iterator it = begin(); it != position; it++)
						_alloc.construct(&new_alloc[new_size++], *it);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&new_alloc[new_size++], val);
					for (iterator it = position; it != end(); it++)
						_alloc.construct(&new_alloc[new_size++], *it);
				}
				else if (position <= begin())
				{
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&new_alloc[new_size++], val);
					for (iterator it = begin(); it != end(); it++)
						_alloc.construct(&new_alloc[new_size++], *it);
				}
				clear();
				_alloc.deallocate(_arr, _capacity);
				_arr = new_alloc;
				_capacity = new_cap;
				_size = new_size;
			}

			void assign (size_type n, const value_type& val)
			{
				this->clear();
				_alloc.deallocate(_arr, this->_capacity);
				_arr = _alloc.allocate(_new_capacity(n));
				this->_capacity = _new_capacity(n);
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
				this->_size = n;
			}

			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last)
			{
				for (; first != last; first++)
					position = insert(position, *first) + 1;
			}

			template <class InputIterator>
			void		assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				clear();
				_alloc.deallocate(_arr, this->_capacity);
				_size = 0;
				_capacity = 0;
				iterator	pos = first;
				size_type	n = 0;
				for (n = 0, pos = first; pos != last; pos++, n++);
				_capacity = _new_capacity(n);
				_arr = _alloc.allocate(_capacity);
				for (pos = first; pos != last; pos++)
					push_back(*pos);
			}

			iterator erase (iterator position)
			{
				if (position <= begin())
				{
					_alloc.destroy(&_arr[0]);
					T	*new_alloc = _alloc.allocate(_new_capacity(_size - 1));
					for (size_type i = 1, j = 0; i < _size; i++, j++)
					{
						_alloc.construct(&new_alloc[j], _arr[i]);
						_alloc.destroy(&_arr[i]);
					}
					for (size_type j = 0; j < _size - 1; j++)
					{
						_alloc.construct(&_arr[j], new_alloc[j]);
						_alloc.destroy(&new_alloc[j]);
					}
					_size--;
					return (begin());
				}
				else if (position < end())
				{
					size_type i = 0;
					T	*new_alloc;
					for (i = 0; i < _size && _arr[i] != *position; i++);
					new_alloc = _alloc.allocate(_new_capacity(_size - i));
					for (size_type j = 0, k = i; k < _size; k++, j++)
						_alloc.construct(&new_alloc[j], _arr[k]);
					for (size_type j = 1, k = i; k < _size; k++, j++)
					{
						_alloc.destroy(&_arr[k]);
						_alloc.construct(&_arr[k], new_alloc[j]);
					}
					iterator it = begin();
					for (it = begin(); *it != new_alloc[1] && it != end(); it++);
					for(size_type j = 0; j < _size - i; j++)
						_alloc.destroy(&new_alloc[j]);
					_alloc.deallocate(new_alloc, _new_capacity(_size - 1));
					_size--;
					return (it);
				}
				return (position);
			}

			iterator erase (iterator first, iterator last)
			{
				while (first < last)
				{
					last = erase(last);
					last--;
				}
				last = erase(last);
				return (last);
			}

			void	print()
			{
				for (size_type i = 0; i < _size; i++)
					std::cout << _arr[i] << " ";
				std::cout << std::endl;
			}

			void	swap(vector &other)
			{
				value_type		*arr = other._arr;
				allocator_type	alloc = other.get_allocator();
				size_type		capacity = other._capacity;
				size_type		size = other._size;

				other._arr = _arr;
				other._alloc = get_allocator();
				other._capacity = _capacity;
				other._size = _size;
				_arr = arr;
				_alloc = alloc;
				_capacity = capacity;
				_size = size;
			}

		private:

	//! -------------------------------------------- Private Variables -------------------------------------------- !//

			value_type		*_arr;
			allocator_type	_alloc;
			size_type		_capacity;
			size_type		_size;
			size_type		_new_capacity(size_type	size)
			{
				size_type	n;

				n = 1;
				for (n = 1; n < size; n *= 2);
				return (n);
			}
			void	_swap(T t1, T t2)
			{
				T	tmp = t2;
				t1 = t2;
				t2 = tmp;
			}

	};
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

	//! -------------------------------------------- Relational Operators -------------------------------------------- !//

	template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class T, class Alloc>  bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }
	template <class T, class Alloc>  bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())	); }
	template <class T, class Alloc>  bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }
	template <class T, class Alloc>  bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs)); }
	template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }
};

#endif