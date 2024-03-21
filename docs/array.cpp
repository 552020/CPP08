#include <iostream>
#include <algorithm> // For std::copy

// C++(98) does not have a built-in array class, so we use a raw array

int main()
{
	// Creation of an array with 5 elements
	int myArray[5] = {1, 2, 3, 4, 5};

	// Access and print an element in the middle
	int middleIndex = sizeof(myArray) / sizeof(myArray[0]) / 2; // Calculate middle index
	std::cout << "Element in the middle: " << myArray[middleIndex] << std::endl;

	// Substitute an element in the middle
	myArray[middleIndex] = 10;
	std::cout << "After substitution, middle element: " << myArray[middleIndex] << std::endl;

	// "Resizing" the array: create a new array with a different size
	const int newSize = 6;			  // New desired size
	int *newArray = new int[newSize]; // Dynamically allocate a new array

	// Copy elements from the old array to the new array
	// Note: In a real scenario, you'd likely want to check bounds and copy accordingly
	std::copy(myArray, myArray + 5, newArray);

	// Add a new element at the end of the new array
	newArray[newSize - 1] = 6;

	// Delete the old array if it was dynamically allocated
	// Not applicable here since myArray is not dynamically allocated

	// Re-declare the old array pointer to point to the new array
	// This is somewhat simulated here since myArray is not a pointer
	int *myArrayDynamic = newArray;

	// Print elements of the new array
	std::cout << "New array elements: ";
	for (int i = 0; i < newSize; ++i)
	{
		std::cout << myArrayDynamic[i] << " ";
	}
	std::cout << std::endl;

	// Clean up dynamic memory
	delete[] myArrayDynamic;

	return 0;
}
