#pragma once

#include "milky.h"

class Cheese : public Milky {
	string structure;
public:
	Cheese(string name, double pri, Date delivDate, Date shelfLife, string manufact, double fatCont, string str) :
		Milky(name, pri, delivDate, shelfLife, manufact, fatCont), structure(str) {} //Конструктор с параметрами
	Cheese() : Milky(), structure("") {} //Конструктор по умолчанию
	void setStruct(string str); //Установить состав
	string getStruct(); //Получить состав
	virtual void print(); //Вывод шапки
	friend istream& operator>>(istream& is, Cheese&); //Перегрузка оператора ввода
	friend ostream& operator<<(ostream& os, Cheese&); //Перегрузка оператора вывода
	static void read(Stack<Cheese>&); //Чтение данных из файла
	static void write(Stack<Cheese>&); //Запись данных в файл
};
