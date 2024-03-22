#include <iostream>
#include <stack>

// We need the typename U for the case we initialise the stack with a vector or any other container
// OUr print function otherwise would not work
template <typename T, typename U>
void printStack(std::stack<T, U> myStack)
{
	std::stack<T> tempStack;

	// Pop elements from the original stack, print them, and push them onto the temporary stack
	while (!myStack.empty())
	{
		T topElement = myStack.top();
		myStack.pop();
		std::cout << topElement << " ";
		tempStack.push(topElement);
	}
	std::cout << std::endl;

	// Restore the original stack by pushing elements back from the temporary stack
	while (!tempStack.empty())
	{
		myStack.push(tempStack.top());
		tempStack.pop();
	}
}

void stackWithVector()
{
	// Not valid in C++98
	// std::vector<int> myVector = {1, 2, 3, 4, 5};
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

int main()
{
	std::stack<int> myStack;
	// error: use of class template 'std::stack' requires template arguments
	// std::stack myStackWithoutType;

	// Push numbers onto the stack
	myStack.push(10);
	myStack.push(20);
	printStack(myStack);

	// Access the top element
	std::cout << "Top element: " << myStack.top() << std::endl;

	// Remove the top element
	myStack.pop();

	// Check if stack is empty
	if (!myStack.empty())
	{
		std::cout << "Stack is not empty" << std::endl;
	}

	stackWithVector();

	return 0;
}
