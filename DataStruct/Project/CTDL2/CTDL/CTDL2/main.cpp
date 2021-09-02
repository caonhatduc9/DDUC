#include"DataGenerator.h"
#include<time.h>
#include<iostream>
using namespace std;

int insertion_sort(int*& a, int n)
{
	int v, j;
	long long count_compare = 0;

	for (int i = 1; ++count_compare && i < n; i++)
	{
		v = a[i];
		j = i - 1;
		while (++count_compare && j >= 0 && a[j] > v) {
			a[j + 1] = a[j]; j--;
		}
		a[j + 1] = v;
	}
	return count_compare;
}
int selection_sort(int*& a, int n)
{
	unsigned long long count_compare = 0;
	int minidx, minval;
	for (int i = 0; ++count_compare && i < n - 1; i++)
	{
		minidx = i;
		minval = a[i];
		for (int j = i + 1; ++count_compare && j < n; j++)
			if (a[j] < minval)
			{
				minidx = j;
				minval = a[j];
			}
		a[minidx] = a[i];
		a[i] = minval;
	}
	return count_compare;
}

int  binary_insertion_sort(int*& a, int n)
{
	int left, right, m, i;
	int x;
	unsigned long long count_compare = 0;
	for (int i = 1; ++count_compare && i < n; i++)
	{
		x = a[i]; left = 0;
		right = i - 1;
		while (++count_compare && left <= right)
		{
			m = (left + right) / 2;
			if (++count_compare && x < a[m]) right = m - 1;
			else left = m + 1;
		}
		for (int j = i - 1; ++count_compare && j >= left; j--)
			a[j + 1] = a[j];
		a[left] = x;
	}
	return count_compare;
}
int main()
{

	int* a;
	int s;
	int size[6] = { 10000,30000,50000,100000,300000,500000 };//size data
	string Data_Order[4] = { "RandomData","SortedData","ReverseData","NearlySortedData" };//data order 
	unsigned long long count_compare = 0;
	while (1) {
		cout << "choice size:\n1_10000\n2_30000\n3_50000\n4_100000\n5_300000\n6_500000 ";
		cout << "\nchoice: ";
		cin >> s;

		if (s <= 6) {
			a = new int[size[s - 1]];
			clock_t t1, t2;
			for (int i = 0; i < 4; i++)
			{
				count_compare = 0;
				GenerateData(a, size[s - 1], i);
				t1 = clock();
				count_compare = insertion_sort(a, size[s - 1]);
				t2 = clock();
				cout << "Sorting Algorithm: insertion" << endl;
				cout << "Data order: " << Data_Order[i] << endl;
				cout << "Data size: " << size[s - 1] << endl;
				cout << "Time running: " << t2 - t1 << endl;
				cout << "count compare: " << count_compare << endl << endl;

				count_compare = 0;
				GenerateData(a, size[s - 1], i);
				t1 = clock();
				count_compare = binary_insertion_sort(a, size[s - 1]);
				t2 = clock();
				cout << "Sorting Algorithm: binary insertion" << endl;
				cout << "Data order: " << Data_Order[i] << endl;
				cout << "Data size: " << size[s - 1] << endl;
				cout << "Time running: " << t2 - t1 << endl;
				cout << "count compare: " << count_compare << endl << endl;
				count_compare = 0;

				count_compare = 0;
				GenerateData(a, size[s - 1], i);
				t1 = clock();
				count_compare = selection_sort(a, size[s - 1]);
				t2 = clock();
				cout << "Sorting Algorithm: selection_sort" << endl;
				cout << "Data order: " << Data_Order[i] << endl;
				cout << "Data size: " << size[s - 1] << endl;
				cout << "Time running: " << t2 - t1 << endl;
				cout << "count compare: " << count_compare << endl << endl;

			}
		}
	}
}

	