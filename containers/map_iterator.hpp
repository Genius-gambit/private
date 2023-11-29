#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <utility>
#include "utils.hpp"

namespace ft
{
	template <class K, class V>
	class MapIterator
	{
	public:
		typedef ft::pair<K, V> value_type;
		typedef ft::pair<K, V> &reference;
		typedef BNode<K, V> *pointer;

	protected:
		pointer _ptr;

	private:
		pointer _successor(pointer ptr)
		{
			pointer next;
			if (!ptr->rightNode)
			{
				next = ptr;
				while (next->parentNode && next == next->parentNode->rightNode)
					next = next->parentNode;
				next = next->parentNode;
			}
			else
			{
				next = ptr->rightNode;
				while (next->leftNode)
					next = next->leftNode;
			}
			return (next);
		};
		pointer _predecessor(pointer ptr)
		{
			pointer next;
			if (!ptr->leftNode)
			{
				next = ptr;
				while (next->parentNode && next == next->parentNode->leftNode)
					next = next->parentNode;
				next = next->parentNode;
			}
			else
			{
				next = ptr->leftNode;
				while (next->rightNode)
					next = next->rightNode;
			}
			return (next);
		};

	public:
		MapIterator(void) : _ptr(0){};
		MapIterator(const pointer ptr) : _ptr(ptr){};
		MapIterator(const MapIterator &src) { *this = src; };
		MapIterator &operator=(const MapIterator &other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		pointer node(void) { return (_ptr); };
		value_type &operator*(void) { return (_ptr->pair); };
		value_type *operator->(void) { return (&_ptr->pair); };
		bool operator==(const MapIterator<K, V> &other) { return (this->_ptr == other._ptr); };
		bool operator!=(const MapIterator<K, V> &other) { return (!(*this == other)); };
		bool operator>(const MapIterator<K, V> &other) { return (this->_ptr > other._ptr); };
		bool operator<(const MapIterator<K, V> &other) { return (this->_ptr < other._ptr); };
		bool operator>=(const MapIterator<K, V> &other) { return (this->_ptr >= other._ptr); };
		bool operator<=(const MapIterator<K, V> &other) { return (this->_ptr <= other._ptr); };
		MapIterator &operator++(void)
		{
			_ptr = _successor(_ptr);
			return (*this);
		};
		MapIterator &operator--(void)
		{
			_ptr = _predecessor(_ptr);
			return (*this);
		};
		MapIterator operator++(int)
		{
			MapIterator _ret = *this;
			this->operator++();
			return (_ret);
		};
		MapIterator operator--(int)
		{
			MapIterator _ret = *this;
			this->operator--();
			return (_ret);
		};
	};
	template <class K, class V>
	class ConstMapIterator
	{
	public:
		typedef ft::pair<K, V> value_type;
		typedef ft::pair<K, V> &reference;
		typedef BNode<K, V> *pointer;

	protected:
		pointer _ptr;

	private:
		pointer _successor(pointer ptr)
		{
			pointer next;

			if (!ptr->rightNode)
			{
				next = ptr;
				while (next->parentNode && next == next->parentNode->rightNode)
					next = next->parentNode;
				next = next->parentNode;
			}
			else
			{
				next = ptr->rightNode;
				while (next->leftNode)
					next = next->leftNode;
			}
			return (next);
		};
		pointer _predecessor(pointer ptr)
		{
			pointer next;

			if (!ptr->leftNode)
			{
				next = ptr;
				while (next->parentNode && next == next->parentNode->leftNode)
					next = next->parentNode;
				next = next->parentNode;
			}
			else
			{
				next = ptr->leftNode;
				while (next->rightNode)
					next = next->rightNode;
			}
			return (next);
		};

	public:
		ConstMapIterator() : _ptr(0){};
		ConstMapIterator(const pointer ptr) : _ptr(ptr){};
		ConstMapIterator(const ConstMapIterator &other) { *this = other; };
		ConstMapIterator &operator=(const ConstMapIterator &other)
		{
			this->_ptr = other._ptr;
			return (*this);
		};
		pointer Node(void) { return (_ptr); };
		value_type &operator*(void) { return (_ptr->pair); };
		value_type *operator->(void) { return (&_ptr->pair); };
		bool operator==(const MapIterator<K, V> &other) { return (_ptr == other._ptr); };
		bool operator!=(const MapIterator<K, V> &other) { return (!(_ptr == other._ptr)); };
		bool operator>(const MapIterator<K, V> &other) { return (_ptr > other._ptr); };
		bool operator>=(const MapIterator<K, V> &other) { return (_ptr >= other._ptr); };
		bool operator<(const MapIterator<K, V> &other) { return (_ptr < other._ptr); };
		bool operator<=(const MapIterator<K, V> &other) { return (_ptr <= other._ptr); };
		ConstMapIterator &operator++(void)
		{
			_ptr = _successor(_ptr);
			return (*this);
		};
		ConstMapIterator &operator--(void)
		{
			_ptr = _predecessor(_ptr);
			return (*this);
		};
		ConstMapIterator &operator++(int)
		{
			ConstMapIterator tmp;
			tmp = *this;
			this->operator++();
			return (*tmp);
		};
		ConstMapIterator &operator--(int)
		{
			ConstMapIterator tmp;
			tmp = *this;
			this->operator--();
			return (*tmp);
		};
	};
	template<class K, class V>
	class ReverseMapIterator
	{
		public:
			typedef ft::pair<K, V>	value_type;
			typedef ft::pair<K, V>	&reference;
			typedef BNode<K, V>	*pointer;

