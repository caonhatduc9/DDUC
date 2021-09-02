#ifndef function_h
#define function_h
#include<iostream>
using namespace std;
struct Student {
	int id;
	char* name;
	double Score;
	char* adr;
};
void input(Student* &s, int& n);
void outPut(Student* s, int n);
void FreeS(Student  * &s,int n);
void findScore(Student* s, int n, Student* &s1, int &n1);
void sortasc(Student* &s, int n);
void sortName(Student* &s, int n);
void findMaxScore(Student* s, int n);
#endif // !function_h
