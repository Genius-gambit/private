#include <vector>
#include <iterator>
#include <iostream>

int main()
{
	std::vector<int>	test;

	test.insert(test.begin(), -1, 42);
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << *it << " ";
}