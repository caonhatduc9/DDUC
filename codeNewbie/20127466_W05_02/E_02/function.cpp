#include"function.h"

void input(Student*& s, int& n)
{
	cout << "\nnhap n(n>=3): ";
	cin >> n;
	s = new Student[n];
	for (int i = 0; i < n; i++)
	{
		cout << "\nenter ID: ";
		cin >> s[i].id;
		cout << "enter Name: ";
		s[i].name = new char[50];
		cin.ignore();
		cin.getline(s[i].name, 50);
		cout << "enter Score: ";
		cin >> s[i].Score;
		cin.ignore();
		cout << "enter address: ";
		s[i].adr = new char[100];
		cin.getline(s[i].adr, 100);
	}
}

void outPut(Student* s, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "\n\tID: " << s[i].id << endl;
		cout << "\tname: " << s[i].name << endl;
		cout << "\tscore: " << s[i].Score << endl;
		cout << "\taddress: " << s[i].adr << endl;
	}
}
void FreeS(Student * &s,int n)
{
	for (int i = 0; i < n; i++) {
		if (s[i].name!= NULL)
			delete[] s[i].name;
		if (s[i].adr != NULL)
			delete[] s[i].adr;
	}
}
void findScore(Student* s, int n, Student* &s1, int& n1)
{

	for (int i = 0; i < n; i++)
	{
		if (s[i].Score < 5)
			n1++;
	}
	if (n1 == 0)
		return;
		int j = 0;
		s1 = new Student[n1];
		for (int i = 0; i < n; i++)
			if (s[i].Score < 5)
			{
				s1[j] = s[i];
				j++;
			}
}
void sortasc(Student* &s, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i+1; j < n; j++)
			if (s[i].id > s[j].id)
			{
				Student t;
				t.name = new char[50];
				t.adr = new char[100];
				t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
}
void sortName(Student* &s, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(s[i].name, s[j].name) < 0)
			{
				Student temp;
				temp.name = new char[50];
				temp.adr = new char[100];
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
}
void findMaxScore(Student* s, int n)
{
	if (n < 4)
	{
		Student* s3 = new Student[n];
		for (int i = 0; i < n; i++)
			s3[i] = s[i];
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (s3[i].Score < s3[j].Score)
				{
					Student t;
					t.name = new char[50];
					t.adr = new char[100];
					t = s3[i];
					s3[i] = s3[j];
					s3[j] = t;
				}
		outPut(s3, n);
		return;
	}
	Student* s4 = new Student[n];
	for (int i = 0; i < n; i++)
	{
		s4[i] = s[i];
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (s4[i].Score < s4[j].Score)
			{
				Student t;
				t.name = new char[50];
				t.adr = new char[100];
				t = s4[i];
				s4[i] = s4[j];
				s4[j] = t;
			}
	outPut(s4, 3);
}
