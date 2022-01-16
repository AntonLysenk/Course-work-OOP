#pragma once

#include "bakery.h"

class Bun : public Bakery {
	string filling;
public:
	Bun(string name, double pri, Date delivDate, Date shelfLife, string manufact, double weigh, string fill) :
		Bakery(name, pri, delivDate, shelfLife, manufact, weigh), filling(fill) {} //Конструктор с параметрами
	Bun() : Bakery(), filling("") {} //Конструктор по умолчанию
	void setFilling(string fill); //Установить начинку
	string getFilling(); //Получить начинку
	void print() override; //Вывод шапки
	friend istream& operator>>(istream& is, Bun&); //Перегрузка оператора ввода
	friend ostream& operator<<(ostream& os, Bun&); //Перегрузка оператора вывода
	static void read(Stack<Bun>&); //Чтение данных из файла
	static void write(Stack<Bun>&); //Запись данных в файл
};