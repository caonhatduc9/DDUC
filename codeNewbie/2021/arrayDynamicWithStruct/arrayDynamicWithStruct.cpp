//#include<iostream>
//using namespace std;
//typedef struct { int x, y; } Point;
//
//typedef struct { short nVer; Point* Vers; } Polygon;
//
//Polygon* PolyListInit() {
//	void* a = arrInit(0, sizeof(Polygon));
//	return (Polygon*)a;
//}
//
//
//void PolyListSave(Polygon* t, const char* fname) {
//	if (t == NULL || fname == NULL) return;
//	FILE* fp = fopen(fname, “wb”);
//	if (fp == NULL) return;
//	int nPoly = arrSize(t);
//	for (int i = 0; i < nPoly; i++) {
//		short n = t[i].nVer;
//		void* pData = t[i].Vers;
//		fwrite(&n, sizeof(n), 1, fp);
//		fwrite(pData, sizeof(Point), n, fp);
//	}
//	fclose(fp);
//}
//
//
//
//
//void main() {
//	//…
//	if (lst != NULL) {
//		//…
//		PolyListSave(lst, “Polygons.dat”);
//		PolyListFree(lst);
//	}
//}
