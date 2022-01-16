#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Date {
	int days;
	int months;
	int years;
public:
	Date(int d, int m, int y) : days(d), months(m), years(y) {} //Конструктор с параметрами
	Date() : days(0), months(0), years(0) {} //Конструктор по умолчанию
	void setDays(int); //Установить день
	int getDays(); //Получить день
	void setMonths(int); //Установить месяц
	int getMonths(); //Получить месяц
	void setYears(int); //Установить год
	int getYears(); //Получить год
	friend bool operator< (const Date&, const Date&); //Перегрузка оператора меньше
	friend bool operator> (const Date&, const Date&); //Перегрузка оператора больше
	friend bool operator== (const Date&, const Date&); //Перегрузка оператора ==
	Date& operator= (string); //Перегрузка оператора равно
	Date& operator= (const Date&); //Перегрузка оператора равно
	friend istream& operator>>(istream&, Date&); //Перегрузка оператора ввода
	friend ostream& operator<<(ostream&, Date&); //Перегрузка оператора вывода
};

