#include <iostream>
#include <Windows.h>

void FillRand(int arr[], const int n);
void FillRand(int arr[], const int n, int minRand, int maxRand);
int** Allocate(const int rows, const int cols);
template <typename T> void Print(T arr[], const int n);
template <typename T> void Print(T** arr, const int rows, const int cols);
template <typename T> T* push_back(T* arr, int& n, int value);
template <typename T> T* push_front(T* arr, int& n, int value);
template <typename T> T* insert(T* arr, int& n, int value, int index);
template <typename T> T* pop_back(T* arr, int& n);
template <typename T> T* pop_front(T* arr, int& n);
template <typename T> void FillRand(T** arr, const int rows, const int cols);
template <typename T> void Clear(T** arr, const int rows);
template <typename T> T** insertRow(T** arr, int& rows, const int cols, int const index);
template <typename T> T** EraseRow(T** arr, int& rows, const int cols, int const index);
template <typename T> T** push_row_back(T** arr, int& rows, const int cols);
template <typename T> T** push_row_front(T** arr, int& rows, const int cols);
template <typename T> void push_col_back(T** arr, const int rows, int& cols);
template <typename T> void push_col_front(T** arr, const int rows, int& cols);
template <typename T> T** pop_row_back(T** arr, int& rows, const int cols);
template <typename T> void pop_row_front(T** arr, int& rows, const int cols);
template <typename T> void pop_col_back(T** arr, const int rows, int& cols);

//=========================================================================

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
#define delimiter "\n--------------------------\n"

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

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	std::cout << "Enter amount of rows: "; std::cin >> rows;
	std::cout << "Enter amount of cols: "; std::cin >> cols;
	
	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << delimiter << std::endl;

	arr = push_row_back(arr, rows, cols);

	Print(arr, rows, cols);
	
	std::cout << delimiter << std::endl;
	
	std::cout << "Deleting last row: " << std::endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << delimiter << std::endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << delimiter << std::endl;
	
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << delimiter << std::endl;
	std::cout << "Pointer arythmetic: " << std::endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << *(*(arr + i) + j) << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << delimiter << std::endl;

	Clear(arr, rows);
#endif //DYNAMIC_MEMORY_2

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void  FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
template <typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}
template <typename T> T* push_back(T* arr, int& n, int value)
{
	T* buffer = new int[n + 1];
	for(int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	arr[n] = value;
	n++;
	return arr;
}
template <typename T> T* push_front(T* arr, int& n, int value)
{
	T* buffer = new int[n + 1] {};
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
template <typename T> T* insert(T* arr, int& n, int value, int index)
{
	T* buffer = new int[n + 1];
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
template <typename T> T** insertRow(T** arr, int& rows, const int cols, int const index)
{
	T** buffer = new T * [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		i >= index ? buffer[i + 1] = arr[i] : buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new T[cols]{};
	rows++;
	return arr;
} //
template <typename T> T* pop_back(T* arr, int& n)
{
	T* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[]arr;
	return buffer;

	/*T* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++);
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;*/
}
template <typename T> T* pop_front(T* arr, int& n)
{
	T* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template <typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
			delete[] arr[i];
			arr[i] = buffer;
		}
	}
}
template <typename T> void pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T * (rows - 1);
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template <typename T> T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1]; //1. deleting row;
	T** buffer = new int*[--rows]; //2. creating buffer array;
	for (int i = 0; i < rows; i++) //3. copy adress to a new array;
	{
		buffer[i] = arr[i];
	}
	delete[] arr; //4. deleting og array;
	return buffer;
}
template <typename T> void FillRand(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
template <typename T> void Print(T** arr, const int rows, const int cols)
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
template <typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;
}
template <typename T> T** EraseRow(T** arr, int& rows, const int cols, int const index)
{
	T** buffer = new T * [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		i >= index ? buffer[i] = arr[i + 1] : buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template <typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
			delete[] arr[i];
			arr[i] = buffer;
		}
	}
}
template <typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new int[cols + 1] {}; //1. createting buffer row;
		for (int j = 0; j < cols; j++) //2. copy all in og array to the buffer;
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i]; //3. delete og row;
		arr[i] = buffer; //4. writing new adress of ne row in array;
	}
	cols++;
}
template <typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int [cols] {};
	rows++;
	return arr;
}
template <typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new int* [rows + 1]; //1. create buffer array;
	for (int i = 0; i < rows; i++) //2. copy rows adress;
	{
		buffer[i] = arr[i];
	}
	delete[]arr;  //3. delete og array
	arr = buffer;     //4. swap the adress in 'arr' pointer to a new array adress;
	arr[rows] = new int[cols] {};    //5. create a new row;
	rows++; //6. adding new row;
	return arr; //7. returning new array;

}