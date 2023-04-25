//TransferParametrs
#include <iostream>

void Exchange(int& a, int& b);
#define delimiter "\n-------------------------------------------\n"

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	std::cout << a << "\t" << b << std::endl;
	std::cout << &a << "\t" << &b << std::endl;
	std::cout << delimiter << std::endl;
	Exchange(a, b);
	std::cout << delimiter << std::endl;
	std::cout << a << "\t" << b << std::endl;
	std::cout << &a << "\t" << &b << std::endl;
}
/*
	-------------------
	1. by value;
	2. by pointer;
	3. by reference;
	-------------------
*/

void Exchange(int& a, int& b)
{
	std::cout << &a << "\t" << &b << std::endl;
	int buffer = a;
	a = b;
	b = buffer;
	std::cout << a << "\t" << b << std::endl;
}
