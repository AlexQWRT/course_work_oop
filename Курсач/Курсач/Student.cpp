#include "Student.h"
#include "GetIntFrom.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

Student::Student() //����������� �� ���������
{
	group = "";
	hourspropuskov = 0;
	f = "";
	i = "";
	o = "";
	form.text = "�������";
	form.isbudget = false;
	zachet[0].name = "���-��";
	zachet[1].name = "�����";
	zachet[2].name = "��";
	zachet[3].name = "�����";
	zachet[4].name = "��";
	subjects[0].name = "�����";
	subjects[1].name = "����";
	subjects[2].name = "���";
	subjects[3].name = "����";
	for (int i = 0; i < 5; i++)
	{
		zachet[i].iszach = false;
		zachet[i].text = platno;
	}
	for (int i = 0; i < 4; i++)
	{
		subjects[i].mark = 0;
	}
	avgmark = 0; 
	koef = 0;
	money = 0; 
}

void PrintHead() //����� �� ����� ����� �������
{
	cout << ' ';
	for (int i = 0; i < 195; i++)
		cout << "-";
	cout << endl << "|" << setw(5) << "�" << "|" << setw(15) << "�������" << "|" << setw(15) << "���" << "|"
		<< setw(15) << "��������" << "|" << setw(10) << "������" << "|" << setw(10) << "�/�" << "|" << setw(10) << "��������" << "|"
		<< setw(8) << "���-��" << "|" << setw(8) << "�����" << "|" << setw(8) << "��" << "|"
		<< setw(8) << "�����" << "|" << setw(8) << "��" << "|"
		<< setw(8) << "�����" << "|" << setw(8) << "����" << "|" << setw(8) << "���" << "|" << setw(8) << "����" << "|"
		<< setw(8) << "��. ����" << "|" << setw(8) << "����." << "|" << setw(9) << "���������" << "|" << endl;
	cout << ' ';
	for (int i = 0; i < 195; i++)
		cout << "-";
	cout << endl;
}

