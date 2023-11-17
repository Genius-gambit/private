#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <memory>
#include <cstddef>

struct	BNode
{
	BNode	*right;
	BNode	*left;
	BNode	*parent;
	int		num;
};

BNode	*findLeftUncle(BNode	*tmp)
{
	if (tmp != NULL && tmp->parent != NULL
		&& tmp->parent->parent != NULL
		&& tmp->parent->parent->left == NULL)
		return (NULL);
	return (tmp);
}

BNode	*findRightUncle(BNode	*tmp)
{
	if (tmp != NULL && tmp->parent != NULL
		&& tmp->parent->parent != NULL
		&& tmp->parent->parent->right == NULL)
		return (NULL);
	return (tmp);
}

void	insertion(BNode	*nodes, int num, int *size)
{
	BNode	*tmp = nodes;
	bool	pushed = false;

	while (!pushed)
	{
		if (num > tmp->num)
		{
			if (tmp->right == NULL)
			{
				tmp->right = new BNode;
				tmp->right->num = num;
				tmp->right->parent = tmp;
				tmp = tmp->right;
				pushed = true;
				(*size)++;
				break;
			}
			tmp = tmp->right;
		}
		else if (num < tmp->num)
		{
			if (tmp->left == NULL)
			{
				tmp->left = new BNode;
				tmp->left->num = num;
				tmp->left->parent = tmp;
				pushed = true;
				(*size)++;
				break;
			}
			tmp = tmp->left;
		}
	}
	if (*size <= 2)
		return ;
	if (findLeftUncle(tmp) == NULL)
	{
		if (tmp->num > tmp->parent->num
			&& tmp->parent->num > tmp->parent->parent->num)
		{
			BNode	*link = tmp->parent->parent->parent;
			tmp->parent->left = tmp->parent->parent;
			if (tmp->parent->parent)
				delete [] tmp->parent->parent;
			if (tmp != NULL && tmp->parent != NULL
				&& tmp->parent->parent != NULL
				&& tmp->parent->parent->parent != NULL)
				tmp->parent->parent = link;
			
		}
	}
	else if (findRightUncle(tmp) == NULL)
	{

	}
}

int main()
{
	BNode	*node = new BNode;
	int		size = 1;

	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->num = 12;

	insertion(node, 14, &size);
	insertion(node, 15, &size);
	std::cout << "Size: " << size /*<< ", Left: " <<  node.left->num
		*/<< ", Parent: " <<  node->num << ", Right: "
		<<  node->right->num << std::endl;
}