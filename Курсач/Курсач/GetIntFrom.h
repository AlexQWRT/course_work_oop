#pragma once
#include <iostream>
#include <string>
using namespace std;
int GetIntFrom(int smallest, int biggest, string question)
{
	int num;
	cout << question << endl;
	cin >> num;
	if (cin.fail()) 
	{
		cout << "������� ��������� ������! ��������� ����." << endl;
		num = GetIntFrom(smallest, biggest, question);
	}
	if (num < smallest && num > biggest)
	{
		cout << "������� ��������� ������! ��������� ����." << endl;
		num = GetIntFrom(smallest, biggest, question);
	}
	return num;
}
