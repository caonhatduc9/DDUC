#include <stdio.h>
int main()
{
	int k, k1, k2, k3, k4, k5, k6, k7, k8;
	long n;
	printf("nhap vao so tien");
	scanf_s("%ld", &n);
	k = n / 500000;
	n = n - k * 500000;
	printf("so to 500k: %d\n ", k);
	k1 = n / 200000;
	n = n - k1 * 200000;
	printf("so to 200k: %d\n ", k1);
	k2 = n / 100000;
	n = n - k2 * 100000;
	printf("so to 100k: %d\n ", k2);
	k3 = n / 50000;
	n = n - k3 * 50000;
	printf("so to 50k: %d\n ", k3);
	k4 = n / 20000;
	n = n - k4 * 20000;
	printf("so to 20k: %d\n ", k4);
	k5 = n / 10000;
	n = n - k5 * 10000;
	printf("so to 10k: %d\n ", k5);
	k6 = n / 5000;
	n = n - k6 * 5000;
	printf("so to 5k: %d\n ", k6);
	k7 = n / 2000;
	n = n - k7 * 2000;
	printf("so to 2k: %d\n ", k7);
	k8 = n / 1000;
	n = n - k8 * 1000;
	printf("so to 1k: %d ", k8);
}


		