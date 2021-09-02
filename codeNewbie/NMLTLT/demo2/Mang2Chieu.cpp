#include"Mang2Chieu.h"
#include<iostream>
using namespace std;
void inputRandom(int a[100][100], int& d, int& c)
{
	cout << "nhap dong: ";
	cin >> d;
	cout << "nhap cot: ";
	cin >> c;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
}

	void input(int a[100][100], int& d, int& c)
	{
		cout << "nhap dong: ";
		cin >> d;
		cout << "nhap cot: ";
		cin >> c;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> a[i][j];
			}
		}
	}

void output(int a[100][100], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl << endl << endl;
	}
}

int min(int a, int b)
{
	return a < b ? a:b;
}

int sum(int a[100][100], int n, int m)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			s = s + a[i][j];
		}
	}
	return s;
}

bool isprime(int n)
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

int checkPrimeMaTran(int a[100][100], int n, int m)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (isprime(a[i][j]))
				dem++;
		}
	}
	return dem;
}

int sumDong(int a[100][100], int n, int m, int k)
{
	int s = 0;
	for (int i = 0; i < m; i++)
	{
		s = s + a[k][i];
	}
	return s;
}

int  tinhTongTungDong(int a[100][100], int n, int m)
{
	int tong, i;
	cout << "nhap dong can tinh";
	cin >> i;
		tong = sumDong(a, n, m, i);
	return tong;
}

void xuatTheoDong(int a[][100], int d, int c)
{
	cout << "\n nhap so dong\t ";
	int k;
	cin >> k;
	for (int i = 0; i < c; i++)
	{
		cout << a[k][i] << "\t";
	}
}

void xuatTheoCot(int a[][100], int n, int d, int c)
{
	cout << "\n nhap cot\t";
	int k;
	cin >> k;
	for (int i = 0; i < d; i++)
	{
		cout << a[i][k] << "\n";
	}
}

void tinhTongBien(int a[][100], int d, int c)
{
	int s = 0;
	for (int i = 0; i < c; i++)
	{
		s = s + a[0][i];
		s = s + a[d - 1][i];
	}
	for (int i = 1; i < d-1; i++)
	{
		s = s + a[i][0];
		s = s + a[i][c - 1];
	}
	cout << s;
}

//B342 dem phan tu cuc dai
int b342(int A[][100], int N, int M)
{
	int dx[8] = { -1,-1, -1,  0,0, 1,1,1 };
	int dy[8] = { -1, 0,  1, -1,1,-1,0,1 };

	int Dem = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int flag = 1;//gia su dung
			for (int k = 0; k < 8; k++)
			{
				if (i + dx[k] >= 0 && i + dx[k] < N && j + dy[k] >= 0 && j + dy[k] < M)
				{
					if (A[i][j] <= A[i + dx[k]][j + dy[k]])
					{
						flag = 0;
						break;
					}
				}
			}
			if (flag == 1)
			{
				Dem++;
			}
		}
	}
	return Dem;
}


void bai344_2(int a[100][100], int d, int c)
{
	int dem = 0;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int flag = 0;
			for (int d = 0; d < i * c + j; d++)
			{
				if (a[i][j] == a[d / c][d % c])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				dem++;
			}
		}
	}
	cout << dem;
}

//bai346
void bai346(int a[][100], int d, int c)
{
	int dem = 0;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int flag = 1;//gia su hh
			//xet dong
			for (int k = 0; k < c; k++)
			{
				if (a[i][j] <= a[i][k] && j != k)
				{
					flag = 0;
					break;
				}
			}
			//xet cot
			for (int k = 0; k < d; k++ && i != k);
			{
				if (a[i][j])  
				{
					flag = 0;
					break;
				}
			}
			//xet cheo chinh tren
			for (int k = 1; k < min(i, j); k++)
			{
				if (a[i][j] <= a[i-k][j-k])
				{
					flag = 0;
					break;
				}
			}
			//xet cheo chinh duoi
			for (int k = 1; k < min(d-1-i,c-1-i); k++)
			{
				if (a[i][j] <= a[i+k][j+k])
				{
					flag = 0;
					break;
				}
			}
		}
	}
}

void daoMaTran(int a[][100], int d, int c)
{
	for (int i = 0; i < d / 2; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int cc = a[i][j];
			a[i][j] = a[d - i - 1][j];
			a[d - i - 1][j] = cc;
		}
	}
}

void daoCot(int a[][100], int d, int c)
{
	for (int i = 0; i < d ; i++)
	{
		for (int j = 0; j < c/2; j++)
		{
			int cc = a[i][j];
			a[i][j] = a[i][c - j - 1];
			a[i][c - j - 1] = cc;
		}
	}

}

void rotateR(int a[][100], int d, int c, int b[][100], int& db, int& cb)
{
	int id, ic;
	cb = d, db = c;
	for (ic = c - 1; ic >= 0; ic--)
	{
		for (id = 0; id < d; id++)
		{
			b[c - 1 - ic][id] = a[id][ic];
		}
	}
}