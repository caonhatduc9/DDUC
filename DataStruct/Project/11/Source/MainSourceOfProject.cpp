#include "AllOfFunction.h"

using namespace std;

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

void saveFile(const char *path, int *a, int n)
{
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
	long long count_compare = 0;
	//mode algorithm
	if (strcmp(argv[1], "-a") == 0)
	{
		if (argc == 6)//cmd2
		{
			int* a = NULL;
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
			if (strcmp(argv[2], "binary-insertion-sort") == 0)
				countBinaryInsertionSort(a, size, count_compare);
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
			delete a;
		}
		if (argc == 5)
		{

			int size = atoi(argv[3]);
			if (size != 0)//cmd3
			{
				int* a = NULL;
				a = new int[size];
				int b[4][size];
				char order[4][20];
				strcpy(order[0], "randomized data");
				strcpy(order[1], "sorted data");
				strcpy(order[2], "reverse sorted data");
				strcpy(order[3], "nearly sorted data");

				cout << "\nALGORITHM MODE ";
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
					if (strcmp(argv[2], "binary-insertion-sort") == 0)
						countBinaryInsertionSort(a, size, count_compare);
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
				delete a;
			}
			else//cmd1
			{
				int size;
				int* a = NULL;
				loadFile(argv[3], a, size);
				cout << "\nALGORITHM MODE";
				cout << "\nAlgrithm:     " << argv[2];
				cout << "\nInput size:   " << size;
				cout << "\n----------------";
				count_compare = 0;
				t_start = clock();
				if (strcmp(argv[2], "insertion-sort") == 0)
					countInsertionSort(a, size, count_compare);
				if (strcmp(argv[2], "binary-insertion-sort") == 0)
					countBinaryInsertionSort(a, size, count_compare);
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
				cout << endl;
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
				delete a;
			}
		}
	}

	//mode compare
	if (strcmp(argv[1], "-c") == 0)
	{
		if (argc == 6)//cmd 5
		{
			int* a = NULL;
			int t1, t2;
			int* b = NULL;
			long long c1 = 0, c2 = 0;
			int size = atoi(argv[4]);
			a = new int[size];
			b = new int[size];
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
		
			count_compare = 0;
			GenerateData(a, size, data_order);
			
			for (int i= 0; i < size; i++)
				b[i] = a[i];
			saveFile("input.txt", a, size);
			t_start = clock();
			if (strcmp(argv[2], "insertion-sort") == 0)
				countInsertionSort(a, size, count_compare);

			if (strcmp(argv[2], "binary-insertion-sort") == 0)
				countBinaryInsertionSort(a, size, count_compare);

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
			t1 = t_end - t_start;
			c1 = count_compare;
			count_compare = 0;
			t_start = clock();
		
			if (strcmp(argv[3], "insertion-sort") == 0)
				countInsertionSort(b, size, count_compare);
			if (strcmp(argv[3], "binary-insertion-sort") == 0)
				countBinaryInsertionSort(b, size, count_compare);
			if (strcmp(argv[3], "selection-sort") == 0)
				countSelectionSort(b, size, count_compare);
			if (strcmp(argv[3], "bubble-sort") == 0)
				countBubbleSort(b, size, count_compare);
			if (strcmp(argv[3], "heap-sort") == 0)
				countHeapSort(b, size, count_compare);
			if (strcmp(argv[3], "merge-sort") == 0)
				countMergeSort(b, 0, size - 1, count_compare);
			if (strcmp(argv[3], "quick-sort") == 0)
				countQuickSort(b, size, 0, size - 1, count_compare);
			if (strcmp(argv[3], "radix-sort") == 0)
				countRadixSort(b, size, count_compare);
			t_end = clock();
			t2 = t_end - t_start;
			c2 = count_compare;
			cout << "\nRunning time: " << t1 << " | " << t2;
			cout << "\nComparisions: " << c1 << " | " << c2;
			delete a;
			delete b;
		}
		if (argc == 5)//cmd 4
		{
			clock_t start, end;
			int cpu_time_used1, cpu_time_used2;
			long long count_compare1 = 0, count_compare2 = 0;
			int n;
			int* arr;
			loadFile(argv[4], arr, n);
			cout << "COMPARE MODE" << endl;
			cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
			cout << "Input file: " << argv[4] << endl;
			cout << "Input size: " << n << endl;
			cout << "-----------------" << endl;
			if (strcmp(argv[2], "selection-sort") == 0) {
				start = clock();
				countSelectionSort(arr, n, count_compare1);
				end = clock();
				cpu_time_used1 = (end - start);
			}
			if (strcmp(argv[2], "insertion-sort") == 0) {
				start = clock();
				countInsertionSort(arr, n, count_compare1);
				end = clock();
				cpu_time_used1 = end - start;
			}
			if (strcmp(argv[2], "bubble-sort") == 0) {
				start = clock();
				countBubbleSort(arr, n, count_compare1);
				end = clock();
				cpu_time_used1 = end - start;
			}
			if (strcmp(argv[2], "heap-sort") == 0) {
				start = clock();
				countHeapSort(arr, n, count_compare1);
				end = clock();
				cpu_time_used1 = end - start;
			}
			if (strcmp(argv[2], "merge-sort") == 0) {
				start = clock();
				countMergeSort(arr, 0, n - 1, count_compare1);
				end = clock();
				cpu_time_used1 = end - start;
			}
			if (strcmp(argv[2], "quick-sort") == 0) {
				start = clock();
				countQuickSort(arr, n, 0, n - 1, count_compare1);
				end = clock();
				cpu_time_used1 = end - start;
			}
			if (strcmp(argv[2], "radix-sort") == 0) {
				start = clock();
				countRadixSort(arr, n, count_compare1);
				end = clock();
				cpu_time_used1 = end - start;
			}

			if (strcmp(argv[3], "selection-sort") == 0) {
				start = clock();
				countSelectionSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = end - start;
			}
			if (strcmp(argv[3], "insertion-sort") == 0) {
				start = clock();
				countInsertionSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = end - start;
			}

			if (strcmp(argv[3], "binary-insertion-sort") == 0) {
				start = clock();
				countBinaryInsertionSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = end - start;
			}

			if (strcmp(argv[3], "bubble-sort") == 0) {
				start = clock();
				countBubbleSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = end - start;
			}
			if (strcmp(argv[3], "heap-sort") == 0) {
				start = clock();
				countHeapSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = end - start;
			}
			if (strcmp(argv[3], "merge-sort") == 0) {
				start = clock();
				countMergeSort(arr, 0, n - 1, count_compare2);
				end = clock();
				cpu_time_used2 = end - start;
			}
			if (strcmp(argv[3], "quick-sort") == 0) {
				start = clock();
				countQuickSort(arr, n, 0, n - 1, count_compare2);
				end = clock();
				cpu_time_used2 = end - start;
			}
			if (strcmp(argv[3], "radix-sort") == 0) {
				start = clock();
				countRadixSort(arr, n, count_compare2);
				end = clock();
				cpu_time_used2 = end - start;
			}
			cout << "Running time: " << cpu_time_used1 << " | " << cpu_time_used2 << endl;
			cout << "Comparisions: " << count_compare1 << " | " << count_compare2 << endl;
			delete arr;
		}
	}
	return 0;
}