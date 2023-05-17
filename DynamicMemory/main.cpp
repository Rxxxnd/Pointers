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
void FillRand(int arr[], const int n, int minRand, int maxRand);
void Print(int** arr, const int rows, const int cols);
void Clear(int** arr, const int rows);

int** Allocate(const int rows, const int cols);
int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
void  push_col_back(int** arr, const int, int& cols);
int** pop_row_back(int** arr, int& rows, const int cols);



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
	std::cout << "Deleting row: " << std::endl;
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
void  Clear(int** arr, const int rows)
{
	//1) deleting rows:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) deleting array of pointers:
	delete[]arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	//1 Создаем буферный массив указателей:
	int** buffer = new int* [rows + 1];
	//2 Копируем адреса строк:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3 Удаляем старый массив указателей:
	delete[] arr;
	//4 Подменяем адрес в указателе 'arr' адресом нового массива:
	arr = buffer;
	//5 Создаем новую строку:
	arr[rows] = new int[cols] {};
	//6 После добавления строки, количество строк увеличивается на 1:
	rows++;
	//7 Возвращаем новый массив:
	return arr;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
	return arr;
}
void  push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1 создаем буферную строку:
		int* buffer = new int[cols + 1] {};
		//2 копиру все содержимое из исходного в буферный:
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		//3 удаляем исходную строку:
		delete[] arr[i];
		//4 записываем адрес новой строки в массив:
		arr[i] = buffer;
	}
	cols++;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	//1) delete row;
	delete[] arr[rows - 1];
	//2) create buffer array;
	int** buffer = new int* [--rows];
	//3) copy adresses to a new array;
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//4) delete pervious array;
	delete[] arr;
	return buffer;
}
