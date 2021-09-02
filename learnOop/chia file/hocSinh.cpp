#include "hocSinh.h"
void hocSinh::input()
{
	cout << "nhap ten: ";
	getline(cin, name);
	cout << "nhap dia chi: ";
	getline(cin, add);
	cout << "nhap diem toan: ";
	cin >> math;
	cout << "nhap diem van: ";
	cin >> lit;
}
void hocSinh::output() {
	cout << "hoc va ten: " << name;
	cout << "\ndia chi: " << add;
	cout << "\ndiem toan: " << math;
	cout << "\ndiem van: " << lit;
}