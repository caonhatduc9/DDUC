#include <iostream>
#include <time.h>
#include <cmath>
#include<string>
#include<string.h>
#include <fstream>

template <class T>
void HoanVi(T& arr, T& b);

//! Generate Data---------------------------------------------
void GenerateRandomData(int* arr, int n);
void GenerateSortedData(int* arr, int n);
void GenerateReverseData(int* arr, int n);
void GenerateNearlySortedData(int* arr, int n);
void GenerateData(int* arr, int n, int dataType);

//!All of sorting functions-----------------------------------

void bubbleSort(int* arr, int n);
void heapify(int* arr, int n, int i);
void heapSort(int* arr, int n);
void insertionSort(int* arr, int n);
void selectionSort(int* arr, int n);
void binaryInsertionSort(int* arr, int n);
void quickSort(int* arr, int n, int left, int right);
void merge(int* arr, int l, int m, int r);
void mergeSort(int* arr, int l, int r);
int getMax(int arr[], int n);
void countingSort(int* arr, int size, int place);
void radixSort(int* arr, int size);

//!Counting comparisons in sorting algorithms-------------------

long long countBubbleSort(int* arr, int n, long long& count_compare);
long long countHeapify(int* arr, int n, int i, long long& count_compare);
long long countHeapSort(int* arr, int n, long long& count_compare);
long long countInsertionSort(int* arr, int n, long long& count_compare);
long long countSelectionSort(int* arr, int n, long long& count_compare);
long long countBinaryInsertionSort(int* arr, int n, long long& count_compare);
long long countQuickSort(int* arr, int n, int left, int right, long long& count_compare);
long long countMerge(int* arr, int l, int m, int r, long long& count_compare);
long long countMergeSort(int* arr, int l, int r, long long& count_compare);
long long countCountingSort(int* arr, int n, int exp, long long& counting);
long long countRadixSort(int* arr, int n, long long& counting);

//!Counting time in sorting algorithms---------------------------

double timeBubbleSort(int* arr, int n);
double timeHeapSort(int* arr, int n);
double timeInsertionSort(int* arr, int n);
double timeSelectionSort(int* arr, int n);
double timeBinaryInsertionSort(int* arr, int n);
double timeQuickSort(int* arr, int n, int left, int right);
double timeMergeSort(int* arr, int l, int r);
double timeRadixSort(int* arr, int size);




double timeBubbleSort(int* arr, int n) {
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
	elapsed = (double)(end - start) / CLOCKS_PER_SEC;
	return elapsed;
}

double timeHeapSort(int* arr, int n) {
	clock_t start, end;
	double elapsed;

	start = clock();
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end
		HoanVi(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
	end = clock();
	elapsed = ((double)(end - start) / CLOCKS_PER_SEC);
	return elapsed;
}
double timeInsertionSort(int* arr, int n) {
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

	elapsed = ((double)(end - start) / CLOCKS_PER_SEC);
	return elapsed;
}
double timeSelectionSort(int* arr, int n) {
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

	elapsed = ((double)(end - start) / CLOCKS_PER_SEC);
	return elapsed;
}
double timeBinaryInsertionSort(int* arr, int n) {
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
	elapsed = ((double)(end - start) / CLOCKS_PER_SEC);
	return elapsed;
}
double timeQuickSort(int* arr, int n, int left, int right) {
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

		// ! Recursion
		quickSort(arr, n, left, j - 1);
		quickSort(arr, n, j + 1, right);
	}
	end = clock();

	elapsed = ((double)(end - start) / CLOCKS_PER_SEC);
	return elapsed;
}

double timeMergeSort(int* arr, int l, int r) {
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
	elapsed = ((double)(end - start) / CLOCKS_PER_SEC);
	return elapsed;
}

