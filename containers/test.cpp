#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int>	trial;

	trial.assign(5, 10);
	// for (std::vector<int>::iterator it = trial.begin(); it != trial.end(); it++)
	// 	std::cout << *it << std::endl;
	trial.resize(4, 5);
	for (std::vector<int>::iterator it = trial.begin(); it != trial.end(); it++)
		std::cout << *it << std::endl;
	return (0);
}