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
	std::cout << "\n***Test 1 - easyFind with vector vec\n" << std::endl;
	std::vector<int> vec;
	initializeContainer(vec, SIZE);
	int validValue = SIZE - 1;
	std::cout << "Searching for " << validValue << ": " << (easyFind(vec, validValue) ? "Found" : "Not Found")
			  << std::endl;
	int invalidValue = SIZE + 1;
	std::cout << "Searching for " << invalidValue << ": "
			  << (easyFind(vec, invalidValue) ? "Found" : "Not Found") << std::endl;

	std::cout << "\n***Test 2 - easyFindThrow with list lst\n" << std::endl;
	std::list<int> lst(SIZE);
	initializeContainer(lst, SIZE);
	std::cout << "Searching for " << validValue << ": " << (easyFind(lst, validValue) ? "Found" : "Not Found")
			  << std::endl;
	std::cout << "Searching for " << invalidValue << ": " << (easyFind(lst, invalidValue) ? "Found" : "Not Found")
			  << std::endl;
	std::cout << "\n***Test 3 - easyFindThrow with vec\n" << std::endl;
	try
	{
		std::cout << "Searching for " << validValue << ": " <<
		(easyFindThrow(vec, validValue) ? "Found" : "Not Found") << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "Searching for " << invalidValue << ": " <<
		(easyFindThrow(vec, invalidValue) ? "Found" : "Not Found") << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n***Test 4 - easyFind with Deque\n" << std::endl;
	std::deque<int> deq;
	initializeContainer(deq, SIZE);
	std::cout << "Searching for " << validValue << ": " << (easyFind(deq, validValue) ? "Found" : "Not Found")
			  << std::endl;
	std::cout << "Searching for " << invalidValue << ": "
			  << (easyFind(deq, invalidValue) ? "Found" : "Not Found") << std::endl;

	std::cout << "\n***Test 5 - easyFindThrowIndex with Deque\n" << std::endl;
	int index;
	std::cout << "Searching for " << validValue << ": ";
	try
	{
		index = easyFindThrowIndex(deq, validValue);
		std::cout << "Found at index: " << index << "." << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n***Test 6 - easyFindThrowIndex with Deque \n" << std::endl;
	std::cout << "Searching for " << invalidValue << ": ";
	try
	{
		index = easyFindThrowIndex(deq, invalidValue);
		std::cout << "Found at index: " << index << "." << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
