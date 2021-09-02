#include"function.h"
#include<iostream>
using namespace std;
void inputarray(int*& a, int& n)
{
	cout << "items? : ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]\t";
		cin >> *(a + i);
	}
}
void outputArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a + i) << "\t";
}
void arrayClone(int*& a, int n, int*& b)
{
	b = new int[n * 2];
	for (int i = 0; i < n*2; i++)
	{
		if (i >= n)
			b[i] = 0;
		else
		b[i] = a[i];
	}
}