#pragma once 

#include "products.h"

class Grocery : public Products {
protected: 
	double weight;
public:
	Grocery(string name, double pri, Date delivDate, Date shelfLife, string manufact, double wei) :
		Products(name, pri, delivDate, shelfLife, manufact), weight(wei) {} //����������� � �����������
	Grocery() : Products(), weight(0) {} //����������� �� ��������� 
	void setWeight(double weight); //���������� ���
	double getWeight(); //�������� ���
	void print() override {} //����� �����
};
