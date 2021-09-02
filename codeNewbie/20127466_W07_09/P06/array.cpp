#include"array.h"

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

void gopMang(int a[], int n1, int b[], int n2, int c[], int& n3)
{
	n3 = n1;
	for (int i = 0; i < n3; i++)
	{
		c[i] = a[i];
	}
	n3 = n3 + n2;
	for (int i = n3 - n2; i < n3; i++)
		c[i] = b[i - (n3 - n2)];
	for (int i = 0; i < n3 - 1; i++)
	{
		for (int j = i + 1; j < n3; j++)
		{
			if (c[i] > c[j])
				hoanDoi(c[i], c[j]);
		}
	}
}

void insertX(int a[], int& n)
{
	int x, k;
	cout << "nhap x: ";
	cin >> x;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				hoanDoi(a[i], a[j]);
		}
	}
	if (x <= a[n - 1])
	{
		for (int i = 0; i < n; i++)
		{
			if (x <= a[i])
			{
				for (int j = n; j >= i + 1; j--)
				{
					a[j] = a[j - 1];
				}
				n++;
				a[i] = x;
				break;
			}
		}
	}
	else
	{
		n++;
		a[n - 1] = x;
	}
}

void del(int a[], int &n, int k)
{
	for (int i = k ; i < n - 1; i++)
	{
		a[i] = a[i+1];
	}
	n--;
}

void delDup(int a[], int &n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				del(a, n, j);
				i--;
			}
			
		}
	}
}

void tachMaxSangMangb(int a[], int n, int b[], int &n2)
{
	n2 = 0;
	for (int i = 1; i < n-1 ; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
		{
			b[n2] = a[i];
			n2++;
		}
	}
	if (n2 == 0)
		cout << "khong co so thoa man:\n";
	else
	{
		cout << "xuat mang b: ";
		output(b, n2);
	}
}


