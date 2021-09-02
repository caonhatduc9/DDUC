/*#include<iostream>
#include<stdlib.h>
using namespace std;
void inPut(int A[100][100], int& d, int& c);
void outPut(int A[100][100], int d, int c);
void swap(int& a, int& b);
void xepTangCheoChinh(int A[100][100], int d, int c);
void xepCheoPhu(int A[100][100], int d, int c);
void swapRow(int A[100][100], int d, int c,int g,int h);
void xepTangTongDong(int A[100][100], int d, int c);
int main()
{
	srand(time(NULL));
	int A[100][100], c, d;
	inPut(A, d, c);
	outPut(A, d, c);
	cout << "\n\n\n";
	//xepTangCheoChinh(A, d, c);
	//outPut(A, d, c);
	/*xepCheoPhu(A, d, c);
     cout << "\n\n\n";
	outPut(A, d, c);

	int a, b;
	cout << "nhap 2 dong can doi: ";
	cin >> a >> b;
	swapRow(A, d, c,a,b);
	outPut(A, d, c);
	xepTangTongDong(A, d, c);
	outPut(A, d, c);
	return 0;
}
void inPut(int A[100][100], int &d, int &c)
{
	cout << "ROW ";
	cin >> d;
	cout << "\nCOLUMN ";
	cin >> c;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
		{
			A[i][j] = rand() % 100;
		}
}
void outPut(int A[100][100], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		cout << "\t\t\t";
		for (int j = 0; j < c; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << "\n\n";
	}
}
void swap(int& a, int& b)
{
	b += a;
	a = b - a;
	b = b - a;
}
void xepTangCheoChinh(int A[100][100], int d, int c)
{
	for (int i = 0; i < d - 1; i++)
	{
		for (int j = i + 1; j < d; j++)
		{
			if (A[i][i] > A[j][j])
				swap(A[i][i], A[j][j]);
		}
	}
}
void xepCheoPhu(int A[100][100], int d, int c)
{
	for (int i = d - 1; i > 0; i--)
	{	
		for (int j = i - 1; j >= 0; j--)
		{
			if (A[i][d-i-1] > A[j][d-1-j])
				swap(A[i][d-i-1], A[j][d-1-j]);
		}
	}
}
void swapRow(int A[100][100], int d, int c,int g,int h)
{
	for (int i = 0; i < c; i++)
	{
		swap(A[g][i], A[h][i]);
	}
}
void xepTangTongDong(int A[100][100], int d, int c)
{
	int B[5];
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			B[i] = B[i] + A[i][j];
		}
	}
	for (int i = 0; i < d - 1; i++)
	{
		for (int j = i + 1; j < d; j++)
		{
			if (B[i] > B[j])
				swapRow(A, d, c, i, j);
		}
	}
}*/

#include<iostream>
using namespace std;
//#define nrow=3
int arr2D_alloc(int* a[], int m, int n)
{
	int i;
	int* buffer = (int*)calloc(m * (size_t)n, sizeof(int));
	if (buffer == NULL) {
		a[0] = NULL;
		return 0;
	}

	a[0] = buffer;

	for (i = 0; i < m; i++)
	{
		buffer += n;
		a[i] = buffer;
	}
	return 1;
}
void arr2D_free(int* a[])
{
	if (a[0] != NULL)
	{
		free(a[0]);
		a[0] = NULL;
	}
}
void arr2D_input(int* a[], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}
void arr2D_output(int* a[], int m, int n)
{

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
			cout << endl;
		}
}

int main()
{
	int nrow = 3;
	int nb, mb = nrow;
	int* b[3];
	cout << "enter clumn";
	cin >> nb;
	if (nb > 0 && arr2D_alloc(b, mb, nb))
	{
		arr2D_input(b, mb, nb);
		cout << "\n\n";
		arr2D_output(b, mb, nb);
	}
	arr2D_free(b);
	return 0;
}