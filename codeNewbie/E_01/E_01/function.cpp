#include"function.h"
#include<iostream>
using namespace std;

void input(PS*& a, int& n)
{
	cout << "\nnhap n: ";
	cin >> n;
	a = new PS[n];
	for (int i = 0; i < n; i++)
	{
		cout << "nhap tu: ";
			cin >> a[i].tu;
		cout << "nhap mau: ";
		cin >> a[i].mau;

	}
}


void output(PS* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i].tu << "/" << a[i].mau << endl;
}


void extractN(PS* a, int n, PS*& b, int& m)
{

	for (int i = 0; i < n; i++)
	{
		if (a[i].tu * a[i].mau < 0)
			m++;
	}
	int count = 0;
		b = new PS[m];
		for (int i = 0; i < n; i++)
		{
			if (a[i].tu * a[i].mau < 0)
			{
				b[count++] = a[i];
			}
		}
	
}