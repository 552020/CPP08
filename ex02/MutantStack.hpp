#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

// clang-format off
template< typename T, typename C = std::deque<T> >
// clang-format on
class MutantStack : public std::stack<T, C>
{
  public:
	MutantStack() : std::stack<T, C>() {};
	MutantStack(const MutantStack &other) : std::stack<T, C>(other) {};
	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
		{
			std::stack<T, C>::operator=(other);
		}
		return *this;
	}
	~MutantStack() {};
	// We need typedef, cause of the main in the subject
	typedef typename C::const_iterator const_iterator;
	typedef typename C::const_reverse_iterator const_reverse_iterator;
	typedef typename C::iterator iterator;
	typedef typename C::reverse_iterator reverse_iterator;

	const_iterator begin() const
	{
		return this->c.begin();
	}

	const_iterator end() const
	{
		return this->c.end();
	}

	const_reverse_iterator rbegin() const
	{
		return this->c.rbegin();
	}

	const_reverse_iterator rend() const
	{
		return this->c.rend();
	}

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}

	reverse_iterator rend()
	{
		return this->c.rend();
	}
};

#endif