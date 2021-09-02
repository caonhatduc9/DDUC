#ifndef function_h
#define function_h

struct PS {
	float tu, mau;
};


void input(PS*& a, int& n);

void output(PS* a, int n);
void extractN(PS* a, int n, PS*& b, int& m);
PS operator+(PS a, PS b);
int UCLN(int a, int b);
void rutGon(int& a, int& b);
PS sumPos(PS* a, int n);
#endif // !function_h

