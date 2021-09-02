#include <iostream>
using namespace std;

int sumOf2(int a[], int n) {
	int max = a[0] + a[1];
	int pos = 0;
	for (int i = 1; i < n; i++) {
		if (max < a[i] + a[i + 1]) {
			pos = i;
			max = a[i] + a[i + 1];
		}
	}
	return max;
}

int sumOf2_count(int a[], int n, int &count_assign,int &count_compare) {
	count_assign = 0;
	count_compare = 0;
	int max = a[0] + a[1]; ++count_assign;
	int pos = 0; ++count_assign;
	int i = 1; ++count_assign;
	for (; ++count_compare && i < n; ++count_assign && i++) {
		if (++count_compare && max < a[i] + a[i + 1]) {
			pos = i; ++count_assign;
				max = a[i] + a[i + 1]; ++count_assign;
		}
	}
	return max;
 }

int sumOf2_recursion(int a[], int n)
{
	if (n == 1)
		return -1;
	if (n == 2)
		return a[0] + a[1];
	else
	{
		if (a[n - 1] + a[n-2] > sumOf2_recursion(a, n - 1))
		{
			return a[n - 1] + a[n];
		}
		else
			return  sumOf2_recursion(a, n - 1);
	}
}

int sumOf2_recursion2(int a[], int n, int pos)
{
	if (pos == n - 2)
	{
		return a[n - 2] + a[n - 1];
	}
	return max(sumOf2_recursion2(a, n, pos + 1), a[pos] + a[pos + 1]);
}
int main() {
	int a[10] = { 4,99,2,3,7,536,8,6,5,3 };
	int c1 = 0, c2 = 0;
	cout << sumOf2_count(a, 10, c1, c2);
	cout << sumOf2_recursion2(a, 10,0);
	cout << c2 << c1;
	return 0;
}