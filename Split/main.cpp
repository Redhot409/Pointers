//Split
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);
	// 1) Вычисляем кол-во четных и нечетных элементов:
	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0)even_count++;else odd_count++;
		arr[i] % 2 == 0 ? even_count++ : odd_count++;//тернарник
	}
	cout << "Количество четных элементов: " << even_count << endl;
	cout << "Количество нечетных элементов: " << odd_count << endl;

	// 2) Выделяем память для массивов
	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	// 3) Копируем четные и нечетные элементы в соответствующие массивы:
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		//else odd_arr[k++] = arr[i]; эти две строки равны нижней следующей:
		//(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
		(arr[i] % 2 ? odd_arr[k++] : even_arr[j++]) = arr[i];
	}
	//4) Вывод результатов:
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);

	// 5) Удаление массивов:
	 delete[] odd_arr; 
	 delete[] odd_arr; 
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
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