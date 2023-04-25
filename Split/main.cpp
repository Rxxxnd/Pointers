//Split

#include<iostream>;

	//void FillRand(int arr[], const int n);
	//void Print(int arr[], const int n);
	//void Split(int arr[], const int n);
	//void SizeCalc(int arr[], const int n, int& even, int& odd);
	//void Sorting(int arr[]; const int n, int even_arr[], int odd_arr[]);


	//void main()
	//{

	//	int n;
	//	std::cout << "Enter the size of array: "; std::cin >> n;
	//	int* arr = new int[n];
	//	FillRand(arr, n);
	//	Print(arr, n);

	//	int even_counter;
	//	int odd_counter;

	//	int* even_arr = new int[even];
	//	int* odd_arr = new int[odd];

	//	Split(arr, n);

	//	delete[] arr;
	//	delete[] even_arr;
	//	delete[] odd_arr;

	//}

	//void FillRand(int arr[], const int n)
	//{
	//	for (int i = 0; i < n; i++)
	//	{
	//		*(arr + i) = rand() % 100;
	//	}
	//}

	//void Print(int arr[], const int n)
	//{
	//	for (int i = 0; i < n; i++)
	//	{
	//		std::cout << arr[i] << "\t";
	//	}
	//	std::cout << std::endl;
	//}

	//void Split(int arr[], const int n)

	//void SizeCalc(int arr[], const int size, int& even, int& odd)
	//{
	//	for (int i = 0; i < size; i++)
	//	{
	//		if (arr[i] % 2 == 0)
	//		{
	//			even++;
	//		}
	//		else odd++;
	//	}

	//}

	//void Sorting(int arr[]; const int n, int even_arr[], int odd_arr[])
	//{
	//	int e = 0;
	//	int o = 0;
	//	for (int i = 0; i < size; i++)
	//	{
	//		if (arr[i] % 2 == 0)
	//		{,,
	//			even_arr[e] = arr[i];
	//			e++;
	//		}
	//		else
	//		{
	//			odd_arr[o] = arr[i];
	//			o++;
	//		}
	//	}
	//}


void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_cout++;
		else odd_count;
	}

	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	for (int i = 0; j = 0; k = 0; i < n; i++)
	{
		/*if (arr[i] % 2 == 0) even_arr[j++] = arr[i];
		else odd_arr[k++] = arr[i];*/
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];

	}
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);

	delete[] odd_arr;
	delete[] even_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	std::cout << std::endl;
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}
