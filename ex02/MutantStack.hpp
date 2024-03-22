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

	// Iterators with typedef

	const_iterator begin() const
	{
		// We access the protected c class member of the underlying container
		return this->c.begin();
	}

	const_iterator end() const
	{
		// We access the protected c class member of the underlying container
		return this->c.end();
	}

	const_reverse_iterator rbegin() const
	{
		// We access the protected c class member of the underlying container
		return this->c.rbegin();
	}

	const_reverse_iterator rend() const
	{
		// We access the protected c class member of the underlying container
		return this->c.rend();
	}

	// Iterator without typedef
	iterator begin()
	{
		// We access the protected c class member of the underlying container
		return this->c.begin();
	}

	iterator end()
	{
		// We access the protected c class member of the underlying container
		return this->c.end();
	}

	reverse_iterator rbegin()
	{
		// We access the protected c class member of the underlying container
		return this->c.rbegin();
	}

	reverse_iterator rend()
	{
		// We access the protected c class member of the underlying container
		return this->c.rend();
	}
};

#endif

// About the c variable, which represents the underlying container
// https://en.cppreference.com/w/cpp/container/stack