#include"Header.h"
#include<fstream>
#include<iostream>
using namespace std;
void docFile(P A[100],int &n)
{
	ifstream inFile;
	inFile.open("input.txt");
	inFile >> n;
	for (int i = 0; i < n; i++)
	{
		inFile >> A[i].Tu;
		inFile >> A[i].Mau;
	}
	inFile.close();
}
void tangDan(P A[100], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (A[i].Tu / A[i].Mau > A[j].Tu / A[j].Mau)
			{
				int a;
				a = A[i].Tu;
				A[i].Tu = A[j].Tu;
				A[j].Tu = a;
				int b;
				b = A[i].Mau;
				A[i].Mau = A[j].Mau;
				A[j].Mau = b;
			}
		}
	}
}

void saveFile(P A[100], int n)
{
	ofstream outFile;
	outFile.open("outPut.txt");
	outFile << n << "\n";
	for (int i = 0; i < n; i++)
	{
		outFile << A[i].Tu<<" ";
		outFile << A[i].Mau << "\n";
	}
	outFile.close();
}