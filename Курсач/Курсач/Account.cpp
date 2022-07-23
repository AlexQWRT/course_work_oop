#include "Account.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <vector>
using namespace std;

bool Account::Set()
{
	string buf;
	do
	{
		cout << "������� ����� (������� 0 ����� ��������� � ����): ";
		cin >> username;
		if (username == "0")
		{
			return 0;
		}
		if (username.length() > 20)
		{
			system("cls");
			cout << "�������� ����� ������� �������. ��������� ����." << endl;
		}
	} while (username.length() > 20);
	system("cls");
	buf = username;
	do
	{
		cout << "����������� ����� (������� 0 ����� ��������� � ����): ";
		cin >> username;
		if (username == "0")
		{
			return 0;
		}
		if (username != buf)
		{
			system("cls");
			cout << "����� ������ �������� � ��� ��������. ��������� ����." << endl;
		}
	} while (username != buf);
	system("cls");

	while (password.length() < 8)
	{
		password = "";
		cout << "������� ������ (������� 0 ����� ��������� � ����): ";
		do
		{
			char bufsym = _getch();
			if (bufsym == '\b')
			{
				if (password.length() > 0)
				{
					cout << "\b \b";
					password = password.substr(0, password.length() - 1);
				}
			}
			else if (bufsym != 13)
			{
				password += bufsym;
				cout << '*';
			}
			else
			{
				break;
			}
		} while (password.length() < 20);
		if (password == "0")
		{
			return 0;
		}
		if (password.length() < 8)
		{
			system("cls");
			cout << "�������� ������ ������� ��������. ��������� ����." << endl;
		}
	}
	buf = password;
	system("cls");
	do
	{

		password = "";
		cout << "����������� ������ (������� 0 ����� ��������� � ����): ";
		do
		{
			char bufsym = _getch();
			if (bufsym == '\b')
			{
				if (password.length() > 0)
				{
					cout << "\b \b";
					password = password.substr(0, password.length() - 1);
				}
			}
			else if (bufsym != 13)
			{
				password += bufsym;
				cout << '*';
			}
			else
			{
				break;
			}
		} while (password.length() < 20);
		if (password == "0")
		{
			return 0;
		}
		if (password != buf)
		{
			system("cls");
			cout << "�������� ������ �� ��������� � ����������. ��������� ����." << endl;
		}
	} while (password != buf);
	return 1;
}

void Account::Print(int index)
{
	cout << '|' << setw(5) << index << '|' << setw(20) << username << '|' << setw(20) << password << '|'
		<< setw(6) << isadmin << '|';
	cout << endl << ' ';
	for (int i = 0; i < 54; i++)
		cout << '-';
	cout << endl;
}

void Account::InFile(ofstream& f)
{
	f << endl << username << ' ' << password << ' ' << isadmin;
}

Account Account::OutFile(ifstream& f)
{
	f >> username >> password >> isadmin;
	return *this;
}

string Account::GetUsername()
{
	return username;
}

string Account::GetPassword()
{
	return password;
}

bool Account::GetAdmin()
{
	return isadmin;
}

void Account::SetAdmin(bool isadmin)
{
	this->isadmin = isadmin;
}

void PrintAccountHead()
{
	cout << ' ';
	for (int i = 0; i < 54; i++)
		cout << '-';
	cout << endl;
	cout << '|' << setw(5) << '�' << '|' << setw(20) << "�����" << '|' << setw(20) << "������" << '|'
		<< setw(6) << "�����" << '|';
	cout << endl << ' ';
	for (int i = 0; i < 54; i++)
		cout << '-';
	cout << endl;
}

void Registration(ofstream& fin, string accsfile, vector<Account>& accounts)
{
	system("cls");
	Account temp;
	if (!temp.Set())
	{
		system("cls");
		cout << "�������� �������� ��������." << endl;
		system("pause");
		system("cls");
		return;
	}
	accounts.push_back(temp);
	fin.open(accsfile, ios_base::app);
	temp.InFile(fin);
	fin.close();
	cout << endl << "������ ������� ������." << endl;
	system("pause");
	system("cls");
}

void Admin();
void User();
void Login(vector<Account> accounts)
{
	system("cls");
	string buf = "";
	bool wasfound = false;
	int usernum;
	do
	{
		cout << "������� ����� (������� 0 ��� ������ � ������� ����): ";
		cin >> buf;
		if (buf == "0")
		{
			system("cls");
			cout << "���� �� ��������." << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i].GetUsername() == buf)
			{
				wasfound = true;
				usernum = i;
			}
		}
		if (!wasfound)
		{
			system("cls");
			cout << "����� �������� �����. ��������� ����." << endl;
		}
		else
		{
			system("cls");
		}
	} while (!wasfound);
	
	wasfound = false;
	do
	{
		buf = "";
		cout << "������������: " << accounts[usernum].GetUsername() << endl;
		cout << "������� ������ (������� 0 ��� ������ � ������� ����): ";
		while (true)
		{
			char bufsym = _getch();
			if (bufsym == '\b')
			{
				if (buf.length() > 0)
				{
					cout << "\b \b";
					buf = buf.substr(0, buf.length() - 1);
				}
			}
			else if (bufsym != 13)
			{
				buf += bufsym;
				cout << '*';
			}
			else
			{
				break;
			}
		}
		if (buf == "0")
		{
			system("cls");
			cout << "���� �� ��������" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (accounts[usernum].GetPassword() == buf)
		{
			wasfound = true;
			system("cls");
			cout << "���� �������� �������." << endl;
			system("pause");
			system("cls");
		}
		else
		{
			system("cls");
			cout << "����� �������� ������." << endl;
			system("pause");
			system("cls");
		}
	} while (!wasfound);
	if (accounts[usernum].GetAdmin())
	{
		Admin();
		system("cls");
		return;
	}
	else
	{
		User();
		system("cls");
		return;
	}
}

void EditAccount(vector<Account>& accounts, ofstream& fin, string accsfile)
{
	system("cls");
	string buf;
	if (accounts.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	PrintAccountHead();
	for (int i = 0; i < accounts.size(); i++)
	{
		accounts[i].Print(i + 1);
	}
	while (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > accounts.size() || atoi(buf.c_str()) == NULL) //���� ���-�� ������� � ���������
	{
		cout << "������� ����� ������������, �������� ������ ���� ����� ��������������" << endl;
		cin >> buf;
		if (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > accounts.size() || atoi(buf.c_str()) == NULL)
		{
			cout << "������� �������� ��������, ��������� ����" << endl;
		}
	}
	int accnum = atoi(buf.c_str());
	buf = "";
	while (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > 2 || atoi(buf.c_str()) == NULL) //���� ���-�� ������� � ���������
	{
		cout << "�� �������?" << endl;
		cout << "1. ��" << endl;
		cout << "2. ���" << endl;
		cin >> buf;
		if (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > 2 || atoi(buf.c_str()) == NULL)
		{
			cout << "������� �������� ��������, ��������� ����" << endl;
		}
	}
	if (buf == "2")
	{
		cout << "�������������� ��������" << endl;
		system("pause");
		system("cls");
	}
	else {
		accounts[accnum - 1].SetAdmin(true);
		cout << "������� ���������������" << endl;
		fin.open(accsfile, ios_base::in);
		for (int i = 0; i < accounts.size(); i++)
		{
			accounts[i].InFile(fin);
		}
		fin.close();
		system("pause");
		system("cls");
	}
}

