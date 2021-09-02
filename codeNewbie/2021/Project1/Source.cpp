#include <iostream>
using namespace std;

struct comp
{
	float real, vir;
};

void* origin_addr(void* aData);
void* data_addr(void* aOrigin);
void* sizeItem_addr(void* aData); 
int arrSize(void* aData);
int arrItemSize(void* aData);
void arrFree(void* aData);
void* arrInit(int num, int size);
void* arrResize(void* aData, int nItem); 
int arrPushback(void** aData, void* x); 
istream& operator>>(istream& input, comp& p); 
ostream& operator<<(ostream& output, comp& p); 
void* arrPopback(void** aData); 
comp* compArrIn();
void compArrOut(comp* B);
void main()
{
	cout << "Input complex items: ";
	comp* B = compArrIn();
	compArrOut(B);
	comp* x = (comp*)arrPopback((void**)&B);
	cout << "pop: \n";
	compArrOut(B);
	cout << "\nPop element: " << *x << endl;
	free(x);
	arrFree(B);
}

void* origin_addr(void* aData) 
{
	if (aData != NULL)
		return (char*)aData - 2 * sizeof(int);
	return NULL;
}

void* data_addr(void* aOrigin) 
{
	if (aOrigin != NULL)
		return (char*)aOrigin + 2 * sizeof(int);
	return NULL;
}

void* sizeItem_addr(void* aData)
{
	if (aData != NULL)
		return (char*)aData - sizeof(int);
	return NULL;
}

int arrSize(void* aData) 
{
	if (aData != NULL)
		return *(int*)origin_addr(aData);
	return 0;
}

int arrItemSize(void* aData)
{
	if (aData != NULL)
		return *(int*)sizeItem_addr(aData);
	return 0;
}

void* arrInit(int num, int size)
{
	int sz = 2 * sizeof(int) + num * size;
	void* aOrigin = malloc(sz);
	if (aOrigin != NULL) 
	{
		memset(aOrigin, 0, sz);
		void* aData = data_addr(aOrigin);
		*(int*)origin_addr(aData) = num;
		*(int*)sizeItem_addr(aData) = size;
		return aData;
	}
	return NULL;
}

void* arrResize(void* aData, int nItem) 
{
	if (aData == NULL || nItem < 0) return NULL;
	void* aOrigin = origin_addr(aData);
	int sizeItem = *(int*)sizeItem_addr(aData);
	int sz = 2 * sizeof(int) + nItem * sizeItem;
	void* aNew = realloc(aOrigin, sz);
	if (aNew != NULL)
	{
		aData = data_addr(aNew);
		*(int*)origin_addr(aData) = nItem;
		return aData;
	}
	return NULL;
}

int arrPushback(void** aData, void* x)
{
	int nItem = arrSize(*aData), szItem = arrItemSize(*aData);
	void* aNew = arrResize(*aData, 1 + nItem);
	if (aNew != NULL) 
	{
		memmove((char*)aNew + nItem * szItem, x, szItem);
		*aData = aNew;
		return 1;
	}
	return 0;
}

istream& operator>>(istream& input, comp& p) 
{
	input >> p.real >> p.vir;
	return input;
}

ostream& operator<<(ostream& output, comp& p) 
{
	output << p.real << "/" << p.vir;
	return output;
}

void* arrPopback(void** aData)
{
	int nItem = arrSize(*aData), szItem = arrItemSize(*aData);
	void* x = malloc(szItem);
	if (*aData != NULL && nItem > 0)
	{
		nItem--;
		memmove(x, (char*)(*aData) + nItem * szItem, szItem);
		void* aNew = arrResize(*aData, nItem);
		if (aNew != NULL) *aData = aNew;
	}
	return x;
}

comp* compArrIn()
{
	comp* p = (comp*)arrInit(0, sizeof(comp));
	comp x = { 0,0 };
	while (cin >> x)
	{
		arrPushback((void**)&p, &x);
	}
	cin.clear();
	return p;
}

void compArrOut(comp* B) 
{
	int nItem = *(int*)origin_addr((void*)B);
	for (int i = 0; i < nItem; i++) 
	{
		cout <<"\t\t"<< B[i] << endl;
	}
}

void arrFree(void* aData)
{
	if (aData != NULL) free(origin_addr(aData));
}
