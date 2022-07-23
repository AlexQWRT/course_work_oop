#include "Student.h"
#include "GetIntFrom.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

Student::Student() //конструктор по умолчанию
{
	group = "";
	hourspropuskov = 0;
	f = "";
	i = "";
	o = "";
	form.text = "платная";
	form.isbudget = false;
	zachet[0].name = "Физ-ра";
	zachet[1].name = "СНВАЯ";
	zachet[2].name = "СТ";
	zachet[3].name = "ТКиОК";
	zachet[4].name = "ОП";
	subjects[0].name = "АЛОВТ";
	subjects[1].name = "ОАиП";
	subjects[2].name = "ООП";
	subjects[3].name = "ТТПО";
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

void PrintHead() //вывод на экран шапки таблицы
{
	cout << ' ';
	for (int i = 0; i < 195; i++)
		cout << "-";
	cout << endl << "|" << setw(5) << "№" << "|" << setw(15) << "Фамилия" << "|" << setw(15) << "Имя" << "|"
		<< setw(15) << "Отчество" << "|" << setw(10) << "Группа" << "|" << setw(10) << "Ф/о" << "|" << setw(10) << "Пропуски" << "|"
		<< setw(8) << "Физ-ра" << "|" << setw(8) << "СНВАЯ" << "|" << setw(8) << "СТ" << "|"
		<< setw(8) << "ТКиОК" << "|" << setw(8) << "ОП" << "|"
		<< setw(8) << "АЛОВТ" << "|" << setw(8) << "ОАиП" << "|" << setw(8) << "ООП" << "|" << setw(8) << "ТТПО" << "|"
		<< setw(8) << "Ср. балл" << "|" << setw(8) << "Коэф." << "|" << setw(9) << "Стипендия" << "|" << endl;
	cout << ' ';
	for (int i = 0; i < 195; i++)
		cout << "-";
	cout << endl;
}

void Student::Set()
{
	string buf = "";
	cout << "Введите фамилию студента: ";
	(cin >> setw(20) >> f).ignore(ULONG_MAX, '\n').clear();
	cout << "Введите имя студента: ";
	(cin >> setw(20) >> i).ignore(ULONG_MAX, '\n').clear();
	cout << "Введите отчество студента: ";
	(cin >> setw(20) >> o).ignore(ULONG_MAX, '\n').clear();
	cout << "Введите группу: ";
	(cin >> setw(10) >> group).ignore(ULONG_MAX, '\n').clear();
	
	buf = "";
	while (atoi(buf.c_str()) != 1 && atoi(buf.c_str()) != 2 || atoi(buf.c_str()) == NULL)
	{
		cout << "Выберите форму обучения:" << endl;
		cout << "1. Платная" << endl;
		cout << "2. Бюджетная" << endl;
		cin >> buf;
		if (atoi(buf.c_str()) != 1 && atoi(buf.c_str()) != 2 || atoi(buf.c_str()) == NULL)
		{
			cout << "Неверное значение, повторите ввод." << endl;
		}
	}
	//buf = GetIntFrom(1, 2, "Выберите форму обучения :\n1. Платная\n2. Бюджетная");
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
		cout << "Введите кол-во часов прогулов: ";
		cin >> buf;
		if (atof(buf.c_str()) < 0 && atof(buf.c_str()) > 1000 || atof(buf.c_str()) == NULL)
		{
			cout << "Введено неверное значение, повторите ввод" << endl;
		}
	}
	hourspropuskov = atof(buf.c_str());

	//hourspropuskov = GetIntFrom(0, 300, "Введите кол-во часов прогулов: ");
	buf = "";
	bool isstependiya1 = true;
	cout << "Заполните зачёты по предметам:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Предмет " << i + 1 << " - " << zachet[i].name << endl;
		while (atoi(buf.c_str()) != 1 && atoi(buf.c_str()) != 2 || atoi(buf.c_str()) == NULL)
		{
			cout << "Выберите зачёт/незачёт:" << endl;
			cout << "1. Зачёт" << endl;
			cout << "2. Незачёт" << endl;
			cin >> buf;
			if (atoi(buf.c_str()) != 1 && atoi(buf.c_str()) != 2 || atoi(buf.c_str()) == NULL)
			{
				cout << "Неверное значение, повторите ввод." << endl;
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
	cout << "Заполните оценки по предметам:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "Предмет " << i + 1 << " - " << subjects[i].name << endl;
		while (atoi(buf.c_str()) > 10 || atoi(buf.c_str()) < 0 || atoi(buf.c_str()) == NULL)
		{
			cout << "Введите отметку: ";
			cin >> buf;
			if (atoi(buf.c_str()) > 10 || atoi(buf.c_str()) < 0 || atoi(buf.c_str()) == NULL)
			{
				cout << "Введено неврное значение отметки, повторите ввод" << endl;
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
		cout << "Введите количество пропусков: ";
		(cin >> setw(10) >> buf).ignore(ULONG_MAX, '\n').clear();
		if (atof(buf.c_str()) && atof(buf.c_str()) < 0)
		{
			cout << "Введено неврное значение, повторите ввод" << endl;
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
		cout << "Список пуст." << endl;
		system("pause");
		system("cls");
		return;
	}
	string buf;
	bool wasnotfound = true;
	cout << "Введите группу для поиска: ";
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
		cout << "Ничего не найдено." << endl;
	}
	system("pause");
}

void SearchBySurname(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "Список пуст." << endl;
		system("pause");
		system("cls");
		return;
	}
	bool wasnotfound = true;
	string buf;
	cout << "Введите фамилию для поиска: ";
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
		cout << "Ничего не найдено." << endl;
	}
	system("pause");
}

void SearchByName(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "Список пуст." << endl;
		system("pause");
		system("cls");
		return;
	}
	bool wasnotfound = true;
	string buf;
	cout << "Введите имя для поиска: ";
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
		cout << "Ничего не найдено." << endl;
	}
	system("pause");
}

