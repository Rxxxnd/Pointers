#include <iostream>

void FillRand(int arr[], const int n);

void Print(int arr[], const int n);
int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value, int index);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* pop_front(int* arr, int& n);

void FillRand(int** arr, const int rows, const int cols);
void Print(int** arr, const int rows, const int cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	std::cout << "Enter the size of array: "; std::cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	std::cout << "Enter added value: "; std::cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	std::cout << "Enter added value: "; std::cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	
	int index;
	std::cout << "Enter idex of added element: "; std::cin >> index;
	std::cout << "Enter added value: "; std::cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	delete[] arr;
#endif //DYNAMIC_MEMORY_1

	int rows, cols;

	std::cout << "Enter amount of rows: "; std::cin >> rows;
	std::cout << "Enter amount of cols: "; std::cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//1) удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) удаляем массив указателей:
	delete[]arr;

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
int* push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1]; //1. create buffer array.
	for (int i = 0; i < n; i++) //2. copy all elements of array to a buffer array:
	{
		buffer[i] = arr[i];
	}
	delete[] arr; //3. Deleting pervious array;
	arr = buffer; //4. Changing pervious array adress to a new array;
	buffer = nullptr; // 4.1 cleaning second pointer. Null-pointer (pointer @ 0);
	arr[n] = value; //5. Now can add new values to 'arr';
	n++;
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;

	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	/*int* buffer = new int[n-1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;*/

	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}