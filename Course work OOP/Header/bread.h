#pragma once

#include "bakery.h"

class Bread : public Bakery {
	string structure;
public:
	Bread(string name, double pri, Date delivDate, Date shelfLife, string manufact, double wei, string structur) :
		Bakery(name, pri, delivDate, shelfLife, manufact, wei), structure(structur) {} //Конструктор с параметрами
	Bread() : Bakery(), structure("") {} //Конструктор по умолчанию
	void setStructure(string structur); //Установить состав
	string getStructure(); //Получить состав
	void print() override; //Вывод шапки
	friend istream& operator>>(istream& is, Bread&); //Перегрузка оператора ввода
	friend ostream& operator<<(ostream& os, Bread&); //Перегрузка оператора вывода
	static void read(Stack<Bread>&); //Чтение данных из файла
	static void write(Stack<Bread>&); //Запись данных в файл
};