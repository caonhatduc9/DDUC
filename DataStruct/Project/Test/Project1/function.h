#ifndef AllOfFunction
#define AllOfFunction

#include <iostream>
#include <time.h>
#include <cmath>
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
void countSort(int* arr, int size, int place);
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

double timeBubbleSort(int* arr, int n, double& elapsed);
double timeHeapSort(int* arr, int n, double& elapsed);
double timeInsertionSort(int* arr, int n, double& elapsed);
double timeSelectionSort(int* arr, int n, double& elapsed);
double timeBinaryInsertionSort(int* arr, int n, double& elapsed);
double timeQuickSort(int* arr, int n, int left, int right, double& elapsed);
double timeMergeSort(int* arr, int l, int r, double& elapsed);
double timeRadixSort(int* arr, int size, double& elapsed);

#endif
