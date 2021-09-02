#include <stdio.h>
#include <conio.h>
void main()
{
	float a, b, S;
	printf("nhap so tien dien thang truoc ");
	scanf_s("%f", &a);
	printf(" nhap so tien dien thang nay ");
	scanf_s("%f", &b);
	S = b - a;
	printf("ket qua: %f", S);
	_getch();
}
