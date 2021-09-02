#include"function4.h"
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
int modeOfArray(int* a, int n)
{
	int* extra = new int[n], max = 0, mode = *a;

	for (int i = 0; i < n; i++)
		*(extra + i) = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = i+1; j < n; j++)
			if (*(a + i) == *(a + j))
				*(extra + i) = *(extra + i) + 1;

	for (int k = 0; k < n; k++)
		if (max < *(extra + k))
		{
			max = *(extra + k);
			mode = *(a + k);
		}
	
	delete[] extra;
	delete[] a;
	if (max == 0)
	{
		return -1;
	}
	return mode;
}

