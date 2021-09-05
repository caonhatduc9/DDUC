#include "AllOfFunction.h"
using namespace std;

long long countBubbleSort(int *arr, int n, long long &count_compare)
{
	for (int i = 1; ++count_compare && i <= n - 1; i++)
	{
		for (int j = n - 1; ++count_compare && j >= i; j--)
		{
			if (++count_compare && arr[j] < arr[j - 1])
			{
				HoanVi(arr[j], arr[j - 1]);
			}
		}
	}
	return count_compare;
}

long long countHeapify(int *arr, int n, int i, long long &count_compare)
{
	int largest = i;   
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (++count_compare && l < n && ++count_compare && arr[l] > arr[largest])
		largest = l;

	if (++count_compare && r < n && ++count_compare && arr[r] > arr[largest])
		largest = r;

	if (++count_compare && largest != i)
	{
		HoanVi(arr[i], arr[largest]);
		countHeapify(arr, n, largest, count_compare);
	}
	return count_compare;
}

long long countHeapSort(int *arr, int n, long long &count_compare)
{
	for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
		countHeapify(arr, n, i, count_compare);

	for (int i = n - 1; i > 0; i--)
	{
		HoanVi(arr[0], arr[i]);

		countHeapify(arr, i, 0, count_compare);
	}
	return count_compare;
}

long long countInsertionSort(int *arr, int n, long long &count_compare)
{
	int v, j;

	for (int i = 1; ++count_compare && i < n; i++)
	{
		v = arr[i];
		j = i - 1;
		while (++count_compare && j >= 0 && ++count_compare && arr[j] > v)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
	}
	return count_compare;
}

long long countSelectionSort(int *arr, int n, long long &count_compare)
{
	int minidx, minval;
	for (int i = 0; ++count_compare && i < n - 1; i++)
	{
		minidx = i;
		minval = arr[i];
		for (int j = i + 1; ++count_compare && j < n; j++)
			if (++count_compare && arr[j] < minval)
			{
				minidx = j;
				minval = arr[j];
			}
		arr[minidx] = arr[i];
		arr[i] = minval;
	}
	return count_compare;
}

long long countBinaryInsertionSort(int *arr, int n, long long &count_compare)
{
	int left, right, m, i;
	int x;

	for (int i = 1; ++count_compare && i < n; i++)
	{
		x = arr[i];
		left = 0;
		right = i - 1;
		while (++count_compare && left <= right)
		{
			m = (left + right) / 2;
			if (++count_compare && x < arr[m])
				right = m - 1;
			else
				left = m + 1;
		}
		for (int j = i - 1; ++count_compare && j >= left; j--)
			arr[j + 1] = arr[j];
		arr[left] = x;
	}
	return count_compare;
}

long long countQuickSort(int *arr, int n, int left, int right, long long &count_compare)
{
	int p = arr[left];
	int i = left;
	int j = right + 1;
	do
	{
		do
		{
			i++;
		} while (++count_compare && arr[i] < p);
		do
		{
			j--;
		} while (++count_compare && arr[j] > p);

		HoanVi(arr[i], arr[j]);
	} while (++count_compare && i < j);

	HoanVi(arr[i], arr[j]);
	HoanVi(arr[left], arr[j]);

	if (++count_compare && left < right)
	{
		countQuickSort(arr, n, left, j - 1, count_compare);
		countQuickSort(arr, n, j + 1, right, count_compare);
	}
	return count_compare;
}

long long countMerge(int *arr, int l, int m, int r, long long &count_compare)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L = new int[n1];
	int *R = new int[n2];

	for (int i = 0; ++count_compare && i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; ++count_compare && j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0;

	int j = 0;

	int k = l;

	while (++count_compare && i < n1 && ++count_compare && j < n2)
	{
		if (++count_compare && L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (++count_compare && i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (++count_compare && j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	return count_compare;
	delete[] L;
	delete[] R;
}

long long countMergeSort(int *arr, int l, int r, long long &count_compare)
{
	if (++count_compare && l >= r)
	{
		int m = (l + r - 1) / 2;

		countMergeSort(arr, l, m, count_compare);
		countMergeSort(arr, m + 1, r, count_compare);

		countMerge(arr, l, m, r, count_compare);
	}
	return count_compare;
}

long long countRadixSort(int *arr, int n, long long &counting)
{
	int mx = arr[0];
	for (int i = 1; ++counting && i < n; i++)
		if (++counting && arr[i] > mx)
			mx = arr[i];

	for (int exp = 1; ++counting && mx / exp > 0; exp *= 10)
		countCountingSort(arr, n, exp, counting);
	return counting;
}
