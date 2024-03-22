#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) : maxSize(N)
{
	numbers = new std::vector<int>;
}

Span::Span(const Span &other) : maxSize(other.maxSize)
{
	numbers = new std::vector<int>(*other.numbers);
}

Span::~Span()
{
	delete numbers;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		delete numbers;
		numbers = new std::vector<int>(*other.numbers);
		maxSize = other.maxSize;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (numbers->size() >= maxSize)
	{
		throw std::out_of_range("It's full. Try again later ...");
	}
	numbers->push_back(number);
}

int Span::shortestSpan() const
{
	if (numbers->size() < 2)
	{
		throw std::logic_error("Not enough elements to find a span.");
	}

	std::vector<int> sortedNumbers = *numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortest = sortedNumbers[1] - sortedNumbers[0];

	std::vector<int>::const_iterator it = sortedNumbers.begin() + 1;

	for (; it != sortedNumbers.end(); ++it)
	{
		int current = *it;
		int prev = *(it - 1);
		int span = current - prev;
		if (span < shortest)
			shortest = span;
	}

	return shortest;
}

int Span::longestSpan() const
{
	if (numbers->size() < 2)
	{
		throw std::logic_error("Not enough elements to find a span.");
	}

	std::vector<int> sortedNumbers = *numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	return sortedNumbers.back() - sortedNumbers.front();
}
