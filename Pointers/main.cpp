#include <iostream>

//#define POINTERS_BASICS


void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;

	std::cout << a << std::endl;   // вывод переменной 'а';
	std::cout << &a << std::endl;  // взятие переменной 'a' прямо при выводе;
	std::cout << pa << std::endl;  // вывод адреса переменной 'a' хранящегося в указателе 'pa';
	std::cout << *pa << std::endl; // разыменование указателя 'pa', и вывод на экран значения по адресу.


	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
	}
	cout << endl;
}


#endif // POINTERS_BASICS
/*
----------------------
& - Оператор взятия адреса (Address-of operator)
* - Оператор разыменования (Dereference operator)
----------------------
*/


	const int n = 5;
	int arr[n] = { 2,4,6,8,10 };

	for (int i = 0; i < n; i++)
	{
		std::cout << *(arr + i) << std::endl;
	}



}
