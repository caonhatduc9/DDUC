#include<iostream>
#include"function.h"
using namespace std;
int main()
{
	Student* s, *s1;
	int n, n1 = 0;
	input(s, n);
	outPut(s, n);
	//Find the list of students whose scores are less than 5 to an array.
	findScore(s, n, s1, n1);
	cout << "\n\nstudents have scores are less than 5: " << endl;
	if (n1 != 0)
		outPut(s1, n1);
	else
		cout << "\n\t\tno one\n\n";
	//Sort and display the list of students in ascending order based on their ID
	sortasc(s, n);
	cout << "sort id: ";
   outPut(s, n);
   //Sort and display the list of students in descending order based on their name
	sortName(s, n);
	cout << "sort name: ";
	outPut(s, n);
	//Find top 3 students who have the highest score
	cout << "\ntop 3:\n ";
	findMaxScore(s, n);
	FreeS(s,n);
	delete[] s;
	return 0;
}