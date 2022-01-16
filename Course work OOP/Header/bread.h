#pragma once

#include "bakery.h"

class Bread : public Bakery {
	string structure;
public:
	Bread(string name, double pri, Date delivDate, Date shelfLife, string manufact, double wei, string structur) :
		Bakery(name, pri, delivDate, shelfLife, manufact, wei), structure(structur) {} //����������� � �����������
	Bread() : Bakery(), structure("") {} //����������� �� ���������
	void setStructure(string structur); //���������� ������
	string getStructure(); //�������� ������
	void print() override; //����� �����
	friend istream& operator>>(istream& is, Bread&); //���������� ��������� �����
	friend ostream& operator<<(ostream& os, Bread&); //���������� ��������� ������
	static void read(Stack<Bread>&); //������ ������ �� �����
	static void write(Stack<Bread>&); //������ ������ � ����
};