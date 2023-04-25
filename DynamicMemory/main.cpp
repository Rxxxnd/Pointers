#include <iostream>

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "Enter the size of array: "; std::cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	std::cout << "Enter added value: "; std::cin >> value;
	//1. create buffer array.
	int* buffer = new int[n + 1];

	//2. copy all elements of array to a buffer array:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	
	//3. Deleting pervious array;
	delete[] arr;
	
	//4. Changing pervious array adress to a new array;
	arr = buffer;
	// 4.1 
	buffer = nullptr; // cleaning second pointer. Null-pointer (pointer @ 0);
	//5. Now can add new values to 'arr';
	arr[n] = value;
	//6. Now added new element to array;
	n++;

	Print(arr, n);
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}