void Student::Set()
{
	string buf = "";
	cout << "������� ������� ��������: ";
	(cin >> setw(20) >> f).ignore(ULONG_MAX, '\n').clear();
	cout << "������� ��� ��������: ";
	(cin >> setw(20) >> i).ignore(ULONG_MAX, '\n').clear();
	cout << "������� �������� ��������: ";
	(cin >> setw(20) >> o).ignore(ULONG_MAX, '\n').clear();
	cout << "������� ������: ";
	(cin >> setw(10) >> group).ignore(ULONG_MAX, '\n').clear();
	
	buf = "";
	while (atoi(buf.c_str()) != 1 && atoi(buf.c_str()) != 2 || atoi(buf.c_str()) == NULL)
	{
		cout << "�������� ����� ��������:" << endl;
		cout << "1. �������" << endl;
		cout << "2. ���������" << endl;
		cin >> buf;
		if (atoi(buf.c_str()) != 1 && atoi(buf.c_str()) != 2 || atoi(buf.c_str()) == NULL)
		{
			cout << "�������� ��������, ��������� ����." << endl;
		}
	}
	//buf = GetIntFrom(1, 2, "�������� ����� �������� :\n1. �������\n2. ���������");
	if (atoi(buf.c_str()) == 1)
	{
		form.text = platno;
		form.isbudget = false;
	}
	else
	{
		form.text = budget;
		form.isbudget = true;
	} 
	buf = "";
	
	while (atof(buf.c_str()) < 0 && atof(buf.c_str()) > 1000 || atof(buf.c_str()) == NULL)
	{
		cout << "������� ���-�� ����� ��������: ";
		cin >> buf;
		if (atof(buf.c_str()) < 0 && atof(buf.c_str()) > 1000 || atof(buf.c_str()) == NULL)
		{
			cout << "������� �������� ��������, ��������� ����" << endl;
		}
	}
	hourspropuskov = atof(buf.c_str());

	//hourspropuskov = GetIntFrom(0, 300, "������� ���-�� ����� ��������: ");
	buf = "";
	bool isstependiya1 = true;
	cout << "��������� ������ �� ���������:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "������� " << i + 1 << " - " << zachet[i].name << endl;
		while (atoi(buf.c_str()) != 1 && atoi(buf.c_str()) != 2 || atoi(buf.c_str()) == NULL)
		{
			cout << "�������� �����/�������:" << endl;
			cout << "1. �����" << endl;
			cout << "2. �������" << endl;
			cin >> buf;
			if (atoi(buf.c_str()) != 1 && atoi(buf.c_str()) != 2 || atoi(buf.c_str()) == NULL)
			{
				cout << "�������� ��������, ��������� ����." << endl;
			}
		}
		if (atoi(buf.c_str()) == 1)
		{
			zachet[i].text = zachteno;
			zachet[i].iszach = true;
		}
		else
		{
			zachet[i].text = ne_zachteno;
			zachet[i].iszach = false;
			isstependiya1 = false;
		}
		buf = "";
	}
	
	buf = "11";
	bool isstependiya2 = true;
	cout << "��������� ������ �� ���������:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "������� " << i + 1 << " - " << subjects[i].name << endl;
		while (atoi(buf.c_str()) > 10 || atoi(buf.c_str()) < 0 || atoi(buf.c_str()) == NULL)
		{
			cout << "������� �������: ";
			cin >> buf;
			if (atoi(buf.c_str()) > 10 || atoi(buf.c_str()) < 0 || atoi(buf.c_str()) == NULL)
			{
				cout << "������� ������� �������� �������, ��������� ����" << endl;
			}
		}
		subjects[i].mark = atoi(buf.c_str());
		buf = "11";
		avgmark += subjects[i].mark;
		if (subjects[i].mark < 4)
		{
			isstependiya2 = false;
		}
	}
	avgmark = round(avgmark / 4 * 10) / 10;
	
	buf = "";
	while (!atof(buf.c_str()) && (atof(buf.c_str()) < 0 || buf == "0"))
	{
		cout << "������� ���������� ���������: ";
		(cin >> setw(10) >> buf).ignore(ULONG_MAX, '\n').clear();
		if (atof(buf.c_str()) && atof(buf.c_str()) < 0)
		{
			cout << "������� ������� ��������, ��������� ����" << endl;
		}
	}
	
	if (form.isbudget && avgmark >= 5 && isstependiya1 && isstependiya2 && hourspropuskov < 10)
	{
		if (avgmark >= 5 && avgmark < 6)
		{
			koef = 1;
			money = 85.7;
		}
		if (avgmark >= 6 && avgmark < 8)
		{
			koef = 1.2;
			money = 102.84;
		}
		if (avgmark >= 8 && avgmark < 9)
		{
			koef = 1.4;
			money = 119.99;
		}
		if (avgmark >= 9 && avgmark <= 10)
		{
			koef = 1.6;
			money = 137.13;
		}
	}
}

void Student::Print(int num)
{
	cout << "|" << setw(5) << num << "|" << setw(15) << f << "|" << setw(15) << i << "|" << setw(15) << o << "|"
		<< setw(10) << group << "|" << setw(10) << form.text << "|" << setw(10) << hourspropuskov << "|";
	for (int i = 0; i < 5; i++)
	{
		cout << setw(8) << zachet[i].text << "|";
	}
	for (int i = 0; i < 4; i++)
	{
		cout << setw(8) << subjects[i].mark << "|";
	}
	cout << setw(8) << avgmark << "|" << setw(8) << koef << "|" << setw(9) << money << "|";
	cout << endl;
	cout << ' ';
	for (int i = 0; i < 195; i++)
	{
		cout << "-";
	}
	cout << endl;
}

void Student::InFile(ofstream& f)
{
	f << endl << this->f << ' ' << i << ' ' << o << ' ' << hourspropuskov << ' ' << group << ' '
		<< form.isbudget << ' ' << avgmark << ' ' << koef << ' ' << money << ' ';
	for (int i = 0; i < 5; i++)
	{
		f << zachet[i].iszach << ' ';
	}
	for (int i = 0; i < 3; i++)
	{
		f << subjects[i].mark << ' ';
	}
	f << subjects[3].mark;
}

