#include<iostream>
using namespace std;
#include<memory.h>
/*void upper(char* c)
{
	*c = *c - 32;
}
void swap(int*& a, int*& b)
{
	int k = *a;
	*a = *b;
	*b = k;
}
void inputarray1D(int*& a, int& n)
{
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> *(a + i);
}
void outputArray1D(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a + i) << "\t";
}
void inputArray2D(int**& b, int& d, int& c)
{
	cin >> d >> c;
	b = new int* [d];
	for (int i = 0; i < d; i++)
		*(b + i) = new int[c];
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> *(*(b + i) + j);
		}
}
void outputArray2D(int** b, int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << *(*(b + i) + j) << "\t";
		}
		cout << endl << endl;
	}
}
void del(int** b, int d)
{
	for (int i = 0; i < d; i++)
		delete b[d];
}
struct PS {
	int x, y;
};
istream& operator>>(istream& is, PS &a)
{
	is >> a.x;
	is >> a.y;
	return is;
}
ostream& operator<<(ostream& os,const PS &a)
{
	os << a.x<<"/" << a.y;
	return os;
}
template<class T>
void arraypushpack(T*& a, int& n, T x)
{
	int m = n + 1;
	//PS*anew
	T* anew = (T*)realloc(a, m * sizeof(T));
	if (anew != NULL)
	{

		anew[n] = x;
		n++;
		a = anew;
	}
}
template<class T>
void arrayInput(T*& a, int& n)
{
	T x;
	a = NULL, n = 0;
	while (cin >> x)
	{
		arraypushpack(a, n, x);
	}
}*/
static int dummy_nitem;
static int headsize = sizeof(dummy_nitem);
static int memsize(int nitem) {
	if (nitem < 0)
		nitem = -nitem;
	return headsize + nitem * sizeof(float);
}
static void* origin_addr(float* aData)
{
	return (char*)aData - headsize;
}
static float* data_addr(float* origin)
{
	return(float*)((char*)origin + headsize);
}

static void set_nitem(float* aData, int nitem)
{
	*(int*)origin_addr(aData) = nitem;
}
static int get_nitem(float* aData)
{
	return *(int*)origin_addr(aData);
}
float* floatArrResize(float* aData, int nitem)
{
	int sz = memsize(nitem);
	float* anew = NULL;
	void* originAddr = NULL;
	if (aData != NULL)
	{
		originAddr = origin_addr(aData);
	}
	anew = (float*)realloc(originAddr, sz);
	if (anew != NULL)
	{
		if (aData == NULL) {
			memset(anew, 0, sz);
		}
		aData = data_addr(anew);
		set_nitem(aData, nitem);
	}
	return aData;
}
int arrsize(float* aData)
{
	if (aData != NULL)
	{
		return get_nitem(aData);
	}
	return 0;
}
void floatarayfree(float* aData)
{
	if (aData != NULL)
	{
		free(origin_addr(aData));
	}
}
float* floatArrayPushBack(float* aData, float x)
{

	int nitem = arrsize(aData);
	float* anew = floatArrResize(aData, 1 + nitem);
	if (anew != NULL)
	{
		anew[nitem] = x;

		aData = anew;
	}
	return aData;
}
float arrPopBack(float* aData)
{
	int nitem = arrsize(aData);
	float x = 0;
	if (aData != NULL && nitem > 0)
	{
		nitem--;
		x = aData[nitem];
		set_nitem(aData, nitem);
	}
	return x;
}
void arrayOut(float* a)
{
	int i = 0, n = arrsize(a);
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
float* arrayin()
{
	float* anew, * a = NULL; float x;
	while (cin >> x) {
		anew = floatArrayPushBack(a, x); if (anew != NULL)
			a = anew;
	}
	return a;
}

int main()
{
	float* b; float x;
	cout << "input ele ";
	b = arrayin();
	cout << arrsize(b) << " element: \n";
	arrayOut(b);
	x = arrPopBack(b);
	cout << "after pop: ";
	arrayOut(b);
	cout << "\n";
	cout << x;
	floatarayfree(b);
	/*int** a = NULL;
	int d, c;
	inputArray2D(a, d, c);
	outputArray2D(a, d, c);
	del(a, d);
	delete a;*/

}