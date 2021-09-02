#include <stdio.h>
int main()
{
	int i=1, n, s = 0;
	printf("nhap vao bien so ");
	scanf_s("%d", &n);
	while (n>0)
	{
		i = n % 10;
		s = s + i;
		n = n / 10;
		i++;
		
	}
	s = s % 10;
	printf("so nut: %d", s);
	return 0;
}