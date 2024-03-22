#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <ctime>   // For std::time
#include <cstdlib> // For std::rand and std::srand
#include <climits> // for INT_MAX and INT_MIN

#define MAX_N INT_MAX
#define MIN_N 0
#define STEP 1

std::vector<int> createVector(unsigned int n, bool isRandom)
{
	std::vector<int> numbers;

	if (isRandom)
	{
		std::srand(static_cast<unsigned int>(std::time(0)));
		for (size_t i = 0; i < static_cast<size_t>(n); ++i)
		{
			int range = MAX_N - MIN_N;
			int randomNumber = MIN_N + (std::rand() % range + 1);
			numbers.push_back(randomNumber);
		}
	}
	else
	{
		for (size_t i = 0; i < static_cast<size_t>(n); ++i)
		{
			numbers.push_back(i * STEP);
		}
	}
	return numbers;
}

void testAddManyFromRange(unsigned int n, bool isRandom, unsigned int spanSize = 10000)
{

	std::cout << "\nTesting addManyFromRange with " << n << (isRandom ? " random" : " not random") << " numbers"
			  << std::endl;
	std::vector<int> numbers = createVector(n, isRandom);
	Span mySpan(spanSize);

	try
	{
		mySpan.addManyFromRange(numbers.begin(), numbers.end());
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Expected exception caught: " << e.what() << std::endl;
	}
	std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;
}

int main()
{
	Span mySpan = Span(5);
	mySpan.addNumber(6);
	mySpan.addNumber(3);
	mySpan.addNumber(17);
	mySpan.addNumber(9);
	mySpan.addNumber(11);
	std::cout << mySpan.shortestSpan() << std::endl;
	std::cout << mySpan.longestSpan() << std::endl;
	//testAddManyFromRange(100, true, 5);
	//testAddManyFromRange(100, true);
	//testAddManyFromRange(10000, false);

	return 0;
}