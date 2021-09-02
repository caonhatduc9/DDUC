#include"func4.h"
#include<fstream>
#include<iostream>
using namespace std;
void loadFile(DT A[100], int& n)
{
	ifstream inFile;
	inFile.open("input4.txt");
	inFile >> n;
	for (int i = 0; i < n; i++)
	{
		inFile >> A[i].id;
		inFile.ignore();
		inFile.getline(A[i].name, 51);
		inFile >> A[i].st;
		inFile >> A[i].pr;
	}
	inFile.close();
}
int totalPrice(DT A[100], int n)
{
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		p = p + A[i].pr*A[i].st;
	}
	return p;
}

void saveFile(int p)
{
	ofstream saveFile;
	saveFile.open("output4.txt");
	saveFile << p;
	saveFile.close(); 
}