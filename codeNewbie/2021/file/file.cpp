

//#include<iostream>
//#include<fstream>
//using namespace std;
//#pragma pack(1)
//struct ps {
//	int tu, mau;
//};
//void inputArray(int*& a, int& n)
//{
//	cout << "n: ";
//	cin >> n;
//	a = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//}
//void saveFile(ofstream& fout, int* a, int n)
//{
//	fout.write((char*)&n, sizeof(n));
//	for (int i = 0; i < n; i++)
//	{
//		fout.write((char*)&a[i], sizeof(a[i]));
//	}
//}
//void loadfile(ifstream& fin, int*& a, short& n)
//{
//	fin.read((char*)&n, sizeof(n));
//	a = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		fin.read((char*)&a[i], sizeof(a[i]));
//	}
//}
//void outPut(int* a,short n) {
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i];
//	}
//}
//void inputArray(ps*& a, short& n)
//{
//	cout << "n: ";
//	cin >> n;
//	a = new ps[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i].tu >> a[i].mau;
//	}
//}
//void saveFile(ofstream& fout, ps* a, short n)
//{
//	fout.write((char*)&n, sizeof(n));
//	for (int i = 0; i < n; i++)
//	{
//		fout.write((char*)&a[i], sizeof(a[i]));
//	}
//}
//void loadfile(ifstream& fin, ps*& a, short& n)
//{
//	fin.read((char*)&n, sizeof(n));
//	a = new ps[n];
//	for (int i = 0; i < n; i++)
//	{
//		fin.read((char*)&a[i], sizeof(a[i]));
//	}
//}
//void outPut(ps* a, int n) {
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i].tu << "/" << a[i].mau << " ";
//	}
//	
//}
//int main()
//{
//	char base[] = { "C:/Users/caodu/source/repos/2021/file/" };
//	char inputpath[101];
//	strcpy_s(inputpath, base);
//	strcat_s(inputpath, "test.dat");
//
//	char outputpath[101];
//	strcpy_s(outputpath, base);
//	strcat_s(outputpath, "test.dat");
//	cout << inputpath << endl;
//	cout << outputpath << endl;
//
//	ps* a = NULL;
//	short n = 0;
//	ifstream fin;
//	ofstream fout;
//	inputArray(a, n);
//	fout.open(inputpath);
//	if (!fout.is_open())
//	{
//		cout << "dell mo dc" << endl;
//	}
//	else {
//		saveFile(fout, a, n);
//		fout.close();
//		fin.open(outputpath);
//		if (!fin.is_open())
//		{
//			cout << "dell mowr dc" << endl;
//		}
//		else {
//			loadfile(fin, a, n);
//			fin.close();
//			outPut(a, n);
//		}
//	}
//	return 0;
//}
//

#include<iostream>
#include<stdio.h>
using namespace std; 
typedef struct { int x, y; } Point;
//
struct Polygon {
	short nVers;
	Point* Vers;	
};
//
//
//struct PolygonDat { short nVer; Point Vers[1]; };
//
//struct PolygonList
//{
//	char* buf; // Data
//	long nBytes; // Size of file 
//	int nPoly;  // Amount of vertices
//	PolygonDat* operator[](int i) {
//		int j = 0; char* p = buf;
//		while (j < i) {
//			short nVer = *(short*)p;
//			p += sizeof(short) + nVer * sizeof(Point);
//			j++;
//		}
//		return (PolygonDat*)p;
//	}
//};
////typedef struct {
////	char* buf; // Data
////	long nBytes; // Size of file 
////	int nPoly;  // Amount of vertices
////	PolygonDat* operator[](int i) {
////		int j = 0; char* p = buf;
////		while (j < i) {
////			short nVer = *(short*)p;
////			p += sizeof(short) + nVer * sizeof(Point);
////			j++;
////		}
////		return (PolygonDat*)p;
////	};
//
////struct HeadStruct {
////	long offset;
////	union { unsigned long cw; unsigned char cb[4]; };
////	char mb;
////};
////
////struct Point {
////	long x, y;
////};
//
////struct Polygon {
////	short nVers;
////	Point Vers[1];
////};
//
////PolygonP* PgAllocA(int n)
////{
////	if (n < 0)
////		return NULL;
////	int szHead = sizeof(short) + sizeof(Point*);
////	PolygonP* pg = (PolygonP*)calloc(szHead, 1);
////	if (pg == NULL) return NULL;
////	pg->nVers = n;
////	pg->Vers = (Point*)calloc(n, sizeof(Point));
////	if (pg->Vers == NULL) { free(pg); pg = NULL; }
////	return pg;
////}
////void pgFreeA(PolygonP* pg)
////{
////	if (pg != NULL)
////	{
////		if (pg->Vers != NULL)
////			free(pg->Vers);
////			free(pg);
////	}
////}
////
////PolygonP* PgAllocB(int n) {
////	if (n < 0) return NULL;
////	int szHead = sizeof(short) + sizeof(Point*);
////	int szData = n * sizeof(Point);
////	void* buf = calloc(szHead + szData, 1);
////	if (buf == NULL) return NULL;
////	PolygonP* pg = (PolygonP*)buf;
////	pg->nVers = n;
////	pg->Vers = (Point*)((char*)buf + szHead);
////	return pg;
////}
////void pgfreeB(PolygonP* pg)
////{
////	if (pg != NULL)
////		free(pg);	
////}
////Polygon* PgAlloc(int n) {
////	if (n < 0) return NULL;
////	int szHead = sizeof(Polygon), szData = (n - 1) * sizeof(Point);
////	Polygon* pg = (Polygon*)calloc(szHead + szData, 1);
////	if (pg == NULL) return NULL;
////	pg->nVers = n;
////	return pg;
////}
////void pgFree(Polygon* pg)
////{
////	if (pg != NULL)
////		free(pg);
////}
//
typedef struct {
	int nItem, sizeItem;
	char Data[1];
}ArrayStruct;
static int headSize = sizeof(int) + sizeof(int);

