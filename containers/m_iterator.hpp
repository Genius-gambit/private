#ifndef M_ITERATOR_HPP
#define M_ITERATOR_HPP

#include "utils/iterator_traits.hpp"

namespace ft
{
	template <class T, class Compare >
	class revMapIterator;

	template <class T, class Compare >
	class constrevMapIterator;

	template <class T, class Compare >
	class constMapIterator;

	template <class T, class Compare >
	class node_iter
	{
		public:
			typedef Compare											key_compare;
			typedef ft::iterator<ft::bidirectional_iterator_tag, T>	trait_type;
			typedef typename trait_type::value_type
	};
}

#endif