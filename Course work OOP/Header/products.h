#pragma once

#include <iostream>
#include "stack.h"
#include "date.h"

using namespace std;

class Products {
protected:
	string productName; //�������� ��������
	double price; //����
	Date deliveryDate; //���� ��������
	Date shelfLife; //���� ��������
	string manufacturer; //�������������
public:
	Products(string name, double pri, Date delivDate, Date shelfLife, string manufact) : productName(name),
		price(pri), deliveryDate(delivDate), shelfLife(shelfLife), manufacturer(manufact) {} //����������� � �����������
	Products() : productName(""), price(0), deliveryDate(), shelfLife(), manufacturer("") {} //����������� �� ���������
	void setName(string); //���������� �������� ������
	string getName(); //�������� �������� ������
	void setPrice(double); //���������� ����
	double getPrice(); //�������� ����
	void setDeliveryDate(Date); //���������� ���� ��������
	Date getDeliveryDate(); //�������� ���� �������� 
	void setShelfLife(Date); //���������� ���� ��������
	Date getShelfLife(); //�������� ���� ��������
	void setManufact(string); //���������� �������������
	string getManufact(); //�������� �������������
	virtual void print() = 0; //����� ����������� ������� ������ �����
};
