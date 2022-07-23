#pragma once
#include <string>
using std::string;
class Menu
{
	string mainMenu = "==========������� ����==========\n";
	string adminMenu = "==========���� ��������������==========\n";
	string userMenu = "==========���� ������������==========\n";
	string enter = "";
	string login = "�����\n"; //�����
	string registration = "������������������\n"; //������������������
	string searchByGroup = "����� �������� �� ������\n"; //����� �������� �� ������
	string searchBySurname = "����� ������� �� �������\n"; //����� ������� �� �������
	string searchByName = "����� ������� �� �����\n"; //����� ������� �� �����
	string searchByLastname = "����� ������� �� ��������\n"; //����� ������� �� ��������
	string searchByIsBudget = "������� ���� �����������\n"; //������� ���� �����������
	string sortByName = "���������� �� �����\n"; //���������� �� �����
	string sortBySurname = "���������� �� �������\n"; //���������� �� �������
	string sortByLastname = "���������� �� ��������\n"; //���������� �� ��������
	string delAccount = "������� ������� ������\n"; //������� ������� ������
	string save = "��������� � ����\n"; //��������� � ����
	string download = "��������� ������ �� �����\n"; //��������� ������ �� �����
	string spisok = "������������� ������\n"; //������������� ������
	string printspisok = "������� ���� ������ ���������\n"; //������� ���� ������ ���������
	string exitAccount = "����� �� ������� ������\n"; //����� �� ������� ������
	string back = "�����\n"; //�����
	string exit = "����� �� ���������\n"; //����� �� ���������
	string search = "����� �� �������\n"; //����� �� �������
	string sort = "���������� �������\n"; //���������� �������
	string reenter = "������� �������� ������, ��������� ����\n"; //������� �������� ������, ��������� ����
	string showAccounts = "���������� ������ �������������\n"; //���������� ������ �������������
	string addStudent = "�������� ��������\n"; //�������� ��������
	string delStudent = "������� ��������\n"; //������� ��������
	string editAccount = "���� ����� ��������������\n"; //���� ����� ��������������
	string editStudent = "��������������� ������ � ��������\n"; //��������������� ������ � ��������
public:
	int MainMenu();
	int AdminMenu();
	int UserMenu();
	int Search();
	int Sort();
	int EditSpisok();
};

