#pragma once

#include "products.h"

class Bakery : public Products {
protected:
	double weight;
public:
	//Конструктор с параметрами
	Bakery(string name, double pri, Date delivDate, Date shelfLife, string manufact, double wei) : 
		Products(name, pri, delivDate, shelfLife, manufact), weight(wei) {}
	//Конструктор по умолчанию
	Bakery() : Products(), weight(0) {}
	//Установить вес
	void setWeight(double);
	//Получить вес
	double getWeight();
	void print() override {} //Вывод шапки
};