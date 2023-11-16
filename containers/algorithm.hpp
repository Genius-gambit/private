#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{
	template <class InputIter1, class InputIter2>
	bool	equal(InputIter1 first1, InputIter1 last1, InputIter2 first2)
	{
		for (;first1 != last1; first1++, first2++)
			if (*first1 != *first2)
				return (false);
		return (true);
	}

	template <class InputIter1, class InputIter2, class BP>
	bool	equal(InputIter1 first1, InputIter1 last1, InputIter2 first2, BP pred)
	{
		for (;first1 != last1; first1++, first2++)
			if (!pred(*first1, *first2))
				return (false);
		return (true);
	}

	template <class InputIter1, class InputIter2>
	bool	lexicographical_compare(InputIter1 fst1, InputIter1 lst1,
			InputIter2 fst2, InputIter2 lst2)
	{
		for (; fst1 != lst1; ++fst1, ++fst2)
		{
			if (fst2 == lst2 || *fst2 < *fst1)
				return (false);
			else if (*fst1 < *fst2)
				return (true);
		}
		return (fst2 != lst2);
	}
	
	template <class InputIter1, class InputIter2, class Compare>
	bool	lexicographical_compare(InputIter1 fst1, InputIter1 lst1,
			InputIter2 fst2, InputIter2 lst2, Compare comp)
	{
		for (; fst1 != lst1; ++fst1, ++fst2)
		{
			if (fst2 == lst2 || comp(*fst2, *fst1))
				return (false);
			else if (*fst1 < *fst2)
				return (true);
		}
		return (fst2 != lst2);
	}
};

#endif