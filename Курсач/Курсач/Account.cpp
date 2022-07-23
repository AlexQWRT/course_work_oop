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
		cout << "Введите логин (введите 0 чтобы вернуться к меню): ";
		cin >> username;
		if (username == "0")
		{
			return 0;
		}
		if (username.length() > 20)
		{
			system("cls");
			cout << "Введённый логин слишком длинный. Повторите ввод." << endl;
		}
	} while (username.length() > 20);
	system("cls");
	buf = username;
	do
	{
		cout << "Подтвердите логин (введите 0 чтобы вернуться к меню): ";
		cin >> username;
		if (username == "0")
		{
			return 0;
		}
		if (username != buf)
		{
			system("cls");
			cout << "Логин должен совпасть с уже введённым. Повторите ввод." << endl;
		}
	} while (username != buf);
	system("cls");

	while (password.length() < 8)
	{
		password = "";
		cout << "Введите пароль (введите 0 чтобы вернуться к меню): ";
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
			cout << "Введённый пароль слишком короткий. Повторите ввод." << endl;
		}
	}
	buf = password;
	system("cls");
	do
	{

		password = "";
		cout << "Подтвердите пароль (введите 0 чтобы вернуться к меню): ";
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
			cout << "Введённый пароль не совпадает с предыдущим. Повторите ввод." << endl;
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
	cout << '|' << setw(5) << '№' << '|' << setw(20) << "Логин" << '|' << setw(20) << "Пароль" << '|'
		<< setw(6) << "Админ" << '|';
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
		cout << "Создание аккаунта прервано." << endl;
		system("pause");
		system("cls");
		return;
	}
	accounts.push_back(temp);
	fin.open(accsfile, ios_base::app);
	temp.InFile(fin);
	fin.close();
	cout << endl << "Аккунт успешно создан." << endl;
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
		cout << "Введите логин (введите 0 для выхода в главное меню): ";
		cin >> buf;
		if (buf == "0")
		{
			system("cls");
			cout << "Вход не завершён." << endl;
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
			cout << "Введён неверный логин. Повторите ввод." << endl;
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
		cout << "Пользователь: " << accounts[usernum].GetUsername() << endl;
		cout << "Введите пароль (введите 0 для выхода в главное меню): ";
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
			cout << "Вход не завершён" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (accounts[usernum].GetPassword() == buf)
		{
			wasfound = true;
			system("cls");
			cout << "Вход выполнен успешно." << endl;
			system("pause");
			system("cls");
		}
		else
		{
			system("cls");
			cout << "Введён неверный пароль." << endl;
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
		cout << "Список пуст." << endl;
		system("pause");
		system("cls");
		return;
	}
	PrintAccountHead();
	for (int i = 0; i < accounts.size(); i++)
	{
		accounts[i].Print(i + 1);
	}
	while (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > accounts.size() || atoi(buf.c_str()) == NULL) //ввод кол-ва записей с проверкой
	{
		cout << "Введите номер пользователя, которому хотите дать права администратора" << endl;
		cin >> buf;
		if (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > accounts.size() || atoi(buf.c_str()) == NULL)
		{
			cout << "Введено неверное значение, повторите ввод" << endl;
		}
	}
	int accnum = atoi(buf.c_str());
	buf = "";
	while (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > 2 || atoi(buf.c_str()) == NULL) //ввод кол-ва записей с проверкой
	{
		cout << "Вы уверены?" << endl;
		cout << "1. Да" << endl;
		cout << "2. Нет" << endl;
		cin >> buf;
		if (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > 2 || atoi(buf.c_str()) == NULL)
		{
			cout << "Введено неверное значение, повторите ввод" << endl;
		}
	}
	if (buf == "2")
	{
		cout << "Редактирование отменено" << endl;
		system("pause");
		system("cls");
	}
	else {
		accounts[accnum - 1].SetAdmin(true);
		cout << "Успешно отредактировано" << endl;
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

