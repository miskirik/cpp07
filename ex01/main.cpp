#include "Iter.hpp"

template<typename T>
void print(T &i)
{
	std::cout << i << std::endl;
}

template<typename T>
void add(T &i)
{
	i++;
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	iter(tab, 5, print <int>);
	iter(tab, 5, add <int>);
	iter(tab, 5, print<int>);
	return 0;
}
