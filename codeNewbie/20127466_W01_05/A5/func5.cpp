#include"func5.h"
#include<fstream>
#include<string>
using namespace std;
void loadFile(Std A[100], int& n)
{
	ifstream inFile;
	inFile.open("input5.txt");
	inFile >> n;
	for (int i = 0; i < n; i++)
	{
		inFile >> A[i].id;
		inFile.ignore();
		inFile.getline(A[i].name, 100);
		inFile >> A[i].gpa;
	}
}
int  findGpa(Std  A[100], int n)
{
	int k;
	float max = 0;
	int id1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i].gpa > max || (A[i].gpa == max && A[i].id < id1))
		{
			max = A[i].gpa;
			id1 = A[i].id;
			k = i;
		}
	}
	return k;
} 
void saveFile(Std A[100], int k)
{
	ofstream outFile;
	outFile.open("output5.txt");
	outFile << A[k].id << "\n";
	outFile << A[k].name << "\n";
	outFile << A[k].gpa << "\n";
	outFile.close();

}