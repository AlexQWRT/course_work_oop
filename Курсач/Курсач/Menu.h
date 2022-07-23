#pragma once
#include <string>
using std::string;
class Menu
{
	string mainMenu = "==========Главное меню==========\n";
	string adminMenu = "==========Меню администратора==========\n";
	string userMenu = "==========Меню пользователя==========\n";
	string enter = "";
	string login = "Войти\n"; //Войти
	string registration = "Зарегистрироваться\n"; //Зарегистрироваться
	string searchByGroup = "Поиск учащихся по группе\n"; //Поиск учащихся по группе
	string searchBySurname = "Поиск записей по фамилии\n"; //Поиск записей по фамилии
	string searchByName = "Поиск записей по имени\n"; //Поиск записей по имени
	string searchByLastname = "Поиск записей по отчеству\n"; //Поиск записей по отчеству
	string searchByIsBudget = "Вывести всех бюджетников\n"; //Вывести всех бюджетников
	string sortByName = "Сортировка по имени\n"; //Сортировка по имени
	string sortBySurname = "Сортировка по фамилии\n"; //Сортировка по фамилии
	string sortByLastname = "Сортировка по отчеству\n"; //Сортировка по отчеству
	string delAccount = "Удалить учётную запись\n"; //Удалить учётную запись
	string save = "Сохранить в файл\n"; //Сохранить в файл
	string download = "Загрузить данные из файла\n"; //Загрузить данные из файла
	string spisok = "Редактировать список\n"; //Редактировать список
	string printspisok = "Вывести весь список студентов\n"; //Вывести весь список студентов
	string exitAccount = "Выйти из учётной записи\n"; //Выйти из учётной записи
	string back = "Назад\n"; //Назад
	string exit = "Выйти из программы\n"; //Выйти из программы
	string search = "Поиск по записям\n"; //Поиск по записям
	string sort = "Сортировка записей\n"; //Сортировка записей
	string reenter = "Введены неверные данные, повторите ввод\n"; //Введены неверные данные, повторите ввод
	string showAccounts = "Прсмотреть список пользователей\n"; //Прсмотреть список пользователей
	string addStudent = "Добавить студента\n"; //Добавить студента
	string delStudent = "Удалить студента\n"; //Удалить студента
	string editAccount = "Дать права администратора\n"; //Дать права администратора
	string editStudent = "Отредактировать данные о студенте\n"; //Отредактировать данные о студенте
public:
	int MainMenu();
	int AdminMenu();
	int UserMenu();
	int Search();
	int Sort();
	int EditSpisok();
};

