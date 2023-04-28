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
	
	int* buffer = new int[n + 1]; //1. create buffer array.

	for (int i = 0; i < n; i++) //2. copy all elements of array to a buffer array;
	{
		buffer[i] = arr[i];
	}
	delete[] arr; //3. Deleting pervious array;
	
	arr = buffer; //4. Changing pervious array adress to a new array;
	
	buffer = nullptr; // 4.1 cleaning second pointer. Null-pointer (pointer @ 0);
	
	arr[n] = value; //5. Now can add new values to 'arr';
	
	n++; //6. Now added new element to array;

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