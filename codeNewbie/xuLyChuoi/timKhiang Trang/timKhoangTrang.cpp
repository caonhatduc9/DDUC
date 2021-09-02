#include<iostream>
#include<string>
using namespace std;
int main()
{
	string chuoi1;
	cout << "nhap chuoi: ";
	getline(cin, chuoi1);

	cout << chuoi1 << endl;

	/*string sample = "Access to the first and the last element";
	cout << "First: " << sample.front() << endl;// lay kí tự đầu tiên 
	cout << "Last: " << sample.back() << endl;// lấy kí tự cuối
	chuoi1.push_back('.');//THEM KÍ TỰ VÀO CUỐI CHUỖI
	if (!chuoi1.empty())
		chuoi1.pop_back()// XÓA KÍ TỰ CUỐI CÙNG
	chuoi1 += "add"*/
	chuoi1.append("Thao quyen");
	cout << chuoi1;
	return 0;
}