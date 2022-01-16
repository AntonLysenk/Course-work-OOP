#pragma once

#include "products.h"

class Bakery : public Products {
protected:
	double weight;
public:
	//����������� � �����������
	Bakery(string name, double pri, Date delivDate, Date shelfLife, string manufact, double wei) : 
		Products(name, pri, delivDate, shelfLife, manufact), weight(wei) {}
	//����������� �� ���������
	Bakery() : Products(), weight(0) {}
	//���������� ���
	void setWeight(double);
	//�������� ���
	double getWeight();
	void print() override {} //����� �����
};