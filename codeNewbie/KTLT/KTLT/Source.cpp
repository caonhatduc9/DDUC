#include<iostream>
#include<math.h>
struct complex
{
	float a;
	float b;
};
using namespace std;
double task1(int x);
int task2(int n);
void inPut(complex &k);
void outPut(complex k);
double module(complex k);
void add(complex k, complex h);
int main()
{
	int x;
	cout << "nhap x\n";
	cin >> x;
	double y = task1(x);
	
	if (task2(x) == 1)
		cout << "YES\n";
	else
		cout << "NO\n";
	complex k, h;
	inPut(k);
	outPut(k);
	cout << "\n";
	inPut(h);
	outPut(h);

	cout << "\nmodule: " << module(k);
	add(k, h);
	return 0;
}
double task1(int x)
{
	return sqrt(1 + x * x);
}
int task2(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt((float)n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void inPut(complex &k)
{
	cout << "nhap a: ";
	cin >> k.a;
	cout << "nhap b: ";
	cin >> k.b;
}
void outPut(complex k)
{
	cout << k.a << "i + " << k.b;
}
double module(complex k)
{
	return sqrt(k.a * k.a + k.b * k.b);
}
void add(complex k, complex h)
{
	cout << "\nKet qua " << k.a + h.a << "i + " << k.b + h.b;
}