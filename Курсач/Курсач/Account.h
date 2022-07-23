#pragma once
#include <string>
#include <fstream>
using namespace std;
using std::string;
class Account
{
	string username;
	string password;
	bool isadmin = false;
public:
	bool Set();
	string GetUsername();
	string GetPassword();
	bool GetAdmin();
	void SetAdmin(bool isadmin);
	void Print(int index);
	void InFile(ofstream& f);
	Account OutFile(ifstream& f);
};

