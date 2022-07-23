#pragma warning(disable: 4996)
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <conio.h>
#include "Student.h"
#include "Menu.h"
#include "Account.h"
using namespace std;

string buf; //строка для ввода данных и их проверки
vector<Student> students; //односвязный список с записями о студентах
vector<Account> accounts;
ofstream fin; //поток для ввода в файл
ifstream fout; //поток для вывода из файла
string accsfile = "accs.txt"; //имя файла с аккаунтами
string studsfile = "stud.txt"; //имя файла со студентами

void PrintAccountHead();
void PrintHead();
void DownloadFromFile(ifstream& fout, string studsfile, vector<Student>& students);
void AddAtList(vector<Student>& students);
void PrintAllList(vector<Student> students);
void Registration(ofstream& fin, string accsfile, vector<Account>& accounts);
void Login(vector<Account> accounts);
void EditAccount(vector<Account>& accounts, ofstream& fin, string accsfile);
void DeleteStudent(vector<Student>& students);
void EditStudent(vector<Student>& students);

void EditSpisok()
{
	while (true)
	{
		system("cls");
		Menu a;
		switch (a.EditSpisok())
		{
		case 1:
			AddAtList(students);
			break;
		case 2:
			DeleteStudent(students);
			break;
		case 3:
			EditStudent(students);
		case 4:
			system("cls");
			return;
		}
	}
}

void Admin()
{
	system("cls");
	while (true)
	{
		Menu a;
		switch (a.AdminMenu())
		{
		case 1:
			EditSpisok();
			break;
		case 2:
			PrintAllList(students);
			break;
		case 3:
			system("cls");
			PrintAccountHead();
			for (int i = 0; i < accounts.size(); i++)
				accounts[i].Print(i + 1);
			system("pause");
			system("cls");
			break;
		case 4:
			EditAccount(accounts, fin, accsfile);
			break;
		case 5:
			return;
		}
	}
}

void Search()
{
	while (true)
	{
		system("cls");
		Menu a;
		switch (a.Search())
		{
		case 1:
			SearchByGroup(students);
			break;
		case 2:
			SearchByIsBudget(students);
			break;
		case 3:
			SearchByName(students);
			break;
		case 4:
			SearchBySurname(students);
			break;
		case 5:
			SearchByLastname(students);
			break;
		case 6:
			system("cls");
			return;
		}
	}
}

void Sort()
{
	while (true)
	{
		system("cls");
		Menu a;
		switch (a.Sort())
		{
		case 1:
			SortByName(students);
			break;
		case 2:
			SortBySurname(students);
			break;
		case 3:
			SortByLatsname(students);
			break;
		case 4:
			system("cls");
			return;
		}
	}
}

void User()
{
	while (true)
	{
		system("cls");
		Menu a;
		switch (a.UserMenu())
		{
		case 1:
			PrintAllList(students);
			break;
		case 2:
			Search();
			break;
		case 3:
			Sort();
			break;
		case 4:
			return;
		}
	}
}

int main()
{
	SetConsoleCP(1251); //установка поддержки ввода на русском
	SetConsoleOutputCP(1251); //установка поддержки вывода на русском
	fout.open(accsfile, ios_base::in);
	if (!fout.is_open())
	{
		cout << "Не удалось открыть файл с аккаунтами." << endl;
		FILE* f = fopen(accsfile.c_str(), "wt");
		fclose(f);
		fin.open(accsfile, ios_base::out);
		fin << endl << "admin 12345678 1" << endl << "user 12344321 0";
		fin.close();
		fout.open(accsfile, ios_base::in);
		cout << "Был создан экстренный файл с пользователем admin и паролем 12345678." << endl;
		system("pause");
		system("cls");
	}
	for (int i = 0; !fout.eof(); i++)
	{
		Account temp;
		accounts.push_back(temp.OutFile(fout));
	}
	fout.close();
	fout.open(studsfile, ios_base::in);
	if (!fout.is_open())
	{
		cout << "Не удалось открыть файл со студентами." << endl;
		FILE* f = fopen(studsfile.c_str(), "wt");
		fclose(f);
		fout.open(studsfile, ios_base::in);
		cout << "Был создан экстренный файл со студентами." << endl;
		system("pause");
		system("cls");
	}
	while (!fout.eof())
	{
		Student temp;
		students.push_back(temp.OutFile(fout));
	}
	fout.close();
	while (true)
	{
		system("cls");
		Menu a; 
		switch (a.MainMenu())
		{
		case 1:
			Login(accounts);
			break;
		case 2:
			Registration(fin, accsfile, accounts);
			break;
		case 3:
			fin.open(studsfile, ios_base::out);
			for (int i = 0; i < students.size(); i++)
			{
				students[i].InFile(fin);
			}
			fout.close();
			return 0;
		}
	}
}
    