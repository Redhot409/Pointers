//Pointers
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define POINTERS_BASICS
void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS

	int a = 2;
	int* pa = &a;
	cout << a << endl;//вывод значение переменной на экран
	cout << &a << endl;// взятие адреса переменной а прямо при выводе
	cout << pa << endl;// вывод адреса переменной а, хранящегося в указателе ра
	cout << *pa << endl;// разыменование указателя ра и вывод значения переменной а
	// int - int
	//int* - Указатель на int
	int* pb;
	int b = 3;
	pb = &b;
	cout << *pb << endl;
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;//разыменовали
	for (int i = 0; i < n; i++)
	{
		//cout << arr + i << "\t";
		cout << *(arr + i) << "\t";

	}
	cout << endl;
}

	