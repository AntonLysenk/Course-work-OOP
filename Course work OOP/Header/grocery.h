#pragma once 

#include "products.h"

class Grocery : public Products {
protected: 
	double weight;
public:
	Grocery(string name, double pri, Date delivDate, Date shelfLife, string manufact, double wei) :
		Products(name, pri, delivDate, shelfLife, manufact), weight(wei) {} //Конструктор с параметрами
	Grocery() : Products(), weight(0) {} //Конструктор по умолчанию 
	void setWeight(double weight); //Установить вес
	double getWeight(); //Получить вес
	void print() override {} //Вывод шапки
};
