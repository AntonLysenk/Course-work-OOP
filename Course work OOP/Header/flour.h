#pragma once

#include "grocery.h"

class Flour : public Grocery {
	string structure;
public:
	Flour(string name, double pri, Date delivDate, Date shelfLife, string manufact, double wei, string structur) :
		Grocery(name, pri, delivDate, shelfLife, manufact, wei), structure(structur) {} //Конструктор с параметрами
	Flour() : Grocery(), structure("") {} //Конструктор по умолчанию
	void setStructure(string); //Установить состав
	string getStructure(); //Получить состав
	void print() override; //Вывод шапки
	friend istream& operator>>(istream&, Flour&); //Перегрузка оператора ввода
	friend ostream& operator<<(ostream&, Flour&); //Перегрузка оператора вывода
	static void read(Stack<Flour>&); //Чтение данных из файла
	static void write(Stack<Flour>&); //Запись данных в файл
};