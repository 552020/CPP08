#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define SIZE 5

template <typename Container>
void initializeContainer(Container &container, int size)
{
	for (int i = 1; i <= size; ++i)
	{
		container.push_back(i);
	}
}

int main()
{
	// Example usage with std::vector
	// This works from C++11 onwards
	// std::vector<int> vec = {1, 2, 3, 4, 5};
	std::vector<int> vec;
	initializeContainer(vec, SIZE);
	int validValue = SIZE - 1;
	std::cout << "Vector: Searching for " << validValue << ": " << (easyFind(vec, validValue) ? "Found" : "Not Found")
			  << std::endl;
	int invalidValue = SIZE + 1;
	std::cout << "Vector: Searching for " << invalidValue << ": "
			  << (easyFind(vec, invalidValue) ? "Found" : "Not Found") << std::endl;

	// Example usage with std::list
	// This works from C++11 onwards
	// std::list<int> lst = {1, 2, 3, 4, 5};
	std::list<int> lst;
	initializeContainer(lst, SIZE);
	std::cout << "List: Searching for " << validValue << ": " << (easyFind(lst, validValue) ? "Found" : "Not Found")
			  << std::endl;
	std::cout << "List: Searching for " << invalidValue << ": " << (easyFind(lst, invalidValue) ? "Found" : "Not Found")
			  << std::endl;

	try
	{
		easyFindThrow(vec, 3);
		std::cout << "Value found." << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyFindThrow(vec, 6);
		std::cout << "Value found." << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Testing with std::deque
	std::deque<int> deq;
	initializeContainer(deq, SIZE);
	std::cout << "Deque: Searching for " << validValue << ": " << (easyFind(deq, validValue) ? "Found" : "Not Found")
			  << std::endl;
	std::cout << "Deque: Searching for " << invalidValue << ": "
			  << (easyFind(deq, invalidValue) ? "Found" : "Not Found") << std::endl;

	try
	{
		easyFindThrow(deq, 3);
		std::cout << "Value found in deque." << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyFindThrow(deq, 6);
		std::cout << "Value found in deque." << std::endl; // This won't execute; just for consistency
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
