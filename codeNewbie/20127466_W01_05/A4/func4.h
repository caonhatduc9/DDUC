#ifndef function_h
#define function_h
struct DT
{
	int id;
	char name[100];
	int st;
	int pr;
};

void loadFile(DT A[100], int& n);
int totalPrice(DT A[100], int n);
void saveFile(int p);
#endif