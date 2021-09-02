#ifndef function_h
#define function_h
struct Std
{
	int id;
	char name[50];
	float gpa;
};
 void loadFile(Std A[100], int& n);
 int findGpa(Std A[100], int n);
 void saveFile(Std A[100], int k);
#endif