#include <iostream>
#include <list>

void printList(const std::list<int> &list)
{
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << " ";
	}
	if (list.empty())
	{
		std::cout << "List is empty";
	}
	std::cout << std::endl;
}

void printListBackwards(const std::list<int> &list)
{
	for (std::list<int>::const_reverse_iterator it = list.rbegin(); it != list.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	// Create an empty list of integers
	std::list<int> myList;

	std::cout << "List elements in forward direction:" << std::endl;
	printList(myList);

	// Check if the list is initially empty
	std::cout << "Is the list empty? " << (myList.empty() ? "Yes" : "No") << std::endl;

	// Add elements to the list using push_back and push_front
	myList.push_back(2);  // List: 2
	myList.push_back(4);  // List: 2, 4
	myList.push_front(1); // List: 1, 2, 4
	myList.push_back(3);  // List: 1, 2, 4, 3

	// Print the contents of the list in forward direction
	std::cout << "List elements in forward direction:" << std::endl;
	printList(myList);

	// Check if the list is initially empty
	std::cout << "Is the list still empty? " << (myList.empty() ? "Yes" : "No") << std::endl;

	// Print the contents of the list in forward direction
	std::cout << "List elements in forward direction:" << std::endl;
	printList(myList);
	std::cout << std::endl;

	// Print the contents of the list in reverse direction
	std::cout << "List elements in reverse direction:" << std::endl;
	printListBackwards(myList);
	std::cout << std::endl;

	// Demonstate the copy constructor
	std::list<int> myListCopy(myList);
	std::cout << "Copied list elements in forward direction:" << std::endl;
	printList(myListCopy);

	// Change values in the copied list
	std::list<int>::iterator it = myListCopy.begin();
	*it = 10; // Change first element to 10
	++it;
	*it = 20; // Change second element to 20

	std::cout << "myListCopy after changing values:" << std::endl;
	printList(myListCopy);
	std::cout << std::endl;
	std::cout << "myList after changing values in myListCopy:" << std::endl;
	printList(myList);
	std::cout << std::endl;

	// Demonstrate the assignment operator
	std::list<int> myListAssigned;
	myListAssigned = myList;
	std::cout << "Assigned list elements in forward direction:" << std::endl;
	printList(myListAssigned);

	std::list<int>::iterator itAssigned = myListAssigned.begin();
	*itAssigned = 100; // Change first element to 100
	++itAssigned;
	*itAssigned = 200; // Change second element to 200

	std::cout << "myListAssigned after changing values:" << std::endl;
	printList(myListAssigned);
	std::cout << std::endl;
	std::cout << "myList after changing values in myListAssigned:" << std::endl;
	printList(myList);
	std::cout << std::endl;

	// Demonstate constructor with initial size and value
	std::list<int> myListSize(5, 10);
	std::cout << "Constructor with initial size and value" << std::endl;
	std::cout << "std::list<int> myListSize(5, 10);" << std::endl;
	std::cout << "List elements in forward direction:" << std::endl;
	printList(myListSize);

	// Demonstrate front and back accessors
	std::cout << "First element: " << myList.front() << std::endl;
	std::cout << "Last element: " << myList.back() << std::endl;

	// Push front and back
	std::cout << "myList.push_front(0);" << std::endl;
	myList.push_front(0);
	std::cout << "myList.push_back(5);" << std::endl;
	myList.push_back(5);
	std::cout << "List elements after push front and back:" << std::endl;
	printList(myList);

	// Pop front and back
	std::cout << "myList.pop_front();" << std::endl;
	myList.pop_front();
	std::cout << "myList.pop_back();" << std::endl;
	myList.pop_back();
	std::cout << "List elements after pop front and back:" << std::endl;
	printList(myList);

	// Insert an element at the third position
	std::list<int>::iterator itInsert = myList.begin();
	itInsert++;
	itInsert++;

	std::cout << "Inserting 100 at the third position" << std::endl;
	std::cout << "myList.insert(itInsert, 100);" << std::endl;
	myList.insert(itInsert, 100);
	printList(myList);

	// Erase the element at the third position
	std::cout << "Erasing the element at the third position" << std::endl;
	std::cout << "myList.erase(itInsert);" << std::endl;
	myList.erase(itInsert);
	printList(myList);

	// Demonstarte swap
	std::list<int> myListSwap(3, 30);
	std::cout << "myList elements in forward direction before swap:" << std::endl;
	printList(myList);
	std::cout << "myListSwap elements in forward direction before swap:" << std::endl;
	printList(myListSwap);
	std::cout << "myList.swap(myListSwap);" << std::endl;
	myList.swap(myListSwap);
	std::cout << "myList elements in forward direction after swap:" << std::endl;
	printList(myList);
	std::cout << "myListSwap elements in forward direction after swap:" << std::endl;
	printList(myListSwap);

	// Domestate clear
	std::cout << "Clearing myList" << std::endl;
	myList.clear();
	std::cout << "myList elements in forward direction after clear:" << std::endl;
	printList(myList);

	// Demonstrate value_type to declare a variable
	std::list<int>::value_type value = 100;
	std::cout << "value_type value: " << value << std::endl;

	// Repopulate the list
	myList.push_back(2);	 // List: 2
	myList.push_back(4);	 // List: 2, 4
	myList.push_front(1);	 // List: 1, 2, 4
	myList.push_back(3);	 // List: 1, 2, 4, 3
	myList.push_back(value); // List: 1, 2, 4, 3, 100

	// Use size_type to get the size of the list
	std::list<int>::size_type size = myList.size();
	std::cout << "Size of myList: " << size << std::endl;

	// Use iterator to iterate over the list and print elements
	std::cout << "Elements (using iterator): ";
	for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	// Use const_iterator to iterate over the list and print elements
	std::cout << "Elements (using const_iterator): ";
	for (std::list<int>::const_iterator cit = myList.cbegin(); cit != myList.cend(); ++cit)
	{
		std::cout << *cit << ' ';
	}
	std::cout << std::endl;

	return 0;
}
