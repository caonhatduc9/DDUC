#pragma once
#include<iostream>
#include<string>
using namespace std;

class hocSinh
{
private:
	string name, add;
	float math, lit;
public:
	//khai bao phuong thuc o file .h va cai dat o cpp
	void input();
	void output();
};

