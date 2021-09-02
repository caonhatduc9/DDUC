#include "Mang2Chieu.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;
int main()
{
	srand(time(NULL));
	int a[100][100], b[100][100], d = 0, c = 0, db = 0, cb = 0;
	inputRandom(a, c, d);
	//input(a, d, c);
	output(a, d, c);
	
	//bai342
	cout << "\n";
	daoMaTran(a, d, c);
	output(a, d, c);

	rotateR(a, d, c, b, db, cb);
	output(b, db, cb);
}