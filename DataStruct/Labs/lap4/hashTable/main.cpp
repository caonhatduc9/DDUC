#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct Company {
	string name, profit_tax, address;
};
void show(vector<Company> c)
{
	int n = c.size();
	for (int i = 0; i < 1250; i++)
	{
		cout << c[i].name << "|" << c[i].profit_tax << "|" << c[i].address << i << endl;
	}
}
vector<Company> readcompanyList(string fileName)
{
	vector<Company> com;
	ifstream f;
	f.open("MST.txt");
	string infor;
	getline(f, infor);
	Company c;
	while (!f.eof())
	{
		getline(f, infor);
		stringstream buf(infor);
		getline(buf, c.name, '|');
		getline(buf, c.profit_tax, '|');
		getline(buf, c.address);
		com.push_back(c);
	}
	f.close();
	return com;
}

long long abcx(int i, long long ans)
{
	for (int j = 0; j <= i; j++)
	{
		if (j == 0)
			ans = 1;
		else
			ans *= 31;
		ans %= 1000009;
	}
	return ans;
}
long long HashString(string company_name)
{
	long long val = 0;
	int n = company_name.size();
	//	if (n > 21)

	if (n > 20) {
		company_name = company_name.substr(company_name.size() - 20, 20);
		n = company_name.size();
	}
	for (int i = 0; i < n; i++)
	{
		int x = company_name[i], ans = 1;
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				ans = 1;
			else
				ans *= 31;
			ans %= 1000009;
		}
		val += (ans * x) % 1000009;
	}
	return val;
}
bool isPrime(int n) {
	for (int i = 2; i < n; i++)
		if (n % i == 0) {
			// n chia hết cho số khác 1 và chính nó.
			return false;
		}
	return n > 1;
}
Company* createhashtable(vector<Company> list_company)
{
	Company* c = new Company[2000];
	int idx;
	int temp;

	for (int i = 0; i < 2000; i++)
		c[i] = { "","","" };
	//cout << endl << list_company.size() << endl;
	for (int i = 0; i < list_company.size(); i++) {
		idx = HashString(list_company[i].name) % 2000;
		if (c[idx].name == "")
			c[idx] = list_company[i];
		else
		{
			temp = (HashString(list_company[i].name) + 1) % 2000;
			while (c[temp].name != "")
				temp = (temp + 1) % 2000;
			c[temp] = list_company[i];
		}
	}
	return c;
}
void insert(Company* &hashTable, Company company)
{
	int idx = HashString(company.name) % 2000;
	if (hashTable[idx].name == "")
		hashTable[idx] = company;
	else
	{
		int temp = (HashString(company.name) + 1) % 2000;
		while (hashTable[temp].name != "")
			temp = (temp + 1) % 2000;
		hashTable[temp] = company;
	}
}
Company *Search(Company* hashTable, string company_name)
{
	int idx = HashString(company_name) % 2000;
	if (hashTable[idx].name == "")
		return NULL;
	while (hashTable[idx].name != company_name)
	{
		if (hashTable[idx].name == "")
			return NULL;
		idx = (idx + 1) % 2000;
	}
	return &hashTable[idx];
}

int main()
{
	Company i = { "CONG TY TNHH MOT MINH TAO","69696969","TP.hcm" };
	Company* c = createhashtable(readcompanyList("MST.txt"));
	insert(c, i);
	for (int i = 0; i < 2000; i++)
	{
		if (c[i].name != "")
			cout << i << "\t" << c[i].name << endl;
	}
	Company* z = Search(c, "CONG TY TNHH MOT MINH TAOl");
	if (z == NULL)
		cout << "\n\t\t\tkhong tim thay";
	else
		cout << z->name << " " << z->profit_tax << " " << z->address;
	return 0;
}