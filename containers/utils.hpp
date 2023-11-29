#ifndef UTILS_HPP
#define UTILS_HPP

#include "pair.hpp"

namespace ft
{
	template <typename T>
	struct	Node
	{
		T	data;
		Node* prev;
		Node* next;
	};
	template <class Key, class T>
	struct BNode
	{
		ft::pair<Key, T>	pair;
		BNode* leftNode;
		BNode* rightNode;
		BNode* parentNode;
		bool	end;
		bool	_root;
		bool	_red;
	};
};

#endif