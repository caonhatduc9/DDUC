#include"func.h"
#include <iostream>
#include<fstream>
using namespace std;
void loadFile(cir A[100], int& n)
{
	ifstream inFile;
	inFile.open("input2.txt");
	inFile >> n;
	for (int i = 0; i < n; i++)
	{
		inFile >> A[i].x;
		inFile >> A[i].y;
		inFile >> A[i].r;
	}
	inFile.close();
}
int area(cir A[100], int n)
{
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + A[i].r * A[i].r * 3.14;
	}
	return s;
}
void saveFile(float s)
{
	ofstream outFile;
	outFile.open("output2.txt");
	outFile << s;
	outFile.close();
}
