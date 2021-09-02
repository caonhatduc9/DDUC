#include"function.h"
#include<iostream>
using namespace std;
int main()
{
	int* a, n, * b;
	inputarray(a, n);
	cout << "mang a\n";
	outputArray(a, n);
	arrayClone(a, n, b);
	cout << "\nmang b\n";
	outputArray(b, n*2);
	return 0;
}