#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

int Menu::MainMenu()
{
	while (atoi(enter.c_str()) < 1 || atoi(enter.c_str()) > 3 || atoi(enter.c_str()) == NULL)
	{
		cout << mainMenu;
		cout << "1. " << login;
		cout << "2. " << registration;
		cout << "3. " << exit;
		cin >> enter;
		if (atoi(enter.c_str()) < 1 || atoi(enter.c_str()) > 3 || atoi(enter.c_str()) == NULL)
		{
			system("cls");
			cout << reenter;
		}
	}
	return atoi(enter.c_str());
}

int Menu::AdminMenu()
{
	while (atoi(enter.c_str()) < 1 || atoi(enter.c_str()) > 5 || atoi(enter.c_str()) == NULL)
	{
		cout << adminMenu;
		cout << "1. " << spisok;
		cout << "2. " << printspisok;
		cout << "3. " << showAccounts;
		cout << "4. " << editAccount;
		cout << "5. " << exitAccount;
		cin >> enter;
		if (atoi(enter.c_str()) < 1 || atoi(enter.c_str()) > 5 || atoi(enter.c_str()) == NULL)
		{
			system("cls");
			cout << reenter;
		}
	}
	return atoi(enter.c_str());
}

int Menu::EditSpisok()
{
	while (atoi(enter.c_str()) < 0 || atoi(enter.c_str()) > 4 || atoi(enter.c_str()) == NULL)
	{
		cout << adminMenu;
		cout << "1. " << addStudent;
		cout << "2. " << delStudent;
		cout << "3. " << editStudent;
		cout << "4. " << back;
		cin >> enter;
		if (atoi(enter.c_str()) < 0 || atoi(enter.c_str()) > 4 || atoi(enter.c_str()) == NULL)
		{
			system("cls");
			cout << reenter;
		}
	}
	return atoi(enter.c_str());
}

int Menu::UserMenu()
{
	while (atoi(enter.c_str()) < 0 || atoi(enter.c_str()) > 4 || atoi(enter.c_str()) == NULL)
	{
		cout << userMenu;
		cout << "1. " << printspisok;
		cout << "2. " << search;
		cout << "3. " << sort;
		cout << "4. " << exitAccount;
		cin >> enter;
		if (atoi(enter.c_str()) < 0 || atoi(enter.c_str()) > 4 || atoi(enter.c_str()) == NULL)
		{
			system("cls");
			cout << reenter;
		}
	}
	return atoi(enter.c_str());
}

int Menu::Search()
{
	while (atoi(enter.c_str()) < 1 || atoi(enter.c_str()) > 6 || atoi(enter.c_str()) == NULL)
	{
		cout << userMenu;
		cout << "1. " << searchByGroup;
		cout << "2. " << searchByIsBudget;
		cout << "3. " << searchByName;
		cout << "4. " << searchBySurname;
		cout << "5. " << searchByLastname;
		cout << "6. " << back;
		cin >> enter;
		if (atoi(enter.c_str()) < 1 || atoi(enter.c_str()) > 6 || atoi(enter.c_str()) == NULL)
		{
			system("cls");
			cout << reenter;
		}
	}
	return atoi(enter.c_str());
}

int Menu::Sort()
{
	while (atoi(enter.c_str()) < 1 || atoi(enter.c_str()) > 4 || atoi(enter.c_str()) == NULL)
	{
		cout << userMenu;
		cout << "1. " << sortByName;
		cout << "2. " << sortBySurname;
		cout << "3. " << sortByLastname;
		cout << "4. " << back;
		cin >> enter;
		if (atoi(enter.c_str()) < 1 || atoi(enter.c_str()) > 4 || atoi(enter.c_str()) == NULL)
		{
			system("cls");
			cout << reenter;
		}
	}
	return atoi(enter.c_str());
}