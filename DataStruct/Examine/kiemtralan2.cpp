#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
struct SV {
	string name;
	float math, literature, foreign_language;
};
SV readSV(string line_info)
{
	SV s;
	string buf;
	stringstream doc(line_info);
	getline(doc, s.name, ',');
	getline(doc, buf, ',');
	s.math = atof(buf.c_str());
	getline(doc, buf, ',');
	s.literature = atof(buf.c_str());
	getline(doc, buf, ',');
	s.foreign_language = atof(buf.c_str());
	return s;
}

vector<SV> readSVList(string file_name) {
	vector<SV> s;
	string line_infor;
	ifstream fin;
	fin.open(file_name);
	while (!fin.eof())
	{
		getline(fin, line_infor);
		s.push_back(readSV(line_infor));
	}
	fin.close();
	return s;
}
void showInfor(vector<SV> s)
{
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		cout << s[i].name << "\t";
		cout << s[i].math << "\t";
		cout << s[i].literature << "\t";
	
		cout << s[i].foreign_language << endl << endl;
	}
}
int main()
{
	vector<SV> s;
	s = readSVList("input.txt");
	showInfor(s);
	return 0;
}