double timeRadixSort(int* arr, int size) {
	clock_t start, end;
	double elapsed;
	start = clock();
	int max = getMax(arr, size);

	for (int place = 1; max / place > 0; place *= 10)
	{
		countingSort(arr, size, place);
	}
	end = clock();
	elapsed = ((double)(end - start) / CLOCKS_PER_SEC);
	return elapsed;
}
long long countBubbleSort(int* arr, int n, long long& count_compare) {
	for (int i = 1; ++count_compare && i <= n - 1; i++) {
		for (int j = n - 1; ++count_compare && j >= i; j--) {
			if (++count_compare && arr[j] < arr[j - 1]) {
				HoanVi(arr[j], arr[j - 1]);
			}
		}
	}
	return count_compare;
}

long long countHeapify(int* arr, int n, int i, long long& count_compare) {
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (++count_compare && l < n && ++count_compare && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (++count_compare && r < n && ++count_compare && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (++count_compare && largest != i)
	{
		HoanVi(arr[i], arr[largest]);
		countHeapify(arr, n, largest, count_compare);
	}
	return count_compare;
}

long long countHeapSort(int* arr, int n, long long& count_compare) {
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
		countHeapify(arr, n, i, count_compare);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end
		HoanVi(arr[0], arr[i]);

		// call max heapify on the reduced heap
		countHeapify(arr, i, 0, count_compare);
	}
	return count_compare;
}

long long countInsertionSort(int* arr, int n, long long& count_compare) {
	int v, j;

	for (int i = 1; ++count_compare && i < n; i++)
	{
		v = arr[i];
		j = i - 1;
		while (++count_compare && j >= 0 && ++count_compare && arr[j] > v) {
			arr[j + 1] = arr[j]; j--;
		}
		arr[j + 1] = v;
	}
	return count_compare;
}

long long countSelectionSort(int* arr, int n, long long& count_compare) {
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

long long countBinaryInsertionSort(int* arr, int n, long long& count_compare) {
	int left, right, m, i;
	int x;

	for (int i = 1; ++count_compare && i < n; i++)
	{
		x = arr[i]; left = 0;
		right = i - 1;
		while (++count_compare && left <= right)
		{
			m = (left + right) / 2;
			if (++count_compare && x < arr[m]) right = m - 1;
			else left = m + 1;
		}
		for (int j = i - 1; ++count_compare && j >= left; j--)
			arr[j + 1] = arr[j];
		arr[left] = x;
	}
	return count_compare;
}

long long countQuickSort(int* arr, int n, int left, int right, long long& count_compare) {
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
		// ! Recursion
		countQuickSort(arr, n, left, j - 1, count_compare);
		countQuickSort(arr, n, j + 1, right, count_compare);
	}
	return count_compare;
}

long long countMerge(int* arr, int l, int m, int r, long long& count_compare) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; ++count_compare && i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; ++count_compare && j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0;

	int j = 0;

	int k = l;

	while (++count_compare && i < n1 && ++count_compare && j < n2) {
		if (++count_compare && L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (++count_compare && i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (++count_compare && j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	return count_compare;
	delete[] L;
	delete[] R;
}

long long countMergeSort(int* arr, int l, int r, long long& count_compare) {
	if (++count_compare && l >= r)
	{
		int m = (l + r - 1) / 2;

		countMergeSort(arr, l, m, count_compare);
		countMergeSort(arr, m + 1, r, count_compare);

		countMerge(arr, l, m, r, count_compare);
	}
	return count_compare;
}

long long countRadixSort(int* arr, int n, long long& counting)
{
	int mx = arr[0];
	for (int i = 1; ++counting && i < n; i++)
		if (++counting && arr[i] > mx)
			mx = arr[i];

	for (int exp = 1; ++counting && mx / exp > 0; exp *= 10)
		countCountingSort(arr, n, exp, counting);
	return counting;
}
using namespace std;

template <class T>
void HoanVi(T& arr, T& b)
{
	T x = arr;
	arr = b;
	b = x;
}

void GenerateRandomData(int* arr, int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
	}
}

void GenerateSortedData(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}

void GenerateReverseData(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = n - 1 - i;
	}
}

void GenerateNearlySortedData(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(arr[r1], arr[r2]);
	}
}

void GenerateData(int* arr, int n, int dataType)
{
	switch (dataType)
	{
	case 0:
		GenerateRandomData(arr, n);
		break;
	case 1:
		GenerateSortedData(arr, n);
		break;
	case 2:
		GenerateReverseData(arr, n);
		break;
	case 3:
		GenerateNearlySortedData(arr, n);
		break;
	default:
		printf("Error: unknown data type!\n");
		break;
	}
}

void bubbleSort(int* arr, int n)
{
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
}

void heapify(int* arr, int n, int i)
{
	int largest = i;   // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		HoanVi(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int* arr, int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end
		HoanVi(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void insertionSort(int* arr, int n)
{
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
}

void selectionSort(int* arr, int n)
{
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
}

void binaryInsertionSort(int* arr, int n)
{
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
}

void quickSort(int* arr, int n, int left, int right)
{
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

		// ! Recursion
		quickSort(arr, n, left, j - 1);
		quickSort(arr, n, j + 1, right);
	}
}

void merge(int* arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0;

	int j = 0;

	int k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
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

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int* arr, int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int m = (l + r - 1) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

int getMax(int* arr, int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

void countingSort(int* arr, int size, int place)
{
	const int max = 10;
	int* output = new int[size];
	int count[max];

	for (int i = 0; i < max; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		count[(arr[i] / place) % 10]++;
	}

	for (int i = 1; i < max; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(arr[i] / place) % 10] - 1] = arr[i];
		count[(arr[i] / place) % 10]--;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = output[i];
	}
	delete[] output;
}
long long countCountingSort(int* arr, int n, int exp, long long& counting)
{
	int* output = new int[n];
	int i, count[10] = { 0 };

	for (i = 0; ++counting && i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; ++counting && i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; ++counting && i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; ++counting && i < n; i++)
		arr[i] = output[i];
	return counting;
}

void radixSort(int* arr, int size)
{
	int max = getMax(arr, size);

	for (int place = 1; max / place > 0; place *= 10)
	{
		countingSort(arr, size, place);
	}
}
char* show_data_order(char* s)
{
	//char* temp = s;
	if (strcmp(s, "-rand") == 0)
		strcpy(s, "randomized data");
	if (strcmp(s, "-sorted") == 0)
		strcpy(s, "sorted data");
	if (strcmp(s, "-rev") == 0)
		strcpy(s, "reverse sorted data");
	if (strcmp(s, "-nsorted") == 0)
		strcpy(s, "nearly sorted data");
	return s;
}

void loadFile(const char* path, int*& a, int& n)
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
void saveFile(const char* path, int *a, int n) {
	ofstream f;
	f.open(path);
	f << n << "\n";
	for (int i = 0; i < n; i++)
		f << a[i] << " ";
	f.close();

}
int main(int argc, char* argv[])
{
	clock_t t_start, t_end;
	string temp;
	int* a = NULL;
	long long count_compare;
	//mode algorithm
	if (strcmp(argv[1], "-a") == 0)
	{
		if (argc == 6)//cmd2
		{
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
			saveFile("input.txt", a, size);
			t_start = clock();
			if (strcmp(argv[2], "insertion-sort") == 0)
				 countInsertionSort(a, size, count_compare);
			if (strcmp(argv[2], "selection-sort") == 0)
				 countSelectionSort(a, size, count_compare);
			if (strcmp(argv[2], "bubble-sort") == 0)
				 countBubbleSort(a, size, count_compare);
			if (strcmp(argv[2], "heap-sort") == 0)
				 countHeapSort(a, size, count_compare);
			if (strcmp(argv[2], "merge-sort") == 0)
				 countMergeSort(a, 0, size - 1, count_compare);
			if (strcmp(argv[2], "quick-sort") == 0)
				 countQuickSort(a, size, 0, size - 1, count_compare);
			if (strcmp(argv[2], "radix-sort") == 0)
				countRadixSort(a, size, count_compare);

			t_end = clock();
			saveFile("output.txt", a, size);
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
			count_compare = 0;
			int size = atoi(argv[3]);
			if (size != 0)//cmd3
			{
				a = new int[size];
				int b[4][size];
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
					count_compare = 0;
					GenerateData(a, size, i);
					for (int j = 0; j < size; j++)
						b[i][j] = a[j];
					t_start = clock();
					if (strcmp(argv[2], "insertion-sort") == 0)
						 countInsertionSort(a, size, count_compare);
					else if (strcmp(argv[2], "selection-sort") == 0)
						 countSelectionSort(a, size, count_compare);
					else if (strcmp(argv[2], "bubble-sort") == 0)
					 countBubbleSort(a, size, count_compare);
					else if (strcmp(argv[2], "heap-sort") == 0)
						countHeapSort(a, size, count_compare);
					else if (strcmp(argv[2], "merge-sort") == 0)
						 countMergeSort(a, 0, size - 1, count_compare);
					else if (strcmp(argv[2], "quick-sort") == 0)
						countQuickSort(a, size, 0, size - 1, count_compare);
					else if (strcmp(argv[2], "radix-sort") == 0)
						 countRadixSort(a, size, count_compare);
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
				saveFile("input_1.txt", b[0], size);
				saveFile("input_2.txt", b[3], size);
				saveFile("input_3.txt", b[1], size);
				saveFile("input_4.txt", b[2], size);

			}
			else
			{
				int size;
				loadFile(argv[3], a, size);
				cout << "\nALGORITHM MODE";
				cout << "\nAlgrithm:     " << argv[2];
				cout << "\nInput size:   " << size;
				cout << "\n----------------";

				t_start = clock();
				if (strcmp(argv[2], "insertion-sort") == 0)
					count_compare = countInsertionSort(a, size, count_compare);
				else if (strcmp(argv[2], "selection-sort") == 0)
					count_compare = countSelectionSort(a, size, count_compare);
				else if (strcmp(argv[2], "bubble-sort") == 0)
					count_compare = countBubbleSort(a, size, count_compare);
				else if (strcmp(argv[2], "heap-sort") == 0)
					count_compare = countHeapSort(a, size, count_compare);
				else if (strcmp(argv[2], "merge-sort") == 0)
					count_compare = countMergeSort(a, 0, size - 1, count_compare);
				else if (strcmp(argv[2], "quick-sort") == 0)
					count_compare = countQuickSort(a, size, 0, size - 1, count_compare);
				else if (strcmp(argv[2], "radix-sort") == 0)
					count_compare = countRadixSort(a, size, count_compare);
				t_end = clock();
				saveFile("output.txt", a, size);
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
			int* b = NULL;
			long long c1 = 0, c2 = 0;
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
			saveFile("input.txt", a, size);
			t_start = clock();
			if (strcmp(argv[2], "insertion-sort") == 0)
				count_compare = countInsertionSort(a, size, count_compare);
			else if (strcmp(argv[2], "selection-sort") == 0)
				count_compare = countSelectionSort(a, size, count_compare);
			else if (strcmp(argv[2], "bubble-sort") == 0)
				count_compare = countBubbleSort(a, size, count_compare);
			else if (strcmp(argv[2], "heap-sort") == 0)
				count_compare = countHeapSort(a, size, count_compare);
			else if (strcmp(argv[2], "merge-sort") == 0)
				count_compare = countMergeSort(a, 0, size - 1, count_compare);
			else if (strcmp(argv[2], "quick-sort") == 0)
				count_compare = countQuickSort(a, size, 0, size - 1, count_compare);
			/*else if (strcmp(argv[2], "radix-sort") == 0)
				count_compare = countRadixSort(a, size, count_compare);*/
			t_end = clock();
			t1 = t_end - t_start;
			c1 = count_compare;
			count_compare = 0;
			t_start = clock();
			GenerateData(a, size, data_order);
			if (strcmp(argv[3], "insertion-sort") == 0)
				count_compare = countInsertionSort(a, size, count_compare);
			else if (strcmp(argv[3], "selection-sort") == 0)
				count_compare = countSelectionSort(a, size, count_compare);
			else if (strcmp(argv[3], "bubble-sort") == 0)
				count_compare = countBubbleSort(a, size, count_compare);
			else if (strcmp(argv[3], "heap-sort") == 0)
				count_compare = countHeapSort(a, size, count_compare);
			else if (strcmp(argv[3], "merge-sort") == 0)
				count_compare = countMergeSort(a, 0, size - 1, count_compare);
			else if (strcmp(argv[3], "quick-sort") == 0)
				count_compare = countQuickSort(a, size, 0, size - 1, count_compare);
			/*else if (strcmp(argv[3], "radix-sort") == 0)
				count_compare = countRadixSort(a, size, count_compare);*/
			t_end = clock();
			t2 = t_end - t_start;
			c2 = count_compare;
			cout << "\nRunning time: " << t1 << " | " << t2;
			cout << "\nComparisions: " << c1 << " | " << c2;
		}
		if (argc == 5)
		{
			clock_t start, end;
			double cpu_time_used1, cpu_time_used2;
			long long count_compare1 = 0, count_compare2 = 0;
			int n;
			ifstream fi(argv[4]);
			fi >> n;
			int* arr = new int[n];
			for (int i = 0; i < n; i++) {
				fi >> arr[i];
			}
			if (strcmp(argv[1], "-c") == 0) cout << "COMPARE MODE" << endl;
			cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
			cout << "Input size: " << n << endl;

			if (strcmp(argv[2], "selection-sort") == 0) {
				start = clock();
				count_compare1 = countSelectionSort(arr, n, count_compare1);
				end = clock();
				cpu_time_used1 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[2], "insertion-sort") == 0) {
				start = clock();
				count_compare2 = countInsertionSort(arr, n, count_compare1);
				end = clock();
				cpu_time_used1 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			if (strcmp(argv[2], "bubble-sort") == 0) {
				start = clock();
				count_compare1 = countBubbleSort(arr, n, count_compare1);
				end = clock();
				cpu_time_used1 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[2], "heap-sort") == 0) {
				start = clock();
				count_compare1 = countHeapSort(arr, n, count_compare1);
				end = clock();
				cpu_time_used1 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[2], "merge-sort") == 0) {
				start = clock();
				count_compare1 = countMergeSort(arr, 0, n - 1, count_compare1);
				end = clock();
				cpu_time_used1 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[2], "quick-sort") == 0) {
				start = clock();
				count_compare1 = countQuickSort(arr, n, 0, n - 1, count_compare1);
				end = clock();
				cpu_time_used1 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[2], "radix-sort") == 0) {
				start = clock();
				count_compare1 = countRadixSort(arr, n, count_compare1);
				end = clock();
				cpu_time_used1 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}

			if (strcmp(argv[3], "selection-sort") == 0) {
				start = clock();
				count_compare2 = countSelectionSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[3], "insertion-sort") == 0) {
				start = clock();
				count_compare2 = countInsertionSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[3], "bubble-sort") == 0) {
				start = clock();
				count_compare2 = countBubbleSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[3], "heap-sort") == 0) {
				start = clock();
				count_compare2 = countHeapSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[3], "merge-sort") == 0) {
				start = clock();
				count_compare2 = countMergeSort(arr, 0, n - 1, count_compare2);
				end = clock();
				cpu_time_used2 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[3], "quick-sort") == 0) {
				start = clock();
				count_compare2 = countQuickSort(arr, n, 0, n - 1, count_compare2);
				end = clock();
				cpu_time_used2 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			else if (strcmp(argv[3], "radix-sort") == 0) {
				start = clock();
				count_compare2 = countRadixSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			cout << "Running time: " << cpu_time_used1 << " | " << cpu_time_used2 << endl;
			cout << "Comparisions: " << count_compare1 << " | " << count_compare2 << endl;
			delete arr;
		}
	}
	return 0;
}