//#include "DataGenerator.h"
//#include <iostream>
//#include <fstream>
//#include <cmath>
//#include <time.h>
//
//using namespace std;
//
//template <class T>
//void HoanVi(T& a, T& b)
//{
//	T x = a;
//	a = b;
//	b = x;
//}
//
////-------------------------------------------------
//
//// Hàm phát sinh mảng dữ liệu ngẫu nhiên
//void GenerateRandomData(int a[], int n)
//{
//	srand((unsigned int)time(NULL));
//
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % n;
//	}
//}
//
//// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
//void GenerateSortedData(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = i;
//	}
//}
//
//// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
//void GenerateReverseData(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = n - 1 - i;
//	}
//}
//
//// Hàm phát sinh mảng dữ liệu gần như có thứ tự
//void GenerateNearlySortedData(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = i;
//	}
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < 10; i++)
//	{
//		int r1 = rand() % n;
//		int r2 = rand() % n;
//		HoanVi(a[r1], a[r2]);
//	}
//}
//
//void GenerateData(int a[], int n, int dataType)
//{
//	switch (dataType)
//	{
//	case 0:	// ngẫu nhiên
//		GenerateRandomData(a, n);
//		break;
//	case 1:	// có thứ tự
//		GenerateSortedData(a, n);
//		break;
//	case 2:	// có thứ tự ngược
//		GenerateReverseData(a, n);
//		break;
//	case 3:	// gần như có thứ tự
//		GenerateNearlySortedData(a, n);
//		break;
//	default:
//		printf("Error: unknown data type!\n");
//	}
//}
///*
//* 	int* a;
//	int s;
//	int size[6] = { 10000,30000,50000,100000,300000,500000 };//size data
//	string Data_Order[4] = { "RandomData","SortedData","ReverseData","NearlySortedData" };//data order 
//	unsigned long long count_compare = 0;
//	while (1) {
//		cout << "choice size:\n1_10000\n2_30000\n3_50000\n4_100000\n5_300000\n6_500000 ";
//		cout << "\nchoice: ";
//		cin >> s;
//
//		if (s <= 6) {
//			a = new int[size[s - 1]];
//			clock_t t1, t2;
//			for (int i = 0; i < 4; i++)
//			{
//				count_compare = 0;
//				GenerateData(a, size[s - 1], i);
//				t1 = clock();
//				count_compare = insertion_sort(a, size[s - 1]);
//				t2 = clock();
//				cout << "Sorting Algorithm: insertion" << endl;
//				cout << "Data order: " << Data_Order[i] << endl;
//				cout << "Data size: " << size[s - 1] << endl;
//				cout << "Time running: " << t2 - t1 << endl;
//				cout << "count compare: " << count_compare << endl << endl;
//
//				count_compare = 0;
//				GenerateData(a, size[s - 1], i);
//				t1 = clock();
//				count_compare = binary_insertion_sort(a, size[s - 1]);
//				t2 = clock();
//				cout << "Sorting Algorithm: binary insertion" << endl;
//				cout << "Data order: " << Data_Order[i] << endl;
//				cout << "Data size: " << size[s - 1] << endl;
//				cout << "Time running: " << t2 - t1 << endl;
//				cout << "count compare: " << count_compare << endl << endl;
//				count_compare = 0;
//
//				count_compare = 0;
//				GenerateData(a, size[s - 1], i);
//				t1 = clock();
//				count_compare = selection_sort(a, size[s - 1]);
//				t2 = clock();
//				cout << "Sorting Algorithm: selection_sort" << endl;
//				cout << "Data order: " << Data_Order[i] << endl;
//				cout << "Data size: " << size[s - 1] << endl;
//				cout << "Time running: " << t2 - t1 << endl;
//				cout << "count compare: " << count_compare << endl << endl;
//
//				count_compare = 0;
//				GenerateData(a, size[s - 1], i);
//				t1 = clock();
//				count_compare = dummy_selection_sort(a, size[s - 1]);
//				t2 = clock();
//				cout << "Sorting Algorithm: dummy selection_sort" << endl;
//				cout << "Data order: " << Data_Order[i] << endl;
//				cout << "Data size: " << size[s - 1] << endl;
//				cout << "Time running: " << t2 - t1 << endl;
//				cout << "count compare: " << count_compare << endl << endl;
//
//			}
//		}
//	}
//*/