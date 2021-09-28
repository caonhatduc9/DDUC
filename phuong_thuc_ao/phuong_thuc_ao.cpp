/*
* dung luu cac doi tuong khac kieu nhau va thao tac khac nhau
* tuong ung tung doi tuong
* chi hoat dong qua con tro
* chi can them tu khoa virtual truoc khai bao khong can dinh nghia o lop co so
* neu mot ham duoc khai bao ao o lop co so thi se ao o moi lop con
* ten phuong thuc o lop co so va lop dan xuat phai trung nhau
*/
#include<iostream>
using namespace std;
class Base {
public:
	virtual void show()
	{
		cout << "this is base class";
	}
	 
};
class Derived : public Base 
{
	void show() {
		cout << "\n this is derived class";
	}
};
int main(void) {
	Base *b;
	Derived d;
	b = &d;
	b->show();
	return 0;
}