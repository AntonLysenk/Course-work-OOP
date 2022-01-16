#pragma once

#include "bakery.h"

class Bun : public Bakery {
	string filling;
public:
	Bun(string name, double pri, Date delivDate, Date shelfLife, string manufact, double weigh, string fill) :
		Bakery(name, pri, delivDate, shelfLife, manufact, weigh), filling(fill) {} //����������� � �����������
	Bun() : Bakery(), filling("") {} //����������� �� ���������
	void setFilling(string fill); //���������� �������
	string getFilling(); //�������� �������
	void print() override; //����� �����
	friend istream& operator>>(istream& is, Bun&); //���������� ��������� �����
	friend ostream& operator<<(ostream& os, Bun&); //���������� ��������� ������
	static void read(Stack<Bun>&); //������ ������ �� �����
	static void write(Stack<Bun>&); //������ ������ � ����
};