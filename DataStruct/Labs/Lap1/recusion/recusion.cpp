#include<iostream>
using namespace std;
//1
int tinhTong(int n)
{
	if (n == 1)
		return 1;
	else
		return tinhTong(n - 1) + n;
}
//2
int tinhGiaiThua(int n)
{
	if (n == 0)
		return 1;
	else return tinhGiaiThua(n - 1) * n;
}
//bai 3
int tinh_x_mu_n(int x, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	else {
		return x * tinh_x_mu_n(x, n - 1);
	}
}
//bai 4 dem so chu so
int countD(int x) {
	if (x < 10 && x >= 0)
		return 1;
	else return countD(x / 10) + 1;
}
//5 kiem tra mọi chu so deu chan?
bool evenDitgit(int x)
{
	if (x % 2 != 0)
		return false;
	if (x >= 10)
		return evenDitgit(x / 10);
	return true;

}
//bai 6
int countCommonDivisor(int x, int y, int c )
{
	if (c == 1)
		return 1;
	else {
		if (x % c == 0 && y % c == 0)
			return countCommonDivisor(x, y, --c) + 1;
		else return countCommonDivisor(x, y, --c);
	}
}
//bai 10 hoan vi
void swap(string& a, string& b)
{
	string c = a;
	a = b;
	b = c;
}

//tim uoc chung lon nhat
int gcd(int m, int n)
{
	int r;
	if (m< n)
		return gcd(n, m);
	r = m % n;
	if (r == 0)
		return n;
	else
		return gcd(n, r);
}
//7
int ucln(int a, int b) {
	if (b == 0) return a;
	if (a % b == 0) return b;
	return ucln(b, a % b);
}
//8
int backsee(int number, int result = 0)
{
	if (number == 0) return result;
	return backsee(number / 10, result * 10 + number % 10);
}
//9
int fib(int x)
{
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
		return fib(x - 1) + fib(x - 2);
}
//10
void permutation(string A, int j)
{
	if (j == 2)
		cout << A << "\n";
	else
		for (int i = j; i < 3; i++)
		{
			swap(A[i], A[j]);
			permutation(A, j + 1);
			swap(A[j], A[i]);
		}
}

int check(int x){
	if (x >= 0 && x < 10) {
		if (x % 2 == 0)
			return 1;
		else
		{
			return 0;
		}
	}
	return check(x % 10);
}
int main()
{
	//cout << tinhTong(2);
//	cout << tinhGiaiThua(5);
cout << countCommonDivisor(50, 5,1);
	//string a = "123";
	//permutation(a,0);
//	cout << tinhxn(2, 10);
	//cout << countD(4);
	int x;
	cin >> x;
	//cout << backsee(x);
	/*if (evenDitgit(x) == true)
		cout << "chan";
	else
		cout << "le";*/
	cout << fib(x);
	return 0;
}
