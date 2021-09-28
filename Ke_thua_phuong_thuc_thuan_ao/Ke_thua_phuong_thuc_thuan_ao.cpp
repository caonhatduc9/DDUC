// thuan ao: pure virtual function
#include<iostream>
using namespace std;
class Base {
public:
	virtual void show() = 0;
	//{
	//	cout << "this is base class";
//	}
};
void Base::show() {
	cout << "this is base class";
}
class Derived : public Base
{
	void show() {
		Base::show();
		cout << "\n this is derived class";
	}
};
int main(void) {	
	Base* b;
	Derived d;
	b = &d;
	b->show();
	return 0;
}