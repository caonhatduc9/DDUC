
//	char chuoi[99];
	//cin.getline(chuoi, 99);
	//cout << chuoi << endl;
	
	//bai1 dem khoang trang trong chuoi
	/*char chuoi[99];
	cin.getline(chuoi, 99);
	int dem = 0;
	int n = strlen(chuoi);
	for (int i = 0; i < n; i++)
	{
		if (chuoi[i] == ' ')
			dem++;
	}
	if (dem == 0)
		cout << "\nKhong co kis tu trang";
	else
		cout << dem;*/
	//bai 2 laoi bo kis tu trang trong chuoi
	/*int n = strlen(chuoi), k;
	for (int i = 0; i < n; i++)
	{
		if (chuoi[i] == 32)
		{
			for (int j = i; j < n; j++)
			{
				chuoi[j] = chuoi[j + 1];
				i--;
			}
		}
	}
	cout << chuoi;*/
	//BAI3 nhap vao hai chuoi noi chuoi 2 vao chuoi 1
	/*char chuoi2[99];
	cin.getline(chuoi2, 99);
	strcat_s(chuoi, chuoi2);
	cout << chuoi;*/
	//bai4 doi thanh ki tu thuong
	/*for (int i = 0; i < strlen(chuoi); i++)
	{
		if (chuoi[i] >= 65 && chuoi[i] < 97)
			chuoi[i] = chuoi[i] + 32;
	}
	cout << chuoi;
//FIBONACI
	int m = 200;
	float n = 5.6;
	void* p;
	p = &m;
	cout << p << endl;
	(*(int*)p) = 10;
	cout << m << endl;
	p = &n;
	(*(float*)p) = 45.7;	cout << n << endl;


	return 0;
}
int fib(int n)
{
	if (n <= 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}
void xuat(int n)
{
	for (int i = 1; i <= n; i++)
		cout << fib(i) << "\t";
	
}*/

