#include "vector.hpp"

int main()
{
	{
		// ft::vector<int, std::allocator<int> >	vec;
		// ft::vector<int, std::allocator<int> >	vec1;

		// vec.push_back(20);
		// vec.push_back(15);
		// vec.push_back(105);
		// vec.push_back(100);

		// vec1.push_back(22);
		// vec1.push_back(17);
		// vec1.push_back(109);
		// vec1.push_back(104);
		// vec1.push_back(120);
		// vec1.push_back(150);
		// vec1.push_back(300);
		// vec.pop_back();
		// // ft::vector<int>::iterator	it = vec.end();
		// vec.insert(vec.end(), vec1.begin() + 2, vec1.end());
		// vec.erase(vec.begin() + 1, vec.begin() + 2);
		// vec1.print();
		// vec.swap(vec1);
		// vec1.print();
		// std::allocator<int>	alloc;
		// ft::vector<int, std::allocator<int> >	vec2(5, 23, alloc);
		// vec2.print();
	}
	{
		ft::vector<int, std::allocator<int> >	vec;
		ft::vector<int, std::allocator<int> >	vec1;

		vec.resize(5, 10);
		vec.print();
		vec.resize(4, 10);
		vec.print();
		vec.resize(8, 8);
		vec.print();
		vec1.push_back(21);
		vec1.print();
		std::cout << (vec != vec1) << std::endl;
	}
	{
		// ft::vector<int, std::allocator<int> >	vec;
		// ft::vector<int, std::allocator<int> >	vec1;

		// vec.push_back(20);
		// vec.push_back(15);
		// vec.push_back(105);
		// vec.push_back(100);

		// vec1.push_back(22);
		// vec1.push_back(17);
		// vec1.push_back(109);
		// vec1.push_back(104);
		// vec1.push_back(120);
		// vec1.push_back(150);
		// vec1.push_back(300);
		// vec.pop_back();
		// vec.assign(vec1.begin(), vec1.begin() + 2);
		// ft::vector<int, std::allocator<int> >	vec2(vec.begin(), vec.end(), vec.get_allocator());
		// vec2.print();
		// vec.assign(5, 10);
		// vec.print();
		// ft::vector<int, std::allocator<int> >	vec3 = vec2;
		// vec3.print();
		// ft::vector<int>::reverse_iterator	r1 = vec3.rbegin();
		// std::cout << *r1 << std::endl;
	}
	return (0);
}