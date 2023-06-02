#include <iostream>
#include <Windows.h>

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);
void FillRand(int arr[], const int n, int minRand, int maxRand);
void FillRand(char arr[], const int n, int minRand, int maxRand);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);
  template <typename T>T** Allocate(const int rows, const int cols);
template <typename T> void Print(T arr[], const int n);
template <typename T> void Print(T** arr, const int rows, const int cols);
template <typename T> void Clear(T** arr, const int rows);
  template <typename T> T* insert(T* arr, int& n, T value, int index);
 template <typename T> T** insertRow(T** arr, int& rows, const int cols, int const index);
 template <typename T> T** EraseRow(T** arr, int& rows, const int cols, int const index);
  template <typename T> T* push_back(T* arr, int& n, T value);
  template <typename T> T* push_front(T* arr, int& n, T value);
 template <typename T> T** push_row_back(T** arr, int& rows, const int cols);
 template <typename T> T** push_row_front(T** arr, int& rows, const int cols);
template <typename T> void push_col_back(T** arr, const int rows, int& cols);
template <typename T> void push_col_front(T** arr, const int rows, int& cols);
  template <typename T> T* pop_back(T* arr, int& n);
  template <typename T> T* pop_front(T* arr, int& n);
 template <typename T> T** pop_row_back(T** arr, int& rows, const int cols);
template <typename T> T** pop_row_front(T** arr, int& rows, const int cols);
template <typename T> void pop_col_back(T** arr, const int rows, int& cols);

//=========================================================================

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
#define delimiter "\n--------------------------\n"

typedef int DataType;

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	std::cout << "Enter the size of array: "; std::cin >> n;
	DataType* arr = new DataType[n];
	FillRand(arr, n);
	Print(arr, n);

	DataType value;
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
	
	DataType** arr = Allocate<DataType>(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << delimiter << std::endl;
	std::cout << "Deleting first row: " << std::endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	std::cout << delimiter << std::endl;
	std::cout << "Deleting row (popback): " << std::endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << delimiter << std::endl;
	std::cout << "Deleting row (popfront): " << std::endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << delimiter << std::endl;
	std::cout << "Push row" << std::endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << delimiter << std::endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	std::cout << delimiter << std::endl;
	
	int index;
	std::cout << "Enter index of added row: "; std::cin >> index;
	arr = insertRow(arr, rows, cols, index);
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
	std::cout << "Push back: " << std::endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
#endif //DYNAMIC_MEMORY_2

}
//========================================================================================
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 10000;
		arr[i] /= 100;
	}
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
	{
		for (int i = 0; i < n; i++)
		{
			*(arr + i) = rand() % (maxRand - minRand) + minRand;
		}
	}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
  template <typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
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
  template <typename T> T* insert(T* arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1];
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
	 return insert(arr, rows, new T[cols]{}, index);

} //
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
  template <typename T> T* push_front(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1] {};
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
  template <typename T> T* push_back(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1];
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
		arr[i]=push_back(arr[i], cols, T());
		cols--;
	}
	cols++;
}
 template <typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
	 return push_front(arr, rows, new T[cols]{});

	
}
 template <typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
	 return push_back(arr, rows, new T[cols]{});

	//T** buffer = new T* [rows + 1]; //1. create buffer array;
	//for (int i = 0; i < rows; i++) //2. copy rows adress;
	//{
	//	buffer[i] = arr[i];  
	//}
	//delete[]arr;  //3. delete og array
	//arr = buffer;     //4. swap the adress in 'arr' pointer to a new array adress;
	//arr[rows] = new T[cols] {};    //5. create a new row;
	//rows++; //6. adding new row;
	//return arr; //7. returning new array;
}
  template <typename T> T* pop_front(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
  template <typename T> T* pop_back(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
 template <typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T*[rows - 1];
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
	 return pop_back(arr, rows);
	T** buffer = new T*[--rows]; //2. creating buffer array;
	for (int i = 0; i < rows; i++) //3. copy adress to a new array;
	{
		buffer[i] = arr[i];
	}
	delete[] arr; //4. deleting og array;
	return buffer;
}
template <typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}