#pragma once

#include "grocery.h"
#include "date.h"

class Pasta : public Grocery {
	string variety;
public:
	Pasta(string name, double pri, Date delivDate, Date shelfLife, string manufact, double wei, string varie) :
		Grocery(name, pri, delivDate, shelfLife, manufact, wei), variety(varie) {} //Конструктор с параметрами
	Pasta() : Grocery(), variety("") {} //Конструктор по умолчанию
	void setVariety(string varie); //Установить сорт
	string getVariety(); //Получить сорт
	void print() override; //Вывод шапки
	friend istream& operator>>(istream& is, Pasta&); //Перегрузка оператора ввода
	friend ostream& operator<<(ostream& os, Pasta&); //Перегрузка оператора вывода
	static void read(Stack<Pasta>&); //Чтение данных из файла
	static void write(Stack<Pasta>&); //Запись данных в файл
};
