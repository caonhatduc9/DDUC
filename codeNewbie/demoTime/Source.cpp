#include <iostream>
#include <ctime>

using namespace std;

bool isLeepYear(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;
}
int dayOfMonth(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		nNumOfDays = 30;
		break;
	case 2:
		if (isLeepYear(nYear))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}
void lastDay(int& nDay, int& nMonth, int& nYear)
{
	nDay--;
	if (nDay == 0)
	{
		nMonth--;
		if (nMonth == 0)
		{
			nMonth = 12;
			nYear--;
		}
		nDay = dayOfMonth(nMonth, nYear);
	}
}
void currentDay(int &day, int &month, int &year)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	day = ltm.tm_mday;
	month = ltm.tm_mon + 1;
	year = ltm.tm_year + 1900;
}

int main() {
	tm ltm;
	int d, m, y;
	currentDay(d, m, y);

	// in ra các thành phần của cấu trúc tm struct
	cout << "Year: " << y << endl;
	cout << "Month: " <<m << endl;
	cout << "Day: " << d << endl;
	
}