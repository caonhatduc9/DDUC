#include "AllOfFunction.h"
using namespace std;

double timeBubbleSort(int *arr, int n)
{
	clock_t start, end;
	double elapsed;

	start = clock();
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				HoanVi(arr[j], arr[j - 1]);
			}
		}
	}
	end = clock();

	elapsed = (double)(end - start);
	return elapsed;
}

double timeHeapSort(int *arr, int n)
{
	clock_t start, end;
	double elapsed;

	start = clock();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		HoanVi(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
	end = clock();

	elapsed = (double)(end - start);
	return elapsed;
}

double timeInsertionSort(int *arr, int n)
{
	clock_t start, end;
	double elapsed;

	start = clock();
	int v, j;

	for (int i = 1; i < n; i++)
	{
		v = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > v)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
	}
	end = clock();

	elapsed = (double)(end - start);
	return elapsed;
}

double timeSelectionSort(int *arr, int n)
{
	clock_t start, end;
	double elapsed;

	start = clock();
	int minidx, minval;

	for (int i = 0; i < n - 1; i++)
	{
		minidx = i;
		minval = arr[i];
		for (int j = i + 1; j < n; j++)
			if (arr[j] < minval)
			{
				minidx = j;
				minval = arr[j];
			}
		arr[minidx] = arr[i];
		arr[i] = minval;
	}
	end = clock();

	elapsed = (double)(end - start);
	return elapsed;
}

double timeBinaryInsertionSort(int *arr, int n)
{
	clock_t start, end;
	double elapsed;

	start = clock();
	int left, right, m, i;
	int x;

	for (int i = 1; i < n; i++)
	{
		x = arr[i];
		left = 0;
		right = i - 1;
		while (left <= right)
		{
			m = (left + right) / 2;
			if (x < arr[m])
				right = m - 1;
			else
				left = m + 1;
		}
		for (int j = i - 1; j >= left; j--)
			arr[j + 1] = arr[j];
		arr[left] = x;
	}
	end = clock();

	elapsed = (double)(end - start);
	return elapsed;
}

double timeQuickSort(int *arr, int n, int left, int right)
{
	clock_t start, end;
	double elapsed;

	start = clock();
	if (left < right)
	{
		int p = arr[left];
		int i = left;
		int j = right + 1;
		do
		{
			do
			{
				i++;
			} while (arr[i] < p);

			do
			{
				j--;
			} while (arr[j] > p);

			HoanVi(arr[i], arr[j]);
		} while (i < j);

		HoanVi(arr[i], arr[j]);
		HoanVi(arr[left], arr[j]);

		quickSort(arr, n, left, j - 1);
		quickSort(arr, n, j + 1, right);
	}
	end = clock();

	elapsed = (double)(end - start);
	return elapsed;
}

double timeMergeSort(int *arr, int l, int r)
{
	clock_t start, end;
	double elapsed;
	start = clock();
	if (l >= r)
	{
		exit(0);
	}
	int m = (l + r - 1) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
	end = clock();
	elapsed = (double)(end - start);
	return elapsed;
}

double timeRadixSort(int *arr, int size)
{
	clock_t start, end;
	double elapsed;
	start = clock();
	int max = getMax(arr, size);

	for (int place = 1; max / place > 0; place *= 10)
	{
		countingSort(arr, size, place);
	}
	end = clock();
	elapsed = (double)(end - start);
	return elapsed;
}