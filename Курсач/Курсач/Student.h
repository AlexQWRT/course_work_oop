#pragma once
#include <string>
#include <fstream>
#include <vector>
using namespace std;
using std::string; 
const string budget = "бюджетная", platno = "платная", zachteno = "зачёт", ne_zachteno = "незачёт"; //константы строк для заполнения полей text в структурах
class Student
{
	float hourspropuskov; //часы пропускоы
	string f, i, o; //ФИО
	string group;
	struct Form
	{
		string text; //текст для вывода (бюджет/платка)
		bool isbudget = false; //переменная для облегчённой обработки данных
	} form; //форма обучения
	struct Zachet
	{
		string name; //название предмета
		string text; //текст для вывода (зачёт/не зачёт)
		bool iszach = false; //переменная для облегчённой обработки данных
	} zachet[5]; //зачёты по предметам
	struct Subjects
	{
		string name; //название предмета
		int mark = 0; //оценка по предмету
	} subjects[4]; //оценки по предметам
	double avgmark; //средний балл
	double koef; //коэфициент стипендии
	double money; //стипендия
public:
	Student();
	void Set(); //заполнение денных
	void Print(int num); //вывод данных о студенте
	void InFile(ofstream& f);
	Student OutFile(ifstream& f);
	friend void SearchByGroup(vector<Student> stud); //поиск по группам
	friend void SearchBySurname(vector<Student> stud); //поиск по фамилии
	friend void SearchByName(vector<Student> stud); //поиск по имени
	friend void SearchByLastname(vector<Student> stud); //поиск по отчеставо
	friend void SearchByIsBudget(vector<Student> stud); //поиск по бюджету
	friend void SortByName(vector<Student> stud); //сортировка в алфавитном порядке по имени
	friend void SortBySurname(vector<Student> stud); //сортировка в алфавитном порядке по имени
	friend void SortByLatsname(vector<Student> stud); //сортировка в алфавитном порядке по имени
};

	