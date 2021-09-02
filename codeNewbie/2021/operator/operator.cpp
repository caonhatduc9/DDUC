#include<iostream>
using namespace std;
struct comp {
	int r, i;
};
istream& operator>>(istream& is, comp& c)
{
	cout << "nhap phan thuc: ";
	is >> c.r;
	cout << "nhap phan ao: ";
	is >> c.i;
	return is;
}

ostream& operator<<(ostream& os, comp c)
{
	os << c.r <<" + "<< c.i << "i";
	return os;
}
comp operator+(comp a, comp b)
{
	comp c;
	c.r = a.r + b.r;
	c.i = a.i + b.i;
	return c;
}
bool NguyenTo(unsigned long n)
{
	long m = (long)sqrt(n);
	for (long k = 2; k <= m && n % k; k++)
	return k > m;
}
int main() 
{
	long n=6;

	cout<<NguyenTo(n);
	return 0;
}