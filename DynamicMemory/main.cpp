//DynamicMemory
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		//��������� � ��-��� ����� ���������� ��������� � � �������� �������������
		*(arr + 1) = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}