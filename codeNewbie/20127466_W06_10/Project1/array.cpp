#include"array.h"
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

float TBC(int a[], int n)
{
	double sum = 0;
	double count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			sum = sum + a[i];
			count++;
		}
	}
	if (count == 0)
		cout << "nhap lai\n";
	else
		cout << sum / count << endl;
	return 0;
}

bool kiemtraprime(int n)
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

int inprime(int a[], int n)
{
	for (int i = 0; i <= n; i++)
	{
		if (kiemtraprime(a[i]) == 1)
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}

int evenmax(int a[], int n)
{
	int i, k;
	int max = 1;
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			max = a[i];
			k = i + 1;
			break;
		}
	}
	if (max == 1)
		cout << "khong co so chan\n";
	else 
		for (k; k < n; k++)
	{
		if ((a[k] >= max) && (a[k] % 2 == 0))
		{
			max = a[k];
		}
	}
	return max;
}

int oddmin(int a[], int n)
{
	int i, k;
	int min = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			min = a[i];
			k = i + 1;
			break;
		}
	}
	if (min == 0)
		cout << "khong co so le\n";
	else
		for (k; k < n; k++)
		{
			if ((a[k] <= min) && (a[k] % 2 != 0))
			{
				min = a[k];
			}
		}
	return min;
}


bool ktgiam(int a[], int n)
{
		for (int i = 1; i < n; i++)
		{
			if (a[i-1] < a[i])
				return 0;
		}
		return 1;
	}

	bool kttang(int a[], int n)
	{
		for (int i = 1; i < n; i++)
		{
			if (a[i-1] > a[i])
				return 0;
		}
		return 1;
	}

	void kiemtratanggiam(int a[], int n)
	{
		if (n == 1)
			cout << "nhap lai\n";
		else
		{
			if (kttang(a, n))
				cout << "tang\n";
			else if (ktgiam(a, n))
			{
				cout << "giam\n";
			}
			else
				cout << "khong tang khong giam\n";
		}
	}

void demsokhacnhau(int a[], int n)
{
	int count = 1;
	
	for (int i = 1; i < n; i++)
	{
		int temp = 69;
		for (int j = 0; j < i; j++)
		{
			if (a[j] == a[i])
			{
				temp = 0;
				break;
			}
		}
		if (temp != 0)
			count++;
	}
	cout << count << endl;
}

void hoandoi(int &a, int &b)
{
	int k = a;
	a = b;
	b = k;
}
void secondmax(int a[], int n)
{
	if (n == 1)
		cout << "nhap lai\n";
	else
	{
		int j;
		for (int i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (a[i] < a[j])
					hoandoi(a[i], a[j]);
			}
		}
		cout << a[1]<<endl;
	}
}

void demprime(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (kiemtraprime(a[i]))
			count++;
	}
	if (count == 0)
		cout << "khong he co so nguyen to nao het tron\n";
	else
		cout << count << endl;
}

void kiemtraphantumangacotrongmangb(int a[], int b[], int n)
{
	int test = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i] == b[j])
				{
					cout << " " << a[i];
					test = 1;
				}
			}
		}
		if (test == 0)
		{
			cout << "khong co gia tri nao\n";
		}
}

void sumequalo(int a[], int b[], int n)
{
	int test = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] + b[j] == 0)
			{
				cout << " " << "(" << i << "," << " " << j << ")";
				test = 1;
			}
		}
	}
	if (test == 0)
		cout << "khong co gia tri\n";
}

int checktichmax(int a[],int n)
{
	int max = a[0] * a[1];
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (a[i] * a[j] > max)
					max = a[i] * a[j];
			}
		}
	}
	return max;
}
void tichmax(int a[], int n)
{
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] * a[j] == checktichmax(a, n));
			cout << " " << "(" << a[i] << ", " << a[j] << ")";
		}
	}
}
