#include<iostream>
#include<string.h>
using namespace std;
struct PHANSO
{
	int tu, mau;
};
//template <class T>
//bool(*standard)(T, T);

template<class T>
bool increase(T a, T b)
{
	return (a > b);
}
template<class T>
bool decrease(T a, T b)
{ 
	return a < b;
}
template<class T>
void sort(T a[], int n, bool (*standard)(T, T))
{
	for (int i = 0; i < n; i++)
	{

		for (int j = i + 1; j < n; j++)
		{
			if (standard(a[i], a[j]))
			{
				T t = a[i]; a[i] = a[j]; a[j] = t;
			}
		}


	}
}
ostream& operator<<(ostream& output, PHANSO a)
{
	output << a.tu << ' ' << a.mau << endl;
	return output;
}

bool operator <(PHANSO a, PHANSO b) 
{
	return (a.tu * b.mau < a.mau* b.tu);
}

bool operator >(PHANSO a, PHANSO b) 
{
	return (a.tu * b.mau > a.mau * b.tu);
}

int main()
{
	//int a[] = { 2,5,3,6 };
//float a[] = { 1.6F,8.6F,9.9F,2.3F };
	//PHANSO a[] = { {1,2},{2,3},{3,7} };
	string a[] = { "hello","chao","bonjour" };
	int n = sizeof(a) / sizeof(a[0]);
	sort(a, n, decrease);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	sort(a, n, increase);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}