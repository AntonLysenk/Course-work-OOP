#pragma once

#include "products.h"

class Milky : public Products {
protected:
	double fatContent; //Процент жирности
public:
	Milky(string name, double pri, Date delivDate, Date shelfLife, string manufact, double fatCont) :
		Products(name, pri, delivDate, shelfLife, manufact), fatContent(fatCont) {} //Конструктор с параметрами
	Milky() : Products(), fatContent(0) {} //Конструктор по умолчанию
	void setFat(double fat); //Установить процент жирности
	double getFat(); //Получить процент жирности      
	void print() override {} //Вывод шапки
};