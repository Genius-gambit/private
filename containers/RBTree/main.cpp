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

void	isnertNodes(BNode	*tmp, int num, int *size)
{
	bool	pushed = false;
	while (!pushed)
	{
		if (num >= tmp->num)
		{
			if (tmp->right == NULL)
			{
				tmp->right = new BNode;
				tmp->right->num = num;
				tmp->right->parent = tmp;
				tmp = tmp->right;
				tmp->left = NULL;
				tmp->right = NULL;
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
				tmp = tmp->left;
				tmp->left = NULL;
				tmp->right = NULL;
				pushed = true;
				(*size)++;
				break;
			}
			tmp = tmp->left;
		}
	}
}

void	insertion(BNode	**nodes, int num, int *size)
{
	BNode	*tmp = *nodes;
	bool	pushed = false;

	while (!pushed)
	{
		if (num >= tmp->num)
		{
			if (tmp->right == NULL)
			{
				tmp->right = new BNode;
				tmp->right->num = num;
				tmp->right->parent = tmp;
				tmp = tmp->right;
				tmp->left = NULL;
				tmp->right = NULL;
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
				tmp = tmp->left;
				tmp->left = NULL;
				tmp->right = NULL;
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
		tmp = tmp->parent;
		tmp->left = new BNode;
		tmp->left->num = tmp->parent->num;
		(*nodes) = (*nodes)->right;
		delete tmp->parent;
		tmp->parent = NULL;
		tmp->left->right = NULL;
		tmp->left->left = NULL;
		tmp->left->parent = tmp;
		if (tmp->num > tmp->parent->num
			&& tmp->parent->num > tmp->parent->parent->num)
		{
			BNode	*link = tmp->parent->parent->parent;
			tmp->parent->left = tmp->parent->parent;
			if (tmp->parent->parent)
				delete tmp->parent->left->right;
			if (tmp != NULL && tmp->parent != NULL
				&& tmp->parent->parent != NULL
				&& tmp->parent->parent->parent != NULL)
				tmp->parent->parent = link;
			
		}
	}
	else if (findRightUncle(tmp) == NULL)
	{

	}
	// nodes = tmp;
}

void	freeNodes(BNode	**nodes)
{
	bool	end = false;

	while (!end)
	{
		if ((*nodes)->right != NULL)
			(*nodes) = (*nodes)->right;
		if ((*nodes)->left != NULL)
			(*nodes) = (*nodes)->left;
		int	id = 0;
		if ((*nodes)->parent != NULL && (*nodes)->num
			>= (*nodes)->parent->num)
			id = 1;
		else if ((*nodes)->parent != NULL && (*nodes)->num
			< (*nodes)->parent->num)
			id = 2;
		BNode	*tmp = (*nodes);
		if (tmp->right != NULL || tmp->left != NULL)
			continue;
		(*nodes) = (*nodes)->parent;
		delete tmp;
		tmp = NULL;
		if (id == 1)
			(*nodes)->right = NULL;
		else if (id == 2)
			(*nodes)->left = NULL;
		if ((*nodes)->parent == NULL
		&& (*nodes)->right == NULL
		&& (*nodes)->left == NULL)
			end = !end;
	}
	delete *nodes;
}

int main()
{
	BNode	*node = new BNode;
	int		size = 1;

	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->num = 12;

	insertion(&node, 14, &size);
	insertion(&node, 15, &size);
	insertion(&node, 15, &size);
	insertion(&node, 11, &size);
	insertion(&node, 10, &size);
	// insertion(&node, 11, &size);
	freeNodes(&node);
	std::cout << "Size: " << size;
	return (0);
}