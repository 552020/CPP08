#include "MutantStack.hpp"
#include <deque>
#include <list>
#include <stack>
#include <vector>
#include <iostream>

// typename U to let work printStack with any underlying container of stack
template <typename T, typename U>
void printStack(std::stack<T, U> myStack)
{
	std::stack<T> tempStack;

	while (!myStack.empty())
	{
		T topElement = myStack.top();
		myStack.pop();
		std::cout << topElement << " ";
		tempStack.push(topElement);
	}
	std::cout << std::endl;

	while (!tempStack.empty())
	{
		myStack.push(tempStack.top());
		tempStack.pop();
	}
}

void printMutantStack(MutantStack<int> myStack)
{
	MutantStack<int>::iterator it = myStack.begin();
	MutantStack<int>::iterator ite = myStack.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void stackWithVector()
{
	std::vector<int> myVector;
	for (int i = 1; i <= 5; ++i)
	{
		myVector.push_back(i);
	}
	// clang-format off
	std::stack<int, std::vector<int> > myStack(myVector);
	// clang-format on

	printStack(myStack);
	// clang-format off
	std::stack<int, std::vector<int> > myOtherStack(myVector);
	// clang-format on
	myOtherStack.push(6);
	myOtherStack.push(7);
	myOtherStack.push(8);

	printStack(myOtherStack);
}

void testStack()
{
	std::stack<int> myStack;

	// error: use of class template 'std::stack' requires template arguments
	// std::stack myStackWithoutType;

	myStack.push(10);
	myStack.push(20);
	printStack(myStack);

	// Access the top element
	std::cout << "Top element: " << myStack.top() << std::endl;

	// Remove the top element
	myStack.pop();

	if (!myStack.empty())
	{
		std::cout << "Stack is not empty" << std::endl;
	}

	// c is a protected member of std::stack<int> and can't be accessed
	// error: 'c' is a protected member of 'std::stack<int>'
	std::cout << "std::deque<int>::iterator it = myStack.c.begin();" << std::endl;
	std::cout << "error: 'c' is a protected member of 'std::stack<int>'" << std::endl;
	// std::deque<int>::iterator it = myStack.c.begin();
	std::cout << "std::deque<int>::iterator it = myStack.c.end();" << std::endl;
	// error: no member named 'd' in 'std::stack<int>'
	std::cout << "error: no member named 'd' in 'std::stack<int>'" << std::endl;
	// std::deque<int>::iterator it = myStack.d.begin();

	stackWithVector();
}

void mainWithVector()
{
	std::cout << "mainWithVector" << std::endl;
	std::vector<int> myVector;
	myVector.push_back(5);
	myVector.push_back(17);
	std::cout << myVector.back() << std::endl;
	myVector.pop_back();
	std::cout << myVector.size() << std::endl;
	myVector.push_back(3);
	myVector.push_back(5);
	myVector.push_back(737);
	myVector.push_back(0);
	std::vector<int>::iterator it = myVector.begin();
	std::vector<int>::iterator ite = myVector.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// clang-format off
	std::stack<int, std::vector<int> > s(myVector);
	// clang-format on
}

void mainWithList()
{
	std::cout << "mainWithList" << std::endl;
	std::list<int> myList;
	myList.push_back(5);
	myList.push_back(17);
	// front() to access the first element: list doesn't have top()
	std::cout << myList.back() << std::endl;
	myList.pop_back();
	std::cout << myList.size() << std::endl;
	myList.push_back(3);
	myList.push_back(5);
	myList.push_back(737);
	myList.push_back(0);
	std::list<int>::iterator it = myList.begin();
	std::list<int>::iterator ite = myList.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// clang-format off
	std::stack<int, std::list<int> > s(myList);
	// clang-format on
}

void extraTests()
{
	std::cout << "Constructor Test with deque:" << std::endl;
	// clang-format off
	MutantStack<int, std::deque<int> > mstackDeque;
	// clang-format on
	mstackDeque.push(1);
	mstackDeque.push(2);
	mstackDeque.push(3);
	printStack(mstackDeque);

	std::cout << "Constructor Test with vector:" << std::endl;
	// clang-format off
	MutantStack<int, std::vector<int> > mstackVector;
	// clang-format on
	mstackVector.push(4);
	mstackVector.push(5);
	mstackVector.push(6);
	printStack(mstackVector);

	std::cout << "Constructor Test with list:" << std::endl;
	// clang-format off
	MutantStack<int, std::list<int> > mstackList;
	// clang-format on
	mstackList.push(7);
	mstackList.push(8);
	mstackList.push(9);
	printStack(mstackList);

	// Copy Constructor Test
	std::cout << "Copy Constructor Test:" << std::endl;
	MutantStack<int> mstackCopy(mstackDeque);
	// Modify original mstackDeque
	mstackDeque.push(10);
	std::cout << "Original MutantStack after modification: ";
	printStack(mstackDeque);
	std::cout << "Copied MutantStack should be unchanged: ";
	printStack(mstackCopy);

	// Test the copy assignment operator
	MutantStack<int> mstackOriginal;
	mstackOriginal.push(1);
	mstackOriginal.push(2);
	mstackOriginal.push(3);
	mstackOriginal.push(4);
	MutantStack<int> mstackAssigned;
	mstackAssigned = mstackOriginal;
	mstackOriginal.push(5);
	std::cout << "Original after further modification (should have 5 elements): ";
	printStack(mstackOriginal);
	std::cout << "Assigned (should have 4 elements): ";
	printStack(mstackAssigned);
}

template <typename Stack>
void printTopAndSize(const std::string &label, Stack &stack)
{
	std::cout << label << " - Top element: " << stack.top() << ", Size: " << stack.size() << std::endl;
}

void compareStackWithMutantStack()
{
	// empty, size, top, push, pop
	std::stack<int> stdStack;
	MutantStack<int> mutantStack;

	std::cout << "std::stack is " << (stdStack.empty() ? "empty" : "not empty") << std::endl;
	std::cout << "MutantStack is " << (mutantStack.empty() ? "empty" : "not empty") << std::endl;

	// Push elements
	stdStack.push(1);
	mutantStack.push(1);

	stdStack.push(2);
	mutantStack.push(2);

	stdStack.push(3);
	mutantStack.push(3);

	// Print top and size after pushes
	printTopAndSize("std::stack", stdStack);
	printTopAndSize("MutantStack", mutantStack);

	// Pop an element
	stdStack.pop();
	mutantStack.pop();

	// Print top and size after pop
	printTopAndSize("std::stack after pop", stdStack);
	printTopAndSize("MutantStack after pop", mutantStack);

	// Access top element
	std::cout << "std::stack top element after pop: " << stdStack.top() << std::endl;
	std::cout << "MutantStack top element after pop: " << mutantStack.top() << std::endl;
	// Check empty
	std::cout << "std::stack is " << (stdStack.empty() ? "empty" : "not empty") << std::endl;
	std::cout << "MutantStack is " << (mutantStack.empty() ? "empty" : "not empty") << std::endl;
}

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	// mainWithList();
	// mainWithVector();
	// extraTests();
	compareStackWithMutantStack();
	return 0;
}