ArrayStruct* StructOf(void* aData) {
	if (aData != NULL)
		aData = (char*)aData - headSize;
	return (ArrayStruct*)aData;
}

int arrSize(void* aData) {
	ArrayStruct* as = StructOf(aData);
	if (as != NULL) return as->nItem;
	return 0;
}

int arrItemSize(void* aData) {
	ArrayStruct* as = StructOf(aData);
	if (as != NULL) return as->sizeItem;
	return 0;
}

void arrFree(void* aData) {
	ArrayStruct* as = StructOf(aData);
	if (as != NULL) free(as);
}

static int memSize(int nItem, int sizeItem) {
	if (sizeItem < 0) sizeItem = -sizeItem;
	if (sizeItem == 0) sizeItem = 1;
	if (nItem < 0) nItem = -nItem;
	return headSize + nItem * sizeItem;
}

//
void* arrInit(int n, int szItem) {//ex: n = 3 & szItem = 4
	int sz = memSize(n, szItem); // Compute the bytes needed
	void* aOrigin = malloc(sz), * aData = NULL;
	if (aOrigin != NULL) {
		ArrayStruct* as = (ArrayStruct*)aOrigin;
		memset(aOrigin, 0, sz);
		as->nItem = n; // Assign value of nItem into nItem member
		as->sizeItem = szItem; // Assign value of sizeItem into sizeItem member
		aData = as->Data;
	}
	return aData;
}

void* arrresize(void* adata, int n) {//n=2
	if (adata ==  NULL || n < 0)
		return NULL;
	ArrayStruct* as = StructOf(adata);
	int szitem = as->sizeItem;
	int sznew = memSize(n, szitem);
	ArrayStruct* anew = (ArrayStruct*)realloc(as, sznew);
	if (anew != NULL) {
		anew->nItem = n;
		return anew->Data;
	}
	return NULL;
}
////
////Polygon* PolyListInit() {
////	void* a = arrInit(0, sizeof(Polygon));
////	return (Polygon*)a;
////}
////
////int PolyListPush(Polygon** t, Point* P, short n) {
////	Polygon po = { n };
////	po.Vers = (Point*)calloc(n, sizeof(Point));
////	
////	for (int i = 0; i < n; i++) po.Vers[i] = P[i];
////	return arrPushback((void**)t, (void*)&po);
////}

////int PolyListPush(Polygon** t, Point* P, short n) {
////	Polygon po = { n };
////	po.Vers = (Point*)calloc(n, sizeof(Point));
////	for (int i = 0; i < n; i++) po.Vers[i] = P[i];
////	return arrPushback((void**)t, (void*)&po);
////}
//
Polygon* PolyListInit() {
	void* a = arrInit(0, sizeof(Polygon));
	return (Polygon*)a;
}
//
int arrPushback(void** aData, void* x) {
	int nItem = arrSize(*aData), szItem = arrItemSize(*aData);
	void* aNew = arrresize(*aData, 1 + nItem);
	if (aNew != NULL) {
		memmove((char*)aNew + nItem * szItem, x, szItem);
		*aData = aNew;
		return 1;
	}
	return 0;
}

