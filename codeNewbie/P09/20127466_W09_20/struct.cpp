#include"struct.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
void inputDate(date& d)
{
	cout << "day: ";
	cin >> d.day;
	cout << "month: ";
	cin >> d.month;
	cout << "year: ";
	cin >> d.year;
}
void outputDate(date d)
{
	cout << "\t" << d.year << "/" << d.month << "/" << d.day;
}
void docFiledate(date &d)
{
		ifstream file;
		file.open("Date.txt");
		if (! file) 
			cout << "khong mo duoc file";
		else
		{
			file >> d.year;
			file >> d.month;
			file >> d.day;
		}
			file.close();
	}
void saveFileDate(date d)
{
	
	ofstream file1;
	file1.open("saveDate.txt");
	file1 << d.year << " ";
	file1 << d.month << " ";
	file1 << d.day;
	file1.close();
}
int  CMPDay(date &d1, date &d2)
{
	cout << "nhap ngay thu nhat" << endl;
	inputDate(d1);
	cout << "nhap ngay thu nhat" << endl;
	inputDate(d2);
	if (d1.year < d2.year)
		return -1;
	else if (d1.year > d2.year)
		return 1;
	else
	{
		if (d1.month < d2.month)
			return -1;
		else if (d1.month > d2.month)
			return 1;
		else
		{
			if (d1.day < d2.day)
				return -1;
			else if (d1.day > d2.day)
				return 1;
			else return 0;
		}
	}
}

int  daymaxInMonth(int m, int y)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
	else
	{
		if (y % 4 == 0 && y % 100!=0 || y % 400 == 0)
			return 29;
		else return 28;
	}
}

void findTomorrow(date d)
{
	if (d.month < 12)
	{
		if (d.day < daymaxInMonth(d.month, d.year))
			d.day++;
		else if (d.day == daymaxInMonth(d.month, d.year))
		{
			d.day = 1;
			d.month++;
		}
	}
	if (d.month == 12)
	{
		if (d.day < daymaxInMonth(d.month, d.year))
			d.day++;
		else if (d.day == daymaxInMonth(d.month, d.year))
		{
			d.day = 1;
			d.month = 1;
			d.year++;
		}
	}
	cout << d.year << "/" << d.month << "/" << d.day;
}

void findYesterday(date d)
{
	if (d.day == 1)
	{
		if (d.month == 1)
		{
			d.day = 31;
			d.month = 12;
			d.year--;
		}
		else
		{
			d.month--;
				d.day = daymaxInMonth(d.month, d.year);
		}
	}
	else
	{
		d.day--;
	}
	cout << d.year << "/" << d.month << "/" << d.day;
}

int checkYear(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return 366;
	return 365;
}

/*void findDayK(date d)
{
	int ngayTrongNam = d.day, flag = 0, month = 1, k;
	cout << "nhap k ngay\t";
	cin >> k;
	for (int i = 1; i < d.month; i++)
	{
		ngayTrongNam += daymaxInMonth(i, d.year);
	}
	flag = ngayTrongNam + k;
	if (flag <= checkYear(d.year))
		while ()
		{

		}
	cout << d.day << "/" << month << "/" << d.year;
}*/
void distance(date d)
	{
		int ngayTrongNam = d.day, dis = 0;
		for (int i = 1; i < d.month; i++)
		{
			ngayTrongNam += daymaxInMonth(i, d.year);
		}
		dis = ngayTrongNam - 1;
		cout << dis;
	}
int distance2()
{
	date d1, d2;
	inputDate(d1);
	inputDate(d2);
	int n1 = d1.day;
	for (int i = 1; i < d1.month; i++)
		n1 += daymaxInMonth(i, d1.year);
	int n2 = d2.day;
	for (int i = 1; i < d2.month; i++)
		n2 += daymaxInMonth(i, d2.year);
	int soNgayN1N2 = 0;
	if (d1.year > d2.year)
		{
		int y;
		y = d1.year;
		d1.year = d2.year;
		d2.year = y;
		}
	for (int i = d1.year; i < d2.year; i++)
		soNgayN1N2 = soNgayN1N2 + 365 + daymaxInMonth(2, i) - 28;
	int dis = n2 - n1 + soNgayN1N2;
	return dis;
}

int distance3()
{
	date d1, d2;
	inputDate(d1);
	d2.day = 1;
	d2.month = 1;
	d2.year = 1970;
	int n1 = d1.day;
	for (int i = 1; i < d1.month; i++)
		n1 += daymaxInMonth(i, d1.year);
	int n2 = d2.day;
	int soNgayN1N2 = 0;
	if (d1.year > 1970)
	{
		int y;
		y = d1.year;
		d1.year = d2.year;
		d2.year = y;
	}
	for (int i =d1.year ; i < d2.year; i++)
		soNgayN1N2 = soNgayN1N2 + 365 + daymaxInMonth(2, i) - 28;
	int dis = n2 - n1 + soNgayN1N2;
	return dis;
}

void inputStudent(student& st)
{
	cout << "ID: ";
	cin >> st.id;
	cin.ignore(1);

	cout << "Full name: ";
	cin.getline(st.fullname, 51);

	cout << "Address: ";
	cin.getline(st.address, 51);

	cout << "GPA: ";
	cin >> st.gpa;

	cout << "Date of birth: ";
	inputDate(st.dob);
}

void outputStudent(student st) 
{
	cout << "ID: " << st.id << endl;
	cout << "Full name: " << st.fullname << endl;
	cout << "GPA: " << st.gpa << endl;
	cout << "Address: " << st.address << endl;
	cout << "DOB: ";
	outputDate(st.dob);
	cout << endl;

}
void loadStudent(student &st)
{
	
	ifstream file;
	file.open("student.txt",ios::in);
	if (!file)
		cout << "khong mo dc\n";
	else
	{
		
		file >> st.id;
		file.ignore();
		file.getline(st.fullname, 51);
		file >> st.gpa;
		file.ignore();
		file.getline(st.address, 101);
		file >> st.dob.day >> st.dob.month >> st.dob.year;
		file.close();
	}
}

void saveStudent(student st)
{
	ofstream file1;
	file1.open("savestudent.txt",ios::in);
	file1 << st.id << "\n";
	file1 << st.fullname << "\n";
	file1 << st.gpa << "\n";
	file1 << st.address << "\n";
	file1 << st.dob.day << " ";
	file1 << st.dob.month << " ";
	file1 << st.dob.year << " ";
	file1.close();
	
}