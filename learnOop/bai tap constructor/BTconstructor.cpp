#include<iostream>
#include<string>
using namespace std;
class sophuc {
private:
	int phanThuc, phanAo;
public:
	sophuc()
	{
		phanThuc = 1;
		phanAo = 1;
	}
	sophuc(int thuc, int ao)
	{
		this->phanAo = ao;
		phanThuc = thuc;
	}
};
class Time {
private:
	int gio, phut, giay;
public:
	Time(int h, int p, int g)
	{
		gio = h;
		phut = p;
		giay = g;
	}
	Time(int h, int s)
	{
		gio = h;
		phut = 0;
		giay = s;
	}
	Time() {}
};
int main()
{
	Time t;
	return 0;
}