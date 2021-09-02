//#include<iostream>
//#include<malloc.h>
//#include<memory.h>
//#include<stdio.h>
//using namespace std;
///*void* malloc(int size)
//{
//	void* p = malloc(size + sizeof(int));
//	*(int*)p = size;
//	return ((int*)p) + 1;
//}
//int msize(void* p)
//{
//	return *(((int*)p) - 1);
//}
//
//void  mfree(void* p)
//{
//	p = ((int*)p) - 1;
//	free(p);
//}
//template <class T>
//struct Tarray
//{
//	int n;T *a;
//};
//template <class T>
//void nhap(Tarray *a)
//{
//	2w
//}*/
//
//struct studentDat {
//	int id;
//	char name[100];
//};
//struct studentList {
//	char* buf;
//	long nByte;
//	int nStudent;	
//	studentDat* operator[](int i)
//	{
//	
//	}
//};
//char* studentRead(const char* fname, long& size) {
//	char* b = NULL;
//	FILE* fp = fopen(fname, "rb");
//	if (fp != NULL) {
//		fseek(fp, 0, SEEK_END); size = ftell(fp);
//		fseek(fp, 0, SEEK_SET);
//		b = (char*)malloc(size);
//		if (b != NULL) fread(b, size, 1, fp);
//		fclose(fp);
//	}
//	return b;
//}
//void CountStudent(studentList& pl) {
//	if (pl.buf == NULL) return;
//	char* pStart = pl.buf, * pEnd = pl.buf + pl.nByte;
//	while (pStart < pEnd) {
//		short nVer = *(short*)pStart;
//		if (nVer > 0) pl.nstudent++;
//		pStart += sizeof(short) + nVer * sizeof(Point);
//	}
//}
//
//void InitStudentList(studentList& p, const char* fname)
//{
//	p.nStudent = 0;
//	p.buf = studentRead(fname, p.nByte);
//	CountPoly(p);
//}
//int main()
//{	
//
//
//}