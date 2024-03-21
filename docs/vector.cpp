#include <iostream>
#include <vector>

int main()
{
	// Creating a vector with 5 elements
	std::vector<int> myVector;
	for (int i = 1; i <= 5; ++i)
	{
		myVector.push_back(i); // Adding elements to the vector
	}

	// Accessing an element in the middle
	size_t middleIndex = myVector.size() / 2;
	std::cout << "Element in the middle: " << myVector[middleIndex] << std::endl;

	// Substituting an element in the middle
	myVector[middleIndex] = 10;
	std::cout << "After substitution, middle element: " << myVector[middleIndex] << std::endl;

	// Adding an element to the end
	myVector.push_back(6);

	// Inserting an element in the middle
	myVector.insert(myVector.begin() + middleIndex, 15);

	// Removing an element from the middle
	myVector.erase(myVector.begin() + middleIndex);

	// Resizing the vector to a smaller size (to demonstrate, shrinking to 4 elements)
	myVector.resize(4);

	// Printing the current state of the vector
	std::cout << "Current vector elements: ";
	for (size_t i = 0; i < myVector.size(); ++i)
	{
		std::cout << myVector[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
