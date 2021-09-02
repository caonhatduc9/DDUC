#include<iostream>
#include<vector>
using namespace std;
static int count_assign = 0;
static int count_compare = 0;
int somesum(int n) {

	int sum = 0; ++count_assign;
	int i = 1; ++count_assign;
	int j;
	while (++count_compare && i <= n) {
		j = n - i; ++count_assign;
		while (++count_compare && j <= i * i) {
			sum = sum + i * j; ++count_assign;
			j += 1; ++count_assign;
		}
		i += 1; ++count_assign;
	}
	return sum;
}

int squaresum_recursion(int n) {
	if (++count_compare && n < 1) return 0;
	else
	{
		++count_assign; return n * n + squaresum_recursion(n - 1);
	}
}
void probA1(int* a, int n, int& compare, int& assignment) {
	for (int i = 0; ++compare && i < n; ++assignment && i++) {
		int cnt = 0; ++assignment;
		for (int j = 0; ++compare && j < n; ++assignment && j++) {
			if (++compare && a[j] == a[i]) {
				cnt++;
				++assignment;
			}
		}
		if (++compare && cnt > n / 2) {
			cout << a[i];
			return;
		}
	}
	cout << "NO";
}
void probA2(int* a, int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
		if (max < a[i])
			max = a[i];
	max++;
	int* cnt = new int[max] { 0 };
	for (int i = 0; i < n; i++)
		cnt[a[i]]++;
	for (int i = 0; i < max; i++)
		if (cnt[i] > n / 2)
		{
			cout << i;
			delete[] cnt;
			return;
		}
	cout << "NO";

}
int probB1(int a, int b)
{
	int gcd = 0;
	for (int i = 1; i <= min(a, b); i++)
		if (a % i == 0 && b % i == 0)
			gcd = i;
	return gcd;
}
int probB2(int a, int b)
{
	if (b == 0) return a;
	if (a % b == 0) return b;
	return probB2(b, a % b);
}
void probC1(string s[], int n)
{
	int* check = new int[n] {0};
	int cnt;
	for (int i = 0; i < n; i++)
	{
		if (check[i] == 1)
			continue;
		cnt = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				cnt++;
				check[j] = 1;
			}
		}
		cout << s[i] << ": " << cnt << endl;
	}
}
template <class T, class T1>
void quickSort(T a[], T1 l, T1 r)
{
	T p = a[(r + l) / 2];
	int i = l, j = r;
	while (i < j)
	{
		while (a[i] < p)
			i++;
		while (a[j] > p)
			j--;
		if (i <= j)
		{
			T tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++; j--;
		}
	}
	if (l < j) quickSort(a, l, j);
	if (i < r) quickSort(a, i, r);
}
void probC2(string s[], int n)
{
	quickSort(s, 0, n - 1);
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != s[i + 1])
		{
			cout << s[i] << ": " << cnt << endl;
			cnt = 1;
		}
		else
			cnt++;
	}
}

//cau D
void probD1(int a[5], int n, int x, int y)
{
	int i, j, flag = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (x + a[i] == y + a[j] && a[j] != a[i]) {
				cout << a[i] << " " << a[j] << endl;
				flag = 1;
			}
		}

	}

	if (flag == 0)
		cout << "not possible";
}
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

void probD2(int* a, int n, int x, int y)
{
	int val,  check = -1;
	for (int i = 0; i < n; i++)
	{
		val = x - y + a[i];
		check = linearSearch(a, n, val);
		if (val == a[check])
		{
			cout << a[i] << "\t" << a[check];
			return;
		}
	}
	cout << "not possible";
}



int main()
{
	//cout << "n\t\tassignments\t\tcomparisions" << endl;
	/*for (int i = 0; i <= 500; i++) {
		somesum(i);
		cout << i << "\t\t" << count_assign << " \t\t\t" << count_compare << endl;
	}
	return 0;*/
	//for (int i = 0; i <= 500; i++) {
	//	squaresum_recursion(i);
	//	cout << i << "\t\t" << count_assign << " \t\t\t" << count_compare << endl;
	//}

	/*int n = 5;
	int* a = { new int[n] {3,5,3,3,2} };
	int x = 0, y = 0;
	probA2(a, n);*/


	//cout << probB2(60, 45);
	
	
	/*c
	int n = 7;
	string s[7] = { "cao","nhat","cao","duc","duc","duc","ba" };
	int x = 0, y = 0;
	probC2(s, n);*/
	
	
	/*
	int n = 5;
	int* a = { new int[n] {3,5,3,3,2} };

	 probD2(a, n, 4, 6);*/
}