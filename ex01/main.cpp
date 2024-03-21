#include "Span.hpp"
#include <algorithm>
#include <iostream>

void testAddManyFromRange()
{
	std::vector<int> numbers;
	for (int i = 0; i < 10; ++i)
	{
		numbers.push_back(i);
	}
	Span mySpan(5);

	try
	{
		// Attempt to add numbers from the vector to the Span
		mySpan.addManyFromRange(numbers.begin(), numbers.end());
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Expected exception caught: " << e.what() << std::endl;
	}

	std::cout << "Test completed. If no assertion failed and the expected exception was caught, the test is successful."
			  << std::endl;
}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	testAddManyFromRange();

	return 0;
}