Student Student::OutFile(ifstream& f)
{
	f >> this->f >> i >> o >> hourspropuskov >> group
		>> form.isbudget >> avgmark >> koef >> money;
	for (int i = 0; i < 5; i++)
	{
		f >> zachet[i].iszach;
		if (zachet[i].iszach)
		{
			zachet[i].text = zachteno;
		}
		else
		{
			zachet[i].text = ne_zachteno;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		f >> subjects[i].mark;
	}
	if (form.isbudget)
	{
		form.text = budget;
	}
	else
	{
		form.text = platno;
	}
	return *this;
}

void SearchByGroup(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	string buf;
	bool wasnotfound = true;
	cout << "������� ������ ��� ������: ";
	cin >> buf;
	PrintHead();
	for (int i = 0; i < stud.size(); i++)
	{
		if (stud[i].group == buf)
		{
			stud[i].Print(i + 1);
			wasnotfound = false;
		}
	}
	if (wasnotfound)
	{
		system("cls");
		cout << "������ �� �������." << endl;
	}
	system("pause");
}

void SearchBySurname(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	bool wasnotfound = true;
	string buf;
	cout << "������� ������� ��� ������: ";
	cin >> buf;
	PrintHead();
	for (int i = 0; i < stud.size(); i++)
	{
		if (stud[i].f == buf)
		{
			stud[i].Print(i + 1);
			wasnotfound = false;
		}
	}
	if (wasnotfound)
	{
		system("cls");
		cout << "������ �� �������." << endl;
	}
	system("pause");
}

void SearchByName(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	bool wasnotfound = true;
	string buf;
	cout << "������� ��� ��� ������: ";
	cin >> buf;
	PrintHead();
	for (int i = 0; i < stud.size(); i++)
	{
		if (stud[i].i == buf)
		{
			stud[i].Print(i + 1);
			wasnotfound = false;
		}
	}
	if (wasnotfound)
	{
		system("cls");
		cout << "������ �� �������." << endl;
	}
	system("pause");
}

void SearchByLastname(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	bool wasnotfound = true;
	string buf;
	cout << "������� �������� ��� ������: ";
	cin >> buf;
	PrintHead();
	for (int i = 0; i < stud.size(); i++)
	{
		if (stud[i].o == buf)
		{
			stud[i].Print(i + 1);
			wasnotfound = false;
		}
	}
	if (wasnotfound)
	{
		system("cls");
		cout << "������ �� �������." << endl;
	}
	system("pause");
}

void SearchByIsBudget(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	bool wasnotfound = true;
	PrintHead();
	for (int i = 0; i < stud.size(); i++)
	{
		if (stud[i].form.isbudget)
		{
			stud[i].Print(i + 1);
			wasnotfound = false;
		}
	}
	if (wasnotfound)
	{
		system("cls");
		cout << "������ �� �������." << endl;
	}
	system("pause");
}

void SortByName(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	PrintHead();
	for (int i = 0; i < stud.size(); i++)
	{
		for (int j = i; j < stud.size(); j++)
		{
			if (stud[i].i > stud[j].i)
			{
				Student buf = stud[i];
				stud[i] = stud[j];
				stud[j] = buf;
			}
		}
		stud[i].Print(i + 1);
	}
	system("pause");
}

void SortBySurname(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	PrintHead();
	for (int i = 0; i < stud.size(); i++)
	{
		for (int j = i; j < stud.size(); j++)
		{
			if (stud[i].f > stud[j].f)
			{
				Student buf = stud[i];
				stud[i] = stud[j];
				stud[j] = buf;
			}
		}
		stud[i].Print(i + 1);
	}
	system("pause");
}

void SortByLatsname(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	PrintHead();
	for (int i = 0; i < stud.size(); i++)
	{
		for (int j = i; j < stud.size(); j++)
		{
			if (stud[i].o > stud[j].o)
			{
				Student buf = stud[i];
				stud[i] = stud[j];
				stud[j] = buf;
			}
		}
		stud[i].Print(i + 1);
	}
	system("pause");
}

void DownloadFromFile(ifstream& fout, string studsfile, vector<Student>& students)
{
	system("cls");
	fout.open(studsfile, ios_base::in);
	if (!fout.is_open())
	{
		cout << "�� ������� ������� ���� �� ����������." << endl;
		return;
	}
	while (!fout.eof())
	{
		Student temp;
		students.push_back(temp.OutFile(fout));
	}
	cout << "�������� �� ����� ��������� �������." << endl;
	system("pause");
	system("cls");
}

void AddAtList(vector<Student>& students)
{
	system("cls");
	string buf = "";
	cout << "������� ���-�� �������: ";
	while (atoi(buf.c_str()) < 0 || atoi(buf.c_str()) > 20 || atoi(buf.c_str()) == NULL) //���� ���-�� ������� � ���������
	{
		cin >> buf;
		if (atoi(buf.c_str()) < 0 || atoi(buf.c_str()) > 20 || atoi(buf.c_str()) == NULL)
			cout << "������� �������� ��������, ��������� ����" << endl;
	}
	for (int i = 0; i < atoi(buf.c_str()); i++) //���������� ������
	{
		cout << "������� " << i + 1 << ":" << endl << endl;
		Student a;
		a.Set();
		students.push_back(a);
		system("pause"); //������������ ��������� ��� ����������� ��������� �������� ������
		system("cls"); //������� �������
	}
}

void PrintAllList(vector<Student> students)
{
	system("cls");
	if (students.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	PrintHead();
	for (int i = 0; i < students.size(); i++)
		students[i].Print(i + 1);
	system("pause");
	system("cls");
}

void DeleteStudent(vector<Student>& students)
{
	system("cls");
	string buf = "";
	if (students.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	int studentnum;
	PrintHead();
	PrintAllList(students);
	cout << "������� ����� ��������, �������� ����� �������: ";
	while (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > students.size() || atoi(buf.c_str()) == NULL) //���� ���-�� ������� � ���������
	{
		cin >> buf;
		if (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > students.size() || atoi(buf.c_str()) == NULL)
		{
			cout << "������� �������� ��������, ��������� ����" << endl;
		}
	}
	string buf2;
	cout << "�� �������?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	while (atoi(buf2.c_str()) < 1 || atoi(buf2.c_str()) > 2 || atoi(buf2.c_str()) == NULL) //���� ���-�� ������� � ���������
	{
		cin >> buf2;
		if (atoi(buf2.c_str()) < 1 || atoi(buf2.c_str()) > 2 || atoi(buf2.c_str()) == NULL)
		{
			cout << "������� �������� ��������, ��������� ����" << endl;
		}
	}
	if (buf2 == "2")
	{
		system("cls");
		cout << "�������� ���� ��������." << endl;
		system("pause");
		system("cls");
		return;
	}
	studentnum = atoi(buf.c_str());
	for (int i = studentnum; i < students.size(); i++)
	{
		students[i - 1] = students[i];
	}
	students.pop_back();
	cout << "�������� ������ �������." << endl;
	system("pause");
	system("cls");
}

void EditStudent(vector<Student>& students)
{
	system("cls");
	if (students.empty())
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	string buf;
	PrintHead();
	for (int i = 0; i < students.size(); i++)
	{
		students[i].Print(i + 1);
	}
	int studnum;
	cout << "������� ����� ��������, ������ �������� ����� ��������� ������: ";
	while (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > students.size() || atoi(buf.c_str()) == NULL) //���� ���-�� ������� � ���������
	{
		cin >> buf;
		if (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > students.size() || atoi(buf.c_str()) == NULL)
		{
			cout << "������� �������� ��������, ��������� ����" << endl;
		}
	}
	string buf2;
	cout << "�� �������?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	while (atoi(buf2.c_str()) < 1 || atoi(buf2.c_str()) > 2 || atoi(buf2.c_str()) == NULL) //���� ���-�� ������� � ���������
	{
		cin >> buf2;
		if (atoi(buf2.c_str()) < 1 || atoi(buf2.c_str()) > 2 || atoi(buf2.c_str()) == NULL)
		{
			cout << "������� �������� ��������, ��������� ����" << endl;
		}
	}
	if (buf2 == "2")
	{
		cout << "�������������� ��������." << endl;
		system("pause");
		system("cls");
	}
	else {
		students[atoi(buf.c_str()) - 1].Set();
		cout << "������� ���������������." << endl;
		system("pause");
		system("cls");
	}
}