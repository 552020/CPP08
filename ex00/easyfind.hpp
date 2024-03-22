#include <algorithm>
#include <stdexcept>

template <typename C>
bool easyFind(const C &container, int value)
{
	// https://cplusplus.com/reference/algorithm/find/
	typename C::const_iterator it = std::find(container.begin(), container.end(), value);

	bool found = it != container.end();
	return found;
}

template <typename C>
bool easyFindThrow(const C &container, int value)
{
	typename C::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
	{
		throw std::runtime_error("Not found (exception)");
	}
	bool found = it != container.end();
	return found;
}

template <typename Container>
int easyFindThrowIndex(const Container &container, int value)
{
	int index;
	typename Container::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw std::runtime_error("Not Found. (Exception)");
	}
	else
	{
		index = std::distance(container.begin(), it);
		return index; 
	}
}
