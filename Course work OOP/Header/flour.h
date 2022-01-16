#pragma once

#include "grocery.h"

class Flour : public Grocery {
	string structure;
public:
	Flour(string name, double pri, Date delivDate, Date shelfLife, string manufact, double wei, string structur) :
		Grocery(name, pri, delivDate, shelfLife, manufact, wei), structure(structur) {} //����������� � �����������
	Flour() : Grocery(), structure("") {} //����������� �� ���������
	void setStructure(string); //���������� ������
	string getStructure(); //�������� ������
	void print() override; //����� �����
	friend istream& operator>>(istream&, Flour&); //���������� ��������� �����
	friend ostream& operator<<(ostream&, Flour&); //���������� ��������� ������
	static void read(Stack<Flour>&); //������ ������ �� �����
	static void write(Stack<Flour>&); //������ ������ � ����
};