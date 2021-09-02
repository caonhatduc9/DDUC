#include<iostream>
#include<string>
using namespace std;
class HOCSINH {
private:
	string name, add;
	float math, lit;
public:
	//cach 1 dinhj nghia trucw tiep tring class
	void input()
	{
		cout << "nhap ten: ";
		getline(cin, name);
		cout << "nhap dia chi";
		getline(cin, add);
		cout << "nhap diem toan: ";
		cin >> math;
		cout << "nhap diem van";
		cin >> lit;
	}
	//cach 2 khai bao trong class, dinh nghia ben ngoai
	void output();
};
// kieutrave tenclass::tenphuongthuc(){}
void HOCSINH::output() {
	cout << "hoc va ten: " << name;
	cout << "\ndia chi: " << add;
	cout << "\ndiem toan: " << math;
	cout << "\ndiem van: " << lit;
}
int main()
{
	HOCSINH hs;
	hs.input();
	hs.output();
	return 0;
}