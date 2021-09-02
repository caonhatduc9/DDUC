#include"array.h"
int main()
{
	int a[100], n = 0; 
	input(a, n);
/*	bai174(a, n);
	//bai230(a, n);
	//int k, x;
	//cout << "nhap k ,x ";
	//cin >> k >> x;
	bai266(a, n, k, x);
return 0;
sắp xếp mảng tăng dần*/
	sapxetangdan(a, n);
	xuatmang(a, n);
}