void SearchByLastname(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "Список пуст." << endl;
		system("pause");
		system("cls");
		return;
	}
	bool wasnotfound = true;
	string buf;
	cout << "Введите отчество для поиска: ";
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
		cout << "Ничего не найдено." << endl;
	}
	system("pause");
}

void SearchByIsBudget(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "Список пуст." << endl;
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
		cout << "Ничего не найдено." << endl;
	}
	system("pause");
}

void SortByName(vector<Student> stud)
{
	system("cls");
	if (stud.empty())
	{
		cout << "Список пуст." << endl;
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
		cout << "Список пуст." << endl;
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
		cout << "Список пуст." << endl;
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
		cout << "Не удалось открыть файл со студентами." << endl;
		return;
	}
	while (!fout.eof())
	{
		Student temp;
		students.push_back(temp.OutFile(fout));
	}
	cout << "Выгрузка из файла произошла успешно." << endl;
	system("pause");
	system("cls");
}

void AddAtList(vector<Student>& students)
{
	system("cls");
	string buf = "";
	cout << "Введите кол-во записей: ";
	while (atoi(buf.c_str()) < 0 || atoi(buf.c_str()) > 20 || atoi(buf.c_str()) == NULL) //ввод кол-ва записей с проверкой
	{
		cin >> buf;
		if (atoi(buf.c_str()) < 0 || atoi(buf.c_str()) > 20 || atoi(buf.c_str()) == NULL)
			cout << "Введено неверное значение, повторите ввод" << endl;
	}
	for (int i = 0; i < atoi(buf.c_str()); i++) //заполнение списка
	{
		cout << "Студент " << i + 1 << ":" << endl << endl;
		Student a;
		a.Set();
		students.push_back(a);
		system("pause"); //приостановка программы для возможности просмотра введённых данных
		system("cls"); //очистка консоли
	}
}

void PrintAllList(vector<Student> students)
{
	system("cls");
	if (students.empty())
	{
		cout << "Список пуст." << endl;
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
		cout << "Список пуст." << endl;
		system("pause");
		system("cls");
		return;
	}
	int studentnum;
	PrintHead();
	PrintAllList(students);
	cout << "Введите номер студента, которого нужно удалить: ";
	while (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > students.size() || atoi(buf.c_str()) == NULL) //ввод кол-ва записей с проверкой
	{
		cin >> buf;
		if (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > students.size() || atoi(buf.c_str()) == NULL)
		{
			cout << "Введено неверное значение, повторите ввод" << endl;
		}
	}
	string buf2;
	cout << "Вы уверены?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	while (atoi(buf2.c_str()) < 1 || atoi(buf2.c_str()) > 2 || atoi(buf2.c_str()) == NULL) //ввод кол-ва записей с проверкой
	{
		cin >> buf2;
		if (atoi(buf2.c_str()) < 1 || atoi(buf2.c_str()) > 2 || atoi(buf2.c_str()) == NULL)
		{
			cout << "Введено неверное значение, повторите ввод" << endl;
		}
	}
	if (buf2 == "2")
	{
		system("cls");
		cout << "Удаление было прервано." << endl;
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
	cout << "Удаление прошло успешно." << endl;
	system("pause");
	system("cls");
}

void EditStudent(vector<Student>& students)
{
	system("cls");
	if (students.empty())
	{
		cout << "Список пуст." << endl;
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
	cout << "Введите номер студента, данные которого нужно заполнить заново: ";
	while (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > students.size() || atoi(buf.c_str()) == NULL) //ввод кол-ва записей с проверкой
	{
		cin >> buf;
		if (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > students.size() || atoi(buf.c_str()) == NULL)
		{
			cout << "Введено неверное значение, повторите ввод" << endl;
		}
	}
	string buf2;
	cout << "Вы уверены?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	while (atoi(buf2.c_str()) < 1 || atoi(buf2.c_str()) > 2 || atoi(buf2.c_str()) == NULL) //ввод кол-ва записей с проверкой
	{
		cin >> buf2;
		if (atoi(buf2.c_str()) < 1 || atoi(buf2.c_str()) > 2 || atoi(buf2.c_str()) == NULL)
		{
			cout << "Введено неверное значение, повторите ввод" << endl;
		}
	}
	if (buf2 == "2")
	{
		cout << "Редактирование отменено." << endl;
		system("pause");
		system("cls");
	}
	else {
		students[atoi(buf.c_str()) - 1].Set();
		cout << "Успешно отредактировано." << endl;
		system("pause");
		system("cls");
	}
}