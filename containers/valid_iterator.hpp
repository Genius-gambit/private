#ifndef VALID_ITERATOR_HPP
#define VALID_ITERATOR_HPP

# include "vector_iterator.hpp"
# include "enable_if.hpp"
# include <iterator>
# include <stdexcept>

namespace ft
{
	template <class InputIter>
	void	is_valid(InputIter first, InputIter last, typename ft::input_iterator_tag)
	{ (void) first; (void) last; }

	template <class InputIter>
	void	is_valid(InputIter first, InputIter last, typename std::input_iterator_tag)
	{ (void) first; (void) last; }

	template <class InputIter>
	void	is_valid(InputIter first , InputIter last, typename ft::random_access_iterator_tag)
	{
		if (first > last)
			throw (std::length_error("cannot create ft::vector larger than max_size()"));
	}

	template <class InputIter>
	void	is_valid(InputIter first , InputIter last, typename std::random_access_iterator_tag)
	{
		if (first > last)
			throw (std::length_error("cannot create ft::vector larger than max_size()"));
	}

	template <class InputIter>
	void	range_check(InputIter first, InputIter last)
	{
		is_valid(first, last, typename ft::iterator_traits<InputIter>::iterator_category());
	}
};

#endif