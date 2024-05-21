//DynamicMemory
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

int** push_row_back(int** arr,  int& rows, const int cols);
int** pop_row_back(int** arr, int& rows, const int cols);
int** push_col_back(int** arr, const int rows, int& cols);

void FillRand(int arr[], const int n,int minRand=0, int maxRand=100);
void FillRand(int** arr,const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* insert(int* arr, int& n, int index,int value);
int* erase(int* arr, int& n, int index,int value);

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
//#define PREFORMANCE_CHECK

void main()
{
 setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;// не написали const тк массив будет объявлен динамическим
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;// добавление нового элемента массива
	cout << "Введите добавляемое значение:"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	//delete[] arr;
	//delete[] buffer;

	cout << "Введите добавляемое значение:"; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;// введите значение индекса из доступного диапазона массива
	cout << " Insert allowed index of insert element :"<<endl;
	cin >> index;
	arr = insert(arr, n, index, value);
	Print(arr, n);

	cout << "Удаление первого элемента массива :"<< endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	
	cout << "Удаление индексного элемента массива :" << endl;
	arr = erase(arr, n, index, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "ВВедите кол-во строк:"; cin >> rows;
	cout << "ВВедите кол-во столбцов:"; cin >> cols;

	int** arr = Allocate(rows, cols);
		
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);

#endif // DYNAMIC_MEMORY_2

	
#ifdef PREFORMANCE_CHECK

	int rows;
	int cols;
	cout << "ВВедите кол-во строк:"; cin >> rows;
	cout << "ВВедите кол-во столбцов:"; cin >> cols;

	int** arr = Allocate(rows, cols);
	cout << "Memory allocated" << endl;
	system("PAUSE");

	arr = push_row_back(arr, rows, cols);
	cout << "Row added" << endl;
	system("PAUSE");

	Clear(arr, rows);
	cout << "Memory clean" << endl;

#endif // PREFORMANCE_CHECK

}

int** Allocate(const int rows, const int cols)
{
	//1 создаем массив указателей
	int** arr = new int* [rows];
	//2  выделяем память под строки
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


void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//Обращение к эл-там через арифметику указателя и и оператор разыменования
		arr [i] = rand() % (maxRand - minRand) + minRand;
	}
	
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

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{

		cout << arr[i] << tab;

	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

int* push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];// создаем буфферный массив нужного размера
	//2)Копируем значения исходного массива в буфферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив
	delete[] arr;
	//4) Подменяем адрес исходного массива адресом нового массива:
	arr = buffer;
	//5) Только после этого в конец массива появляется свободное место, 
	// куда можно добаавить значение:
	arr[n] = value;
	n++;
	//Print(arr, n);
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	//3) Удаляем исходный массив
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив
	delete[] arr;
	return buffer;
}
int* insert(int* arr, int& n, int index, int value)
{
	int* buffer = new int[n + 1];
	buffer[index] = value;
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}

int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0 ; i <= n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	return buffer;
}
int* erase(int* arr, int& n, int index, int value)
{
	int* buffer = new int[--n];
	buffer[index] = value;
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index+1; i <= n; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	//1 создаем буферный массив указателей нужного размера
	int** buffer = new int* [rows+1];

	//2  копируем строки из исх массива указателей
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	
	//3 Удаляем исх массив указателей
	delete[] arr;

	//4 создаем строку и добавляем ее в массив
	buffer[rows] = new int[cols] {};//строка new int на [cols] элементов

	//5 После добавления строки в массив, количество его строк увеличивается
	
	rows++;
	return buffer;

}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	
	//2 Переопределяем массив указателей
	int** buffer = new int*[--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr[rows]; //1 Удаляем строку из памяти
	delete[] arr;
	return buffer;
}
int** push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//создаем буферную строку
		int* buffer = new int[cols + 1] {};
		//копируем значения из исх строки в буферную
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		// удаляем исходную строку
		delete[] arr[i];
		// подменяем адрес строки в массиве указателей:
		arr[i] = buffer;

	}
	cols++;
	return arr;

}