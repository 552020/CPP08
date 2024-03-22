#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define SIZE 5

template <typename C>
void initializeContainer(C &container, int size)
{
	for (int i = 1; i <= size; ++i)
	{
		container.push_back(i);
	}
}

int main()
{
	std::cout << "Test 1 - easyFind with vector vec" << std::endl;
	std::vector<int> vec;
	initializeContainer(vec, SIZE);
	int validValue = SIZE - 1;
	std::cout << "Vector: Searching for " << validValue << ": " << (easyFind(vec, validValue) ? "Found" : "Not Found")
			  << std::endl;
	int invalidValue = SIZE + 1;
	std::cout << "Vector: Searching for " << invalidValue << ": "
			  << (easyFind(vec, invalidValue) ? "Found" : "Not Found") << std::endl;

	std::cout << "Test 2 - easyFindThrow with list lst" << std::endl;
	std::list<int> lst(SIZE);
	initializeContainer(lst, SIZE);
	std::cout << "List: Searching for " << validValue << ": " << (easyFind(lst, validValue) ? "Found" : "Not Found")
			  << std::endl;
	std::cout << "List: Searching for " << invalidValue << ": " << (easyFind(lst, invalidValue) ? "Found" : "Not Found")
			  << std::endl;
	std::cout << "Test 3 - easyFindThrow with vec" << std::endl;
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

	std::cout << "Test 4 - easyFindThrowIndex" << std::endl;
	std::deque<int> deq;
	initializeContainer(deq, SIZE);
	std::cout << "Deque: Searching for " << validValue << ": " << (easyFind(deq, validValue) ? "Found" : "Not Found")
			  << std::endl;
	std::cout << "Deque: Searching for " << invalidValue << ": "
			  << (easyFind(deq, invalidValue) ? "Found" : "Not Found") << std::endl;
	int index;
	try
	{
		index = easyFindThrowIndex(deq, 3);
		std::cout << "Value found in deque at index: " << index << "." << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyFindThrow(deq, 6);
		std::cout << "Value found in deque." << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
