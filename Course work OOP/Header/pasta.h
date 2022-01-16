#pragma once

#include "grocery.h"
#include "date.h"

class Pasta : public Grocery {
	string variety;
public:
	Pasta(string name, double pri, Date delivDate, Date shelfLife, string manufact, double wei, string varie) :
		Grocery(name, pri, delivDate, shelfLife, manufact, wei), variety(varie) {} //����������� � �����������
	Pasta() : Grocery(), variety("") {} //����������� �� ���������
	void setVariety(string varie); //���������� ����
	string getVariety(); //�������� ����
	void print() override; //����� �����
	friend istream& operator>>(istream& is, Pasta&); //���������� ��������� �����
	friend ostream& operator<<(ostream& os, Pasta&); //���������� ��������� ������
	static void read(Stack<Pasta>&); //������ ������ �� �����
	static void write(Stack<Pasta>&); //������ ������ � ����
};
