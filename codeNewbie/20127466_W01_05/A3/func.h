#ifndef func_h
#define func_h
struct date
{
	int d, m, y;
};
void loadFile(date A[100], int& n);
void saveFile(date A[100], int n);
int comPare(date A, date B);
void swap(int& a, int& b);
void sort(date A[100], int n);
#endif // !func_h
