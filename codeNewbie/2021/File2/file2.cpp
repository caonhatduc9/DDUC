#include<iostream>
#include<fstream>

using namespace std;
void converTtoB(const char* t, const char *b)
{
	ifstream fin;
	fin.open(t);
	ofstream fout;
	fout.open(b, ios::binary);
	short d, c;
	fin >> d >> c;
	cout << d << c;
	fout.write((char*)&d, sizeof(d));
	fout.write((char*)&c, sizeof(d));
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
		{
			int x;
			fin >> x;
			fout.write((char*)&x, sizeof(x));
		}
	fin.close();
	fout.close();
}

void converBtoT(const char* b, const char* t)
{
	ifstream fin;
	fin.open(b, ios::binary);
	ofstream fout;
	fout.open(t);
	short d, c;
	fin.read((char*)&d, sizeof(d));
	fin.read((char*)&c, sizeof(d));
	fout << d << " ";
	fout << c<<"\n";
	cout << d << c;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int x;
			fin.read((char*)&x, sizeof(x));
			fout << x << " ";
		}
		fout << "\n";
	}
	fin.close();
	fout.close();

}
int main()
{

	converTtoB("Text.txt", "test.dat");
	converBtoT("test.dat", "Text2.txt");
	return 0;
}