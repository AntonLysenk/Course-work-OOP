#pragma once

#include "milky.h"

class Milk : public Milky {
	string type; //Тип
public:
	Milk(string name, double pri, Date delivDate, Date shelfLife, string manufact, double fatCont, string tp) :
		Milky(name, pri, delivDate, shelfLife, manufact, fatCont), type(tp) {} //Конструктор с параметрами
	Milk() : Milky(), type() {} //Конструктор по умолчанию
	void setType(string tp); //Установить тип
	string getType(); //Получить тип
	void print() override; //Вывод шапки
	friend istream& operator>>(istream&, Milk&); //Перегрузка оператора ввода
	friend ostream& operator<<(ostream&, Milk&); //Перегрузка оператора вывода
	static void read(Stack<Milk>&); //Чтение данных из файла
	static void write(Stack<Milk>&); //Запись данных в файл
};