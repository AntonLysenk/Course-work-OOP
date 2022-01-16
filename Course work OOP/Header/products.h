#pragma once

#include <iostream>
#include "stack.h"
#include "date.h"

using namespace std;

class Products {
protected:
	string productName; //Название продукта
	double price; //Цена
	Date deliveryDate; //Дата поставки
	Date shelfLife; //Срок годности
	string manufacturer; //Производитель
public:
	Products(string name, double pri, Date delivDate, Date shelfLife, string manufact) : productName(name),
		price(pri), deliveryDate(delivDate), shelfLife(shelfLife), manufacturer(manufact) {} //Конструктор с параметрами
	Products() : productName(""), price(0), deliveryDate(), shelfLife(), manufacturer("") {} //Конструктор по умолчанию
	void setName(string); //Установить название товара
	string getName(); //Получить название товара
	void setPrice(double); //Установить цену
	double getPrice(); //Получить цену
	void setDeliveryDate(Date); //Установить дату поставки
	Date getDeliveryDate(); //Получить дату поставки 
	void setShelfLife(Date); //Установить срок годности
	Date getShelfLife(); //Получить срок годности
	void setManufact(string); //Установить производителя
	string getManufact(); //Получить производителя
	virtual void print() = 0; //Чисто виртуальная функция вывода шапки
};