		protected:
			pointer	_ptr;

		private:
			pointer	__successor(pointer ptr)
			{
				pointer	next;

				if (!ptr->rightNode)
				{
					next = ptr;
					while (next->parentNode && next == next->parentNode->rightNode)
						next = next->parentNode;
					next = next->parentNode;
				}
				else
				{
					next = ptr->rightNode;
					while (next->leftNode)
						next = next->leftNode;
				}
				return (next);
			};
			pointer	_predecessor(pointer ptr)
			{
				pointer	next;

				if (!ptr->leftNode)
				{
					next = ptr;
					while (next->parentNode && next == next->parentNode->leftNode)
						next = next->parentNode;
					next = next->parentNode;
				}
				else
				{
					next = ptr->leftNode;
					while (next->rightNode)
						next = next->rightNode;
				}
				return (next);
			};
		public:
			ReverseMapIterator() : _ptr(0) {};
			ReverseMapIterator(const pointer ptr) : _ptr(ptr) {};
			ReverseMapIterator(const ReverseMapIterator &other)
			{
				*this = other;
			};
			ReverseMapIterator	&operator=(const ReverseMapIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			pointer	node() { return (_ptr); };
			value_type	&operator*() { return (_ptr->pair); };
			value_type	*operator->() { return (&_ptr->pair); };
			bool	operator==(const ReverseMapIterator<K, V> &other) { return (_ptr == other._ptr); };
			bool	operator!=(const ReverseMapIterator<K, V> &other) { return (!(_ptr == other._ptr)); };
			bool	operator>(const ReverseMapIterator<K, V> &other) { return (_ptr > other._ptr); };
			bool	operator>=(const ReverseMapIterator<K, V> &other) { return (_ptr >= other._ptr); };
			bool	operator<(const ReverseMapIterator<K, V> &other) { return (_ptr < other._ptr); };
			bool	operator<=(const ReverseMapIterator<K, V> &other) { return (_ptr <= other._ptr); };
			ReverseMapIterator	&operator++()
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};
			ReverseMapIterator	&operator--()
			{
				_ptr = __successor(_ptr);
				return (*this);
			};
			ReverseMapIterator	&operator++(int)
			{
				ReverseMapIterator	tmp(*this);
				this->operator++();
				return (tmp);
			};
			ReverseMapIterator	&operator--(int)
			{
				ReverseMapIterator	tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
	template<class K, class V>
	class ConstReverseMapIterator
	{
		public:
				typedef ft::pair<K, V>	value_type;
				typedef ft::pair<K, V>	&reference;
				typedef BNode<K, V>	*pointer;
		protected:
				pointer	_ptr;
		private:
			pointer	_successor(pointer ptr)
			{
				pointer	next;
				if (!ptr->rightNode)
				{
					next = ptr;
					while (next->parentNode && next == next->parentNode->rightNode)
						next = next->parentNode;
					next = next->parentNode;
				}
				else
				{
					next = ptr->rightNode;
					while (next->leftNode)
						next = next->leftNode;
				}
				return (next);
			};
			pointer	_predecessor(pointer ptr)
			{
				pointer	next;
				if (!ptr->leftNode)
				{
					next = ptr;
					while (next->parentNode && next == next->parentNode->leftNode)
						next = next->parentNode;
					next = next->parentNode;
				}
				else
				{
					next = ptr->leftNode;
					while (next->rightNode)
						next = next->parentNode;
				}
				return (next);
			};
		public:
			ConstReverseMapIterator() : _ptr(0) {};
			ConstReverseMapIterator(const pointer ptr) : _ptr(ptr) {};
			ConstReverseMapIterator(const ConstReverseMapIterator &other) { *this = other; };
			ConstReverseMapIterator	&operator=(const ConstReverseMapIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			pointer	Node(void) { return (_ptr); };
			value_type	&operator*(void) { return (_ptr->pair); };
			value_type	*operator->(void) { return (&_ptr->pair); };
			bool	operator==(const ReverseMapIterator<K, V> &other) { return (_ptr == other._ptr); };
			bool	operator!=(const ReverseMapIterator<K, V> &other) { return (!(_ptr == other._ptr)); };
			bool	operator>(const ReverseMapIterator<K, V> &other) { return (_ptr > other._ptr); };
			bool	operator>=(const ReverseMapIterator<K, V> &other) { return (_ptr >= other._ptr); };
			bool	operator<(const ReverseMapIterator<K, V> &other) { return (_ptr < other._ptr); };
			bool	operator<=(const ReverseMapIterator<K, V> &other) { return (_ptr <= other._ptr); };
			ConstReverseMapIterator	&operator++(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};
			ConstReverseMapIterator	&operator--(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};
			ConstReverseMapIterator	&operator++(int)
			{
				ConstReverseMapIterator	tmp(*this);
				this->operator++();
				return (tmp);
			};
			ConstReverseMapIterator	&operator--(int)
			{
				ConstReverseMapIterator	tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
}

#endif