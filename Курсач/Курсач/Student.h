#pragma once
#include <string>
#include <fstream>
#include <vector>
using namespace std;
using std::string; 
const string budget = "���������", platno = "�������", zachteno = "�����", ne_zachteno = "�������"; //��������� ����� ��� ���������� ����� text � ����������
class Student
{
	float hourspropuskov; //���� ���������
	string f, i, o; //���
	string group;
	struct Form
	{
		string text; //����� ��� ������ (������/������)
		bool isbudget = false; //���������� ��� ����������� ��������� ������
	} form; //����� ��������
	struct Zachet
	{
		string name; //�������� ��������
		string text; //����� ��� ������ (�����/�� �����)
		bool iszach = false; //���������� ��� ����������� ��������� ������
	} zachet[5]; //������ �� ���������
	struct Subjects
	{
		string name; //�������� ��������
		int mark = 0; //������ �� ��������
	} subjects[4]; //������ �� ���������
	double avgmark; //������� ����
	double koef; //���������� ���������
	double money; //���������
public:
	Student();
	void Set(); //���������� ������
	void Print(int num); //����� ������ � ��������
	void InFile(ofstream& f);
	Student OutFile(ifstream& f);
	friend void SearchByGroup(vector<Student> stud); //����� �� �������
	friend void SearchBySurname(vector<Student> stud); //����� �� �������
	friend void SearchByName(vector<Student> stud); //����� �� �����
	friend void SearchByLastname(vector<Student> stud); //����� �� ���������
	friend void SearchByIsBudget(vector<Student> stud); //����� �� �������
	friend void SortByName(vector<Student> stud); //���������� � ���������� ������� �� �����
	friend void SortBySurname(vector<Student> stud); //���������� � ���������� ������� �� �����
	friend void SortByLatsname(vector<Student> stud); //���������� � ���������� ������� �� �����
};

	