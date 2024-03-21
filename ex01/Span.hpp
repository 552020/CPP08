#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
  public:
	Span(unsigned int N);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);

	void addNumber(int number);
	template <typename I>
	void addManyFromRange(I start, I end)
	{
		try
		{
			while (start != end)
			{
				addNumber(*start);
				++start;
			}
		}
		catch (const std::out_of_range &e)
		{
			std::cout << "Exception caught :" << e.what() << std::endl;
		}
	}
	int shortestSpan() const;
	int longestSpan() const;

  private:
	std::vector<int> *numbers;
	unsigned int maxSize;
};

#endif
