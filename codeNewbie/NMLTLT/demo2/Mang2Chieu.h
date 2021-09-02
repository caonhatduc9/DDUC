#ifndef mang2chieu_h
#define mang2chieu_h
void inputRandom(int a[100][100], int &n, int &m);
void input(int a[100][100], int& n, int& m);
void output(int a[100][100], int n, int m);
int min(int a, int b);
int sum(int a[100][100], int n, int m);
bool isprime(int n);
int checkPrimeMaTran(int a[100][100], int n, int m);
int sumDong(int a[100][100], int n, int m, int k);
int tinhTongTungDong(int a[100][100], int m, int n);
void xuatTheoDong(int a[][100], int d, int c);
void xuatTheoCot(int a[][100], int d, int c);
void tinhTongBien(int a[][100], int d, int c);
//bai342
int b342(int a[][100], int d, int c);
//bai344
//void bai344(int a[100][100], int c, int d);
void bai344_2(int a[100][100], int d, int c);
//bai346
void bai346(int a[][100], int d, int c);


//phanSo tinhTongphanSo(phanSo a, phanSo b);

void daoMaTran(int a[][100], int d, int c);
void daoMaTran(int a[][100], int d, int c);
void daoCot(int a[][100], int d, int c);
void rotateR(int a[][100], int d, int c);
void rotateR(int a[][100], int d, int c, int b[][100], int& cb, int& cc);

#endif // !mang2chieu_h


