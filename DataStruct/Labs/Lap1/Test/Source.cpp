//tuan 2 sua bai 20

#include<iostream>
#include<vector>
using namespace std;
int getToken(string& token, string s, int& starPos)
{
	string sep = ",";
	int fromPos, toPos, len = s.length(), nTokenLen = 0;
	 token = "";
	fromPos = s.find_first_not_of(sep,starPos);
	if (fromPos == string::npos)
		return nTokenLen;
	toPos = s.find_first_of(sep, fromPos);
	if (toPos == string::npos)
		toPos = len;
	nTokenLen = toPos - fromPos;
	token = s.substr(fromPos, nTokenLen);
	starPos = toPos;
	return nTokenLen;
}

int parseString(vector<string>& arrToken, string s)
{
	string token;
	int ntokens = 0, startPos = 0;
	while (getToken(token, s, startPos) > 0)
	{
		arrToken.push_back(token);
		ntokens++;
	}
	return ntokens;
}
int main(void)
{
	string s = "BD20127466,cao duc";
	vector<string> arrtoken;
	int ntoken;
	ntoken = parseString(arrtoken, s);
	for (int i = 0; i < arrtoken.size(); i++)
		cout << arrtoken[i] << "\t";
	return 0;
}