//References
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void Exchange(int& a, int& b);

void main()
{
	setlocale(LC_ALL, "");

	int a = 2;
	int b = 3;
	/*nt& ra = a;
	ra += 3;
	cout << a << endl;
	cout << &a << endl;
	cout << &ra << endl*/;
	cout << a << "\t" << b << endl;
	Exchange( a, b);
	cout << a <<"\t" <<b<< endl;
	
}
void Exchange(int& a, int& b)
{
	int buffer = a;
	a = b;
	b = buffer;
}