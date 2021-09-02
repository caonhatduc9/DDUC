#include<iostream>
#include<time.h>
using namespace std;

//sap xep noi bot
void printa(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void nhapMangrand(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = 0 + rand() % n;
}
void nhapMangTheoTT(int a[], int n) {
	for (int i = 0; i < n; i++)
		a[i] = i;
}
void nhapMangNguoc(int a[], int n) {
	for (int i = 0; i < n; i++)
		a[i] = (n - i - 1);
}
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
}
void bubbleSort2(int a[], int n)
{
	int l = 1, k = n-1, r = n-1;
	do {
		for (int j = r; j >= l; j--)
			if (a[j - 1] > a[j])
			{
				int t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t; 
				k = j;
			}
		l = k + 1;
		for (int j = l; j <= r; j++)
			if (a[j - 1] > a[j])
			{
				int t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t; k = j;
			}
		r = k - 1;
	} 	while (l <= r);
}
//sap xep chon
void selectionSort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}
void selectionSort2(int a[], int n)

{
	int minidx, minval;
	for (int i = 0; i < n -1; i++)
	{
		 minidx = i;
		 minval = a[i];
		 for (int j = i + 1; j < n; j++)
			 if (a[j] < minval)
			 {
				 minidx = j;
				 minval = a[j];
			 }
			 a[minidx] = a[i];
			 a[i] = minval;
	}
}
void insertSort(int a[], int n)
{
	int pos = 0, x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		for (pos = i; pos > 0 && a[pos - 1] > x; pos--) {
			a[pos] = a[pos - 1];
		}
		a[pos] = x;
	}
}
void insertSort2(int a[], int n)
{
	int v, j;
	for (int i = 1; i < n; i++)
	{
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {// đây là 
			a[j + 1] = a[j]; j--;
		}
		a[j + 1] = v;
	}
}
// sap xep quicksort
void quickSort(int a[], int n)
{

}
int main()
{
	clock_t t1, t2;
	double d;
	int a[100000], b[100000];
	nhapMangNguoc(a, 100000);
	for (int i = 0; i < 100000; i++)
		b[i] = a[i];
	//printa(a, 20);
	

//	cout << CLOCKS_PER_SEC;
	//printa(a, 100);
	/*t1 = clock();
	bubbleSort(a, 10000);
	t2 = clock();
	cout << "\ntime bub: " << (float)(t2 - t1) / CLOCKS_PER_SEC;
	t1 = clock();
	bubbleSort2(b, 10000);
	t2 = clock();
	cout << "\ntime bub 2: " << (float)(t2 - t1) / CLOCKS_PER_SEC;*/
	/*t1 = clock();
	selectionSort2(a, 30000);
	t2 = clock();
	cout << "\ntime insert2: " << (float)(t2 - t1) / CLOCKS_PER_SEC;
	printa(a, 15);
	t1 = clock();
	selectionSort(b, 30000);
	t2 = clock();
	cout << "\ntime insert: " << (float)(t2 - t1) / CLOCKS_PER_SEC;
	*/
	insertSort2(a, 10);
	printa(a, 10);
//	for (int i = 1; i <= 9; i++)
	//	cout << b[i] << "\t";
	return 0;
}