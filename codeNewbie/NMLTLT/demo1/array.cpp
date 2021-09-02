#include"array.h"
#include<iostream>
using namespace std;

	void input(int a[], int &n)
	{
		cout << "nhap n: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "nhap a[" << i << "]: ";
			cin >> a[i];
		}
	}
	void xuatmang(int a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
	}

void bai174(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				cout << "(" << a[i] << "," << a[j] << ")\n";
			}
			else
				cout << "(" << a[j] << "," << a[i]<<")\n";

		}

	}
}

void bai230(int a[], int n)
{
		 for (int i = 0; i < n; i++)
		 {
			 int dem = 0;
			 for (int j = 0; j < n; j++) // j chạy từ 0
			 {
				 if (a[i] == a[j])
				 {
					 if (i <= j)
					 {
						 dem++;
					 }
					 else
					 {
						 break;    // bỏ qua phần tử bị trùng
					 }
				 }  
			 }
			 if (dem != 0)
			 {
				 cout << a[i] << " xuat hien " << dem << "  lan\n";
			 }
		 }
}

void hoanvi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void sapxetangdan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				hoanvi(a[i], a[j]);
		}
	}
}