int PolyListPush(Polygon** t, Point* P, short n) {
	Polygon po = { n };
	po.Vers = (Point*)calloc(n, sizeof(Point));
	for (int i = 0; i < n; i++) po.Vers[i] = P[i];
	return arrPushback((void**)t, (void*)&po);
}

void PolyListSave(Polygon* t, const char* fname) {
	if (t == NULL || fname == NULL) return;
	FILE* fp;
	errno_t err;;
	err = fopen_s(&fp, fname, "wb");
	if (fp == NULL) return;
	int nPoly = arrSize(t);
	for (int i = 0; i < nPoly; i++) {
		short n = t[i].nVers;
		void* pData = t[i].Vers;
		fwrite(&n, sizeof(n), 1, fp);
		fwrite(pData, sizeof(Point), n, fp);
	}
	fclose(fp);
}
//
void PolyListFree(Polygon* t) {
	if (t == NULL) return;
	int n = arrSize(t);
	for (int i = 0; i < n; i++)
		if (t[i].Vers != NULL) free(t[i].Vers);
	arrFree(t);
}
//
//
//
////typedef struct { short nVer; Point Vers[1]; } PolygonDat;
////typedef struct {
////	char* buf; // Data
////	long nBytes; // Size of file 
////	int nPoly;  // Amount of vertices
////	PolygonDat* operator[](int i) { //… }
////	} PolygonList;
////
//
////char* PolyRead(const char* fname, long& size) {
////	char* b = NULL;
////	FILE* fp;
////	errno_t err;
////	err = fopen_s(&fp, fname, "rb");
////	if (fp != NULL) {
////		fseek(fp, 0, SEEK_END); size = ftell(fp);
////		fseek(fp, 0, SEEK_SET);
////		b = (char*)malloc(size);
////		if (b != NULL) fread(b, size, 1, fp);
////		fclose(fp);
////	}
////	return b;
////}
//Polygon* PolyRead(const char* fname, int& n) {
//	FILE* fp = fopen(fname, "rb");
//	if (fp == NULL) return NULL;
//	n = 0;
//	Polygon* pList = (Polygon*)arrInit(0, sizeof(Polygon));
//	while (!feof(fp)) {
//		Polygon g = { 0 };
//		if (fread(&(g.nVer), sizeof(g.nVer), 1, fp) <= 0) break;
//		g.Vers = (Point*)malloc(g.nVer * sizeof(Point));
//		if (g.Vers != NULL) {
//			n++;
//			fread(g.Vers, g.nVer, sizeof(Point), fp);
//			arrPushback((void**)&pList, (void*)&g);
//		}
//	} fclose(fp);
//	return pList;
//}
//
//void CountPoly(PolygonList& pl) {
//	if (pl.buf == NULL) return;
//	char* pStart = pl.buf, * pEnd = pl.buf + pl.nBytes;
//	while (pStart < pEnd) {
//		short nVer = *(short*)pStart;
//		if (nVer > 0) pl.nPoly++;
//		pStart += sizeof(short) + nVer * sizeof(Point);
//	}
//}
//
//
//	void InitPolyList(PolygonList& p, const char* fname) {
//		p.nPoly = 0;
//		p.buf = PolyRead(fname, p.nBytes);
//		CountPoly(p);
//	}
//
//
//void ShowPoly(PolygonDat* pg) {
//	cout << pg->nVer << " dinh: ";
//	for (int i = 0; i < pg->nVer; i++)
//		cout << "(" << pg->Vers[i].x << ", " << pg->Vers[i].y << ") ";
//}

int main()
{
	Point dg1[] = { {1, 0}, {0, 5}, {5, 5} }; 
	int n1 = 3;
	Point dg2[] = { {4, 0}, {0, 5}, {5, 5}, {5, 0} };
	int n2 = 4;
	Point dg3[] = { {9, 0}, {0, 5}, {1, 1}, {5, 5}, {5, 0} }; 
	int n3 = 5;
	Polygon* lst = PolyListInit();
	if (lst != NULL) {
		PolyListPush(&lst, dg1, n1); PolyListPush(&lst, dg2, n2);
		PolyListPush(&lst, dg3, n3);
		PolyListSave(lst, "Polygons.dat");
		PolyListFree(lst);
	}

	//int nPoly;
	//Polygon* lst = PolyRead("Polygons.dat", nPoly);
	//if (lst) {
	//	for (int i = 0; i < nPoly; i++) {
	//		ShowPoly(&lst[i]); cout << endl;
	//	}
	//}
	//PolyListFree(lst);



	return 0;
}