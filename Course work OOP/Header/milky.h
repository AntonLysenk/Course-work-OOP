#pragma once

#include "products.h"

class Milky : public Products {
protected:
	double fatContent; //������� ��������
public:
	Milky(string name, double pri, Date delivDate, Date shelfLife, string manufact, double fatCont) :
		Products(name, pri, delivDate, shelfLife, manufact), fatContent(fatCont) {} //����������� � �����������
	Milky() : Products(), fatContent(0) {} //����������� �� ���������
	void setFat(double fat); //���������� ������� ��������
	double getFat(); //�������� ������� ��������      
	void print() override {} //����� �����
};