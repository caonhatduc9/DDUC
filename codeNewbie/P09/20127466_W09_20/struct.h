#ifndef struct_h
#define struct_h
struct date
{
	int day, month, year;
};

struct student
{
	int id;
	char fullname[51];
	double gpa;
	char address[101];
	date dob;
};

void inputDate(date& d);
void outputDate(date d);
void docFiledate(date &d);
void saveFileDate(date d);
int CMPDay(date &d1, date &d2);
int  daymaxInMonth(int m, int y);
void findTomorrow(date d);
void findYesterday(date d);
void distance(date d);
int distance2();
int distance3();

void inputStudent(student& st);
void outputStudent(student st);
void loadStudent(student &st);
void saveStudent(student st);

#endif // !struct_h
