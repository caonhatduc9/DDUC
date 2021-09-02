#include "function.h"

using namespace std;

int main(int argc, char* argv[])
{
	clock_t t_start, t_end;
	string temp;
	int* a = NULL;
	long long count_compare;
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