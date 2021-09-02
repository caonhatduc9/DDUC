#include<iostream>
#include<time.h>
using namespace std;
//BAI 1
void  swap(int* a, int* b)
{
	int k = *a;
	*a = *b;
	*b = k;
}
//BAI 2
int* sum(int* a, int* b)
{
	int* s = new int;
	*s = *a + *b;
	return s;
}
//BAI 3
void inputArray(int*& a, int& n)
{
	cout << "nhap n: ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
//BAI 4
void printArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

//bai 6,tim mang con tang dan dai nhat tham khao: https://www.youtube.com/watch?v=zvf4D30YPdE
int* findLongestAscendingSubArray(int* a, int n, int& length)
{
	int* b = new int[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = 1;
	}
	for (int i = n - 1; i > 0; i--)
	{
		if (a[i] > a[i - 1])
			b[i - 1] = b[i] + 1;
	}
	for (int i = 0; i < n; i++)
		cout << " " << b[i];
	int max = b[0];
	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		if (b[i] > max)
		{
			max = b[i]; idx = i;
		}
	}
	length = b[idx];
	return (a + idx);
}
//bai 7, swap 2 mang
void swapArrays(int*& a, int*& b, int& na, int& nb)
{
	int* c = new int[na];
	int* d = new int[nb];
	for (int i = 0; i < na; i++)
		c[i] = a[i];

	for (int i = 0; i < nb; i++)
		d[i] = b[i];

	int temp = na;
	na = nb;
	nb = temp;
	a = new int[na];
	b = new int[nb];
	for (int i = 0; i < nb; i++)
		b[i] = c[i];
	for (int i = 0; i < na; i++)
		a[i] = d[i];
}
//bai 8 gop 2 mang
int* concatenate2Arrays(int* a, int* b, int na, int nb)
{
	int* c = new int[na + nb];
	for (int i = 0; i < na; i++)
	{
		c[i] = a[i];
	}
	for (int i = na; i < na + nb; i++)
	{
		c[i] = b[i - na];
	}
	return c;
}

