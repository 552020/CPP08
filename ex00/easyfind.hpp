#include <algorithm> // For std::find
#include <vector>	 // Example container
#include <list>		 // Example container
#include <iostream>
#include <stdexcept> // For std::exception

template <typename C>
bool easyFind(const C &container, int value)
{
	// Use std::find to search for the value in the container
	// std::end(container) is used to get the end iterator for the container
	// auto it = std::find(std::begin(container), std::end(container), value);
	// We need to explicitly specify the type of the iterator because the compiler can't deduce it
	typename C::const_iterator it = std::find(std::begin(container), std::end(container), value);

	// If iterator it is not equal to the end iterator, the value was found
	bool found = it != std::end(container);
	return found;
}

template <typename C>
void easyFindThrow(const C &container, int value)
{
	// Use std::find to search for the value in the container
	// auto it = std::find(std::begin(container), std::end(container), value);
	// We need to explicitly specify the type of the iterator because the compiler can't deduce it
	typename C::const_iterator it = std::find(std::begin(container), std::end(container), value);

	// If iterator it is equal to the end iterator, the value was not found
	if (it == std::end(container))
	{
		throw std::runtime_error("Value not found in the container");
	}
}

template <typename Container>
int easyFindThrowIndex(const Container &container, int value)
{
	typename Container::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw std::runtime_error("Value not found in the container");
	}
	else
	{
		// If found, return the index
		return std::distance(container.begin(), it);
	}
}
