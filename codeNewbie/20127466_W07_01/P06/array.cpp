#include"array.h"
#define array_h
#include<iostream>
using namespace std;

void input(int a[], int& n)
{
	cout << "nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " " << a[i];
	}
}

int kiemTraPrime(int n)
{
	if (n < 2)
	{
		return 0;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return 0;
	}

	return 1;
}

void hoanDoi(int &a, int &b)
{
	int k = a;
	a = b;
	b = k;
}

void sapXepPrime(int a[], int n)
{
	
	for (int i = 0; i < n - 1; i++)
	{
		if (kiemTraPrime(a[i]) == 1)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] > a[j] && kiemTraPrime(a[j]) == 1 )
					hoanDoi(a[i], a[j]);
			}
		}
	}
}