//bai 9, gop 2 mang tang dan phan biet vao 1 mang tang dan
int* merge2Arrays(int* a, int* b, int na, int nb, int& nc)
{
	nc = na + nb;
	int* c = new int[nc];
	int k1 = 0, k2 = 0;
	for (int i = 0; i < nc; i++)
	{
		if (k1 < na && k2 < nb) {
			if (a[k1] < b[k2])
				c[i] = a[k1++];
			else
				c[i] = b[k2++];
		}
		else if (k2 == nb)
			c[i] = a[k1++];
		else
			c[i] = b[k2++];
	}
	return c;
}
//BAI 10 KHOI TAO MA TRAN
void generateMatrix(int**& a, int& d, int& c)
{
	cout << "\n nhap dong: ";
	cin >> d;
	cout << "\n nhap cot: ";
	cin >> c;
	a = new int* [d];
	for (int i = 0; i < d; i++)
		a[i] = new int[c];
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
}
void generateMatrixRand(int**& a, int& d, int& c)
{
	cout << "\n nhap dong: ";
	cin >> d;
	cout << "\n nhap cot: ";
	cin >> c;
	a = new int* [d];
	for (int i = 0; i < d; i++)
		a[i] = new int[c];
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			a[i][j] = rand() % 10;
}
//	BAI 11
int** generateMatrix2(int* a, int* b, int na, int nb)
{
	int** c = new int* [na];
	for (int j = 0; j < nb; j++)
		c[j] = new int[nb];

	for (int i = 0; i < na; i++)
		for (int j = 0; j < nb; j++)
			c[i][j] = a[i] * b[j];
	return c;
}
// BAI 12 
void swapRows(int** a, int d, int c)
{
	cout << " nhap 2 dong muon swap: ";
	int d1, d2;
	cin >> d1 >> d2;
	for (int i = 0; i < c; i++)
	{
		int temp = a[d1][i];
		a[d1][i] = a[d2][i];
		a[d2][i] = temp;
	}
}
void swapColumns(int** a, int d, int c)
{
	cout << " nhap 2 cot muon swap: ";
	int c1, c2;
	cin >> c1 >> c2;
	for (int i = 0; i < d; i++)
	{
		int temp = a[c1][i];
		a[c1][i] = a[c2][i];
		a[c2][i] = temp;
	}
}
//bai13 chuyen vi ma tran
int** transposeMatrix(int** b, int d, int c)
{
	int** b1 = new int* [c];
	for (int i = 0; i < c; i++)
		b1[i] = new int[d];
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			b1[j][i] = b[i][j];
	return b1;
}
//14
int** concatenate2MatricesH(int** a, int** b, int length, int width)
{
	int** c = new int* [length];
	for (int i = 0; i < length; i++)
		c[i] = new int[width * 2];

	for (int i = 0; i < length; i++)
		for (int j = 0; j < width * 2; j++)
		{
			if (j >= width)
			{
				c[i][j] = b[i][j - width];
			}
			else
				c[i][j] = a[i][j];

		}
	return c;
}
int** concatenate2MatricesV(int** a, int** b, int length, int width)
{
	int** c = new int* [length * 2];
	for (int i = 0; i < length * 2; i++)
		c[i] = new int[width];

	for (int i = 0; i < length * 2; i++)
		for (int j = 0; j < width; j++)
		{
			if (i >= length)
			{
				c[i][j] = b[i - length][j];
			}
			else
				c[i][j] = a[i][j];

		}
	return c;
}
void inputMatrix(int**& b, int& d, int& c)
{
	cout << "nhao dong, cot:";
	cin >> d >> c;
	b = new int* [d];
	for (int i = 0; i < d; i++)
		b[i] = new int[c];
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			cin >> b[i][j];
}
void outputMatrix(int** b, int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}

}
//15 nhan 2 ma tran
bool multiple2Matrices(int** &c, int** a, int** b, int lengtha, int widtha, int lengthb, int widthb)
{
	if (widtha != lengthb)
		return false;
	c = new int* [lengtha];
	for (int i = 0; i < lengtha; i++)
		c[i] = new int[widthb];
	for (int i = 0; i < lengtha; i++)
		for (int j = 0; j < widthb; j++)
		{
			int sum = 0;
			for (int k = 0; k < widtha; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
	return true;
}
//bai 16 tim ma tran con co tong lon nhat, occho lam kha lau
int** findSubmatrix(int** a, int d, int c, int d1, int c1)
{//2 dong 3 cot
	//me 3,4
	int** b = new int* [d1];
	for (int j = 0; j < d; j++)
		b[j] = new int[c1];

	int indexDong = 0, indexCot = 0;

	int** array1D = new int* [d1];
	int	m = (d - d1 + 1) * (c - c1 + 1);
	for (int j = 0; j < m; j++)
		array1D[j] = new int[c1 * d1];


	for (int i = 0; i <= d - d1; i++)
		for (int j = 0; j <= c - c1; j++)
		{
			for (int i1 = i; i1 < i + d1; i1++)
			{
				for (int j1 = j; j1 < j + c1; j1++)
				{
					array1D[indexDong][indexCot++] = a[i1][j1];
				}
				if (indexCot == d1 * c1)
				{
					indexDong++;
					indexCot = 0;
				}
			}
		}
	int sum = 0, max, idxMax;
	//lay ra dong co sum lon nhat
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < c1 * d1; j++)
		{
			sum += array1D[i][j];
			if (i == 0)
			{
				max = sum;
				idxMax = 0;
			}
			if (max < sum)
			{
				max = sum;
				idxMax = i;
			}
			sum = 0;
		}
	}
	int idx = 0;
	for (int i = 0; i < d1; i++)
		for (int j = 0; j < c1; j++)
		{
			b[i][j] = array1D[idxMax][idx++];
		}
	return b;
}


//tim kiem nhi phan
bool binarySearch(int* a, int n, int key, int left, int right) {
	int mid = (left + right) / 2;
	if (a[mid] == key)
		return true;
	if (left > right)
		return false;
	if (a[mid] < key)
		return binarySearch(a, n, key, mid + 1, right);
	if (a[mid] > key)
		return binarySearch(a, n, key, left, mid - 1);
}
//tim kiem binh thuong
int search(int* a, int n, int key)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[mid] == key)
			return mid;
		else if (a[mid] < key)
			l = mid + 1;
		else if (a[mid] > key)
			r = mid - 1;
	}
	return -1;
}
//tim kiem tuyen tinh
int linearSearch(int* a, int n, int key) {
	if (a[n - 1] == key)
		return n - 1;
	else {
		int x = a[n - 1];
		a[n - 1] = key;
		int i;
		for (i = 0; ; i++)
		{
			if (a[i] == key)
				break;
		}
		a[n - 1] = x;
		if (i < n - 1)
			return i;
		if (i == n - 1);
		return -1;
	}
}
int main()
{
	srand(time(NULL));
	//int* arr1{ new int[5]{5,6,8,2,4} };
	//if (binarySearch(arr1, 5, 4, 0, 4))
	//int* arr2{ new int[2]{9,4} };
	////cout << linearSearch(arr1, 5, 2);
	//int l;
	//findLongestAscendingSubArray(arr1, 5, l);
	//for (int i = 0; i < l; i++)
	//	cout << arr1[i] << " ";
	int** b = NULL, ** b1 = NULL, ** k1 = NULL;
	int d = 2, c = 3;
	int d1 = 3, c1 = 4;
	
	return 0;
}