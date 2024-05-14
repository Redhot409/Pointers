//DynamicMemory
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);
int** push_row_back(int** arr, const int rows, const int cols);
int** pop_row_back(int** arr, const int rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);

void FillRand(int arr[], const int n);
void FillRand(int arr[], const int rows,const int cols);
void Print(int arr[], const int n);
void Print(int arr[], const int rows, const int cols);
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);



void main()
{
	setlocale(LC_ALL, "");
	int n;// �� �������� const �� ������ ����� �������� ������������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������:"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	//delete[] arr;
	//delete[] buffer;

	cout << "������� ����������� ��������:"; cin >> value;
	arr=push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);


	int rows;
	int cols;
	cout << "������� ���-�� �����:"; cin >> rows;
	cout << "������� ���-�� ��������:"; cin >> cols;

	int** arr = Allocate(rows, cols);

	FillRand(arr, rows,cols);
	Print(arr, rows,cols);

	arr=push_row_back(arr, rows, cols);
	Print(arr, rows,cols);



	arr=pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = pop_col_back(arr, rows, cols);

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��������� � ��-��� ����� ���������� ��������� � � �������� �������������
		*(arr + i) = rand() % 100;
	}
	
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];// ������� ��������� ������ ������� �������
	//2)�������� �������� ��������� ������� � ���������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������
	delete[] arr;
	//4) ��������� ����� ��������� ������� ������� ������ �������:
	arr = buffer;
	//5) ������ ����� ����� � ����� ������� ���������� ��������� �����, 
	// ���� ����� ��������� ��������:
	arr[n] = value;
	n++;
	//Print(arr, n);
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	//3) ������� �������� ������
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������
	delete[] arr;
	return buffer;
}

int** Allocate(const int rows, const int cols)
{
	//1 ������� ������ ����������
	int** arr = new int* [rows];
	//2  �������� ������ ��� ������
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int [cols] {};
	}
	return arr;
}

void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	//1 ������� �������� ������ ���������� ������� �������
	int** buffer = new int* [rows+1];

	//2  ���� ������ �� ��� ������� ����������
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	

	//3 ������� ��� ������ ����������
	delete[] arr;

	//4 ������� ������ � ��������� �� � ������
	buffer[rows] = new int[cols] {};

	//5 ����� ���������� ������ � ������, ���������� ��� ����� �������������
	
	rows++;
	return buffer;

}

int** pop_row_back(int** arr, const int& rows, const int cols)
{
	delete[] arr[rows]; //1 ������� ������ �� ������
	//2 �������������� ������ ����������
	int** buffer = new int[--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//������� �������� ������
		int* buffer = new int[cols + 1] {};
		//�������� �������� �� ��� ������ � ��������
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		// ������� �������� ������
		delete[] arr[i];
		// ��������� ����� ������ � ������� ����������:
		arr[i] = buffer;


	}
	cols++;

}