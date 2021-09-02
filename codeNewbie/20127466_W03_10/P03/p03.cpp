// 20127466
// Cao Nhat Duc
// CLC07

// test case 1
// input: 
// output: 

// test case 2
// input: 
// output: 

// test case 3
// input: 
// output: 

#include <stdio.h>
int main()
{
	int cheat;
	float asmt, labt, lt, s;
	printf("nhap diem bai tap");
	scanf_s("%f", &asmt);
	printf("\nnhap diem thuc hanh");
	scanf_s("%f", &labt);
	printf("\nnhap diem ly thuyt");
	scanf_s("%f", &lt);
	printf("\nneu thi sinh gian lan nhap 1, neu khong nhap 0: ");
	scanf_s("%d", &cheat);
	if (cheat == 1)
	{
		printf("       FAILED");
	}
	if (cheat == 0)
	{
		s = (asmt * 3.0 / 10) + (labt * 3.0 / 10) + (lt * 4.0 / 10);
		printf(" diem tong: %.1f\n", s);
		if (s < 5)
		{
			printf("   FAILED\n");
		}
		else
		{
			printf("                PASSED");
		}
	}
}
