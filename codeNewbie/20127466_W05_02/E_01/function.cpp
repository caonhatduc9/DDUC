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

	for (int i = 0; i < n; i++) {
		cout << a[i].tu << "/" << a[i].mau << endl;
		
		
	}
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
PS operator+(PS a, PS b)
{
	PS c;
	c.tu = a.tu * b.mau + b.tu * a.mau;
	c.mau = a.mau * b.mau;
	return c;
}

int UCLN(int a,int b) {
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
void rutGon(float& a, float& b)
{
	float anew = a, bnew = b;
	a = a / UCLN(anew, bnew);
	b = b / UCLN(anew, bnew);
}
PS sumPos(PS* a, int n)
{
	PS c = { 0,1 };
	for (int i = 0; i < n; i++)
		if (a[i].tu * a[i].mau > 0)
			c = c + a[i];
	rutGon(c.tu, c.mau);
	return c;
}