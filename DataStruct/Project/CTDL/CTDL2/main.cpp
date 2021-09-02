//#include"DataGenerator.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0: // ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1: // có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2: // có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3: // gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
unsigned long long insertion_sort(int *&a, int n)
{
	int v, j;
	unsigned long long count_compare = 0;

	for (int i = 1; ++count_compare && i < n; i++)
	{
		v = a[i];
		j = i - 1;
		while (++count_compare && j >= 0 && ++count_compare && a[j] > v)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
	return count_compare;
}
unsigned long long selection_sort(int *&a, int n)
{
	unsigned long long count_compare = 0;
	int minidx, minval;
	for (int i = 0; ++count_compare && i < n - 1; i++)
	{
		minidx = i;
		minval = a[i];
		for (int j = i + 1; ++count_compare && j < n; j++)
			if (++count_compare && a[j] < minval)
			{
				minidx = j;
				minval = a[j];
			}
		a[minidx] = a[i];
		a[i] = minval;
	}
	return count_compare;
}
unsigned dummy_selection_sort(int *&a, int n)
{
	int i, j;
	unsigned long long count_compare = 0;
	for (int i = 0; ++count_compare && i < n - 1; i++)
		for (int j = i + 1; ++count_compare && j < n; j++)
			if (++count_compare && a[i] > a[j])
				swap(a[i], a[j]);
	return count_compare;
}

unsigned long long binary_insertion_sort(int *&a, int n)
{
	int left, right, m, i;
	int x;
	unsigned long long count_compare = 0;
	for (int i = 1; ++count_compare && i < n; i++)
	{
		x = a[i];
		left = 0;
		right = i - 1;
		while (++count_compare && left <= right)
		{
			m = (left + right) / 2;
			if (++count_compare && x < a[m])
				right = m - 1;
			else
				left = m + 1;
		}
		for (int j = i - 1; ++count_compare && j >= left; j--)
			a[j + 1] = a[j];
		a[left] = x;
	}
	return count_compare;
}
char *show_data_order(char *s)
{
	//char* temp = s;
	if (strcmp(s, "-rand") == 0)
		strcpy(s, "randomized data");
	if (strcmp(s, "-sorted") == 0)
		strcpy(s, "sorted data");
	if (strcmp(s, "-reverse") == 0)
		strcpy(s, "reverse sorted data");
	if (strcmp(s, "-nearlysorted") == 0)
		strcpy(s, "nearly sorted data");
	return s;
}

void loadFile(const char *path, int *&a, int &n)
{
	ifstream f;
	f.open(path);
	f >> n;
	a = new int[n];
	int idx = 0;
	while (!f.eof())
	{
		f >> a[idx++];
	}
	f.close();
}
int main(int argc, char *argv[])
{
	clock_t t_start, t_end;
	string temp;
	int *a = NULL;
	unsigned long long count_compare;
	if (argc == 4)
	{
		/* code */
	}
	//mode algorithm
	if (strcmp(argv[1], "-a") == 0)
	{
		if (argc == 6)
		{
			/*for (int i = 1; i < 6; i++)
			cout << argv[i] << endl;*/
			int size = atoi(argv[3]);

			int data_order;
			if (strcmp(argv[4], "-rand") == 0)
				data_order = 0;
			if (strcmp(argv[4], "-sorted") == 0)
				data_order = 1;
			if (strcmp(argv[4], "-rev") == 0)
				data_order = 2;
			if (strcmp(argv[4], "-nsorted") == 0)
				data_order = 3;

			a = new int[size];
			GenerateData(a, size, data_order);
			t_start = clock();
			if (strcmp(argv[2], "insertion-sort") == 0)
				count_compare = insertion_sort(a, size);
			if (strcmp(argv[2], "selection-sort") == 0)
				count_compare = selection_sort(a, size);
			if (strcmp(argv[2], "binary-insertion-sort") == 0)
				count_compare = binary_insertion_sort(a, size);
			if (strcmp(argv[2], "dummy-selection-sort") == 0)
				count_compare = dummy_selection_sort(a, size);
			/*	if (strcmp(argv[2], "insert-sort") == 0)
				cac thuat toan sort khac.....
		*/
			t_end = clock();
			cout << "ALGORITHM MODE";
			cout << "\nAlgrithm:     " << argv[2];
			cout << "\nInput size:   " << size;
			cout << "\nInput order:  " << show_data_order(argv[4]);
			cout << "\n-----------------------";
			if (strcmp(argv[5], "-both") == 0)
			{
				cout << "\nRunning time: " << t_end - t_start;
				cout << "\nComparisions: " << count_compare << endl;
			}
			if (strcmp(argv[5], "-time") == 0)
				cout << "\nRunning time: " << t_end - t_start << endl;
			if (strcmp(argv[5], "-comp") == 0)
				cout << "\nComparisions: " << count_compare << endl;
		}
		if (argc == 5)
		{
			int size = atoi(argv[3]);
			if (size != 0)
			{
				a = new int[size];
				char order[4][20];
				strcpy(order[0], "randomized data");
				strcpy(order[1], "sorted data");
				strcpy(order[2], "reverse sorted data");
				strcpy(order[3], "nearly sorted data");

				cout << "\nALGORITHM MODE";
				cout << "\nAlgrithm:     " << argv[2];
				cout << "\nInput size:   " << size << endl;
				for (int i = 0; i < 4; i++)
				{
					GenerateData(a, size, i);
					t_start = clock();
					if (strcmp(argv[2], "insertion-sort") == 0)
						count_compare = insertion_sort(a, size);
					if (strcmp(argv[2], "selection-sort") == 0)
						count_compare = selection_sort(a, size);
					if (strcmp(argv[2], "binary-insertion-sort") == 0)
						count_compare = binary_insertion_sort(a, size);
					if (strcmp(argv[2], "dummy-selection-sort") == 0)
						count_compare = dummy_selection_sort(a, size);
					t_end = clock();

					cout << "\nInput order:  " << order[i];
					cout << "\n--------------------";
					if (strcmp(argv[4], "-both") == 0)
					{
						cout << "\nRunning time: " << t_end - t_start;
						cout << "\nComparisions: " << count_compare << endl;
					}
					if (strcmp(argv[4], "-time") == 0)
						cout << "\nRunning time: " << t_end - t_start << endl;
					if (strcmp(argv[4], "-comp") == 0)
						cout << "\nComparisions: " << count_compare << endl;
				}
			}
			else
			{
				int n;
				loadFile(argv[3], a, n);
				for (int i = 0; i < 20; i++)
					cout << a[i] << " ";
				cout << "\nALGORITHM MODE";
				cout << "\nAlgrithm:     " << argv[2];
				cout << "\nInput size:   " << n;
				cout << "\n----------------";

				t_start = clock();
				if (strcmp(argv[2], "insertion-sort") == 0)
					count_compare = insertion_sort(a, n);
				if (strcmp(argv[2], "selection-sort") == 0)
					count_compare = selection_sort(a, n);
				if (strcmp(argv[2], "binary-insertion-sort") == 0)
					count_compare = binary_insertion_sort(a, n);
				if (strcmp(argv[2], "dummy-selection-sort") == 0)
					count_compare = dummy_selection_sort(a, n);
				t_end = clock();
				if (strcmp(argv[4], "-both") == 0)
				{
					cout << "\nRunning time: " << t_end - t_start;
					cout << "\nComparisions: " << count_compare << endl;
				}
				if (strcmp(argv[4], "-time") == 0)
					cout << "\nRunning time: " << t_end - t_start << endl;
				if (strcmp(argv[4], "-comp") == 0)
					cout << "\nComparisions: " << count_compare << endl;
			}
		}
	}
	//mode compare
	if (strcmp(argv[1], "-c") == 0)
	{
		if (argc == 6)
		{
			int t1, t2;
			int *b = NULL;
			unsigned long long c1 = 0, c2 = 0;
			int size = atoi(argv[4]);
			a = new int[size];
			int data_order;
			if (strcmp(argv[5], "-rand") == 0)
				data_order = 0;
			if (strcmp(argv[5], "-sorted") == 0)
				data_order = 1;
			if (strcmp(argv[5], "-rev") == 0)
				data_order = 2;
			if (strcmp(argv[5], "-nsorted") == 0)
				data_order = 3;
			cout << "\nCOMPARE MODE";
			cout << "\nAlgrithm: " << argv[2] << " | " << argv[3];
			cout << "\nInput size: " << size;
			cout << "\nInput order: " << show_data_order(argv[5]);
			cout << "\n----------------";

			GenerateData(a, size, data_order);
			t_start = clock();
			if (strcmp(argv[2], "insertion-sort") == 0)
				count_compare = insertion_sort(a, size);
			if (strcmp(argv[2], "selection-sort") == 0)
				count_compare = selection_sort(a, size);
			if (strcmp(argv[2], "binary-insertion-sort") == 0)
				count_compare = binary_insertion_sort(a, size);
			if (strcmp(argv[2], "dummy-selection-sort") == 0)
				count_compare = dummy_selection_sort(a, size);
			t_end = clock();
			t1 = t_end - t_start;
			c1 = count_compare;
			count_compare = 0;
			t_start = clock();
			GenerateData(a, size, data_order);
			if (strcmp(argv[3], "insertion-sort") == 0)
				count_compare = insertion_sort(a, size);
			if (strcmp(argv[3], "selection-sort") == 0)
				count_compare = selection_sort(a, size);
			if (strcmp(argv[3], "binary-insertion-sort") == 0)
				count_compare = binary_insertion_sort(a, size);
			if (strcmp(argv[3], "dummy-selection-sort") == 0)
				count_compare = dummy_selection_sort(a, size);
			t_end = clock();
			t2 = t_end - t_start;
			c2 = count_compare;
			cout << "\nRunning time: " << t1 << " | " << t2;
			cout << "\nComparisions: " << c1 << " | " << c2;
		}
		if (argc == 5)
		{
			///cmd 4
			
		}
	}
	return 0;
}
