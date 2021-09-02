#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;
struct Examine
{
	string id;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;
};
Examine readExaminee(string line_info)
{
	Examine e;
	string buf;
	stringstream doc(line_info);
	getline(doc, e.id, ',');
	getline(doc, buf, ',');
	e.math = atof(buf.c_str());
	getline(doc, buf, ',');
	e.literature = atof(buf.c_str());
	getline(doc, buf, ',');
	e.physic = atof(buf.c_str());
	getline(doc, buf, ',');
	e.chemistry = atof(buf.c_str());
	getline(doc, buf, ',');
	e.biology = atof(buf.c_str());
	getline(doc, buf, ',');
	e.history = atof(buf.c_str());
	getline(doc, buf, ',');
	e.geography = atof(buf.c_str());
	getline(doc, buf, ',');
	e.civic_education = atof(buf.c_str());
	getline(doc, buf, ',');
	e.natural_science = atof(buf.c_str());
	getline(doc, buf, ',');
	e.social_science = atof(buf.c_str());
	getline(doc, buf, ',');
	e.foreign_language = atof(buf.c_str());
	
	return e;
}
void showInfor(vector<Examine> e)
{
	int n = e.size();
	for (int i = 0; i < n; i++)
	{
		cout << e[i].id << "\t";
		cout << e[i].math << "\t";
		cout << e[i].literature << "\t";
		cout << e[i].physic << "\t";
		cout << e[i].chemistry << "\t";
		cout << e[i].biology << "\t";
		cout << e[i].history << "\t";
		cout << e[i].geography << "\t";
		cout << e[i].civic_education << "\t";
		cout << e[i].natural_science << "\t";
		cout << e[i].social_science << "\t";
		cout << e[i].foreign_language << endl << endl;
	}
}
vector<Examine> readExamineeList(string file_name) {
	vector<Examine> e;
	Examine buf;
	string line_infor;
	ifstream fin;
	fin.open(file_name);
	while (!fin.eof())
	{
		getline(fin, line_infor);
		e.push_back(readExaminee(line_infor));
	}	
	fin.close();
	return e;
}
void writeTotal(vector<Examine> examinee_list, string out_file_name)
{
	int n = examinee_list.size();
	int sum;
	string id;
	ofstream fout;
	fout.open(out_file_name);
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1) {
			sum = examinee_list[i].math + examinee_list[i].literature + examinee_list[i].foreign_language + examinee_list[i].physic + examinee_list[i].chemistry + examinee_list[i].biology + examinee_list[i].civic_education + examinee_list[i].geography + examinee_list[i].history;
			fout << examinee_list[i].id << " " << sum << "\n";
		}
		else {
			sum = examinee_list[i].math + examinee_list[i].literature + examinee_list[i].foreign_language + examinee_list[i].physic + examinee_list[i].chemistry + examinee_list[i].biology + examinee_list[i].civic_education + examinee_list[i].geography + examinee_list[i].history;
			fout << examinee_list[i].id << " " << sum;
		}
	}
	fout.close();
}
//Số Báo Danh, Họ và Tên, Toán, Ngữ Văn, Vật Lý, Hóa Học, Sinh Học, Lịch Sử, Địa Lý, GDCD, KHTN, KHXH, Ngoại Ngữ, Ghi Chú, Tỉnh
int main()
{
	vector<Examine> e;
	string line_infor;
	e=readExamineeList("data.txt");
	writeTotal(e, "fileOut.txt");
	showInfor(e);
}