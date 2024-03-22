#include <algorithm> // For std::find
#include <vector>	 // Example container
#include <list>		 // Example container
#include <iostream>
#include <stdexcept> // For std::exception

template <typename C>
bool easyFind(const C &container, int value)
{
	// https://cplusplus.com/reference/algorithm/find/
	typename C::const_iterator it = std::find(container.begin(), container.end(), value);

	bool found = it != container.end();
	return found;
}

template <typename C>
void easyFindThrow(const C &container, int value)
{
	typename C::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
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
		return std::distance(container.begin(), it);
	}
}
