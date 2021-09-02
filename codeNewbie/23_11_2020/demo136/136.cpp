#include <iostream>
using namespace std;
int timsonguyentomax(int A[100], int n);
int main()
{
	int A[100];
	int n, s;
	printf("nhap so luong:");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("nhap A[%d]", i);
		scanf_s("%d", &A[i]);
	}
	s = timso(A, n);
	if (s >= 0)
	{
		printf("%d", A[s]);
	}
	else
	{
		printf("delco");
	}
	return 0;
}
	int timsonguyentomax(int A[100], int n)
	{
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			
	}
