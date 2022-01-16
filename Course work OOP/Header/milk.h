#pragma once

#include "milky.h"

class Milk : public Milky {
	string type; //���
public:
	Milk(string name, double pri, Date delivDate, Date shelfLife, string manufact, double fatCont, string tp) :
		Milky(name, pri, delivDate, shelfLife, manufact, fatCont), type(tp) {} //����������� � �����������
	Milk() : Milky(), type() {} //����������� �� ���������
	void setType(string tp); //���������� ���
	string getType(); //�������� ���
	void print() override; //����� �����
	friend istream& operator>>(istream&, Milk&); //���������� ��������� �����
	friend ostream& operator<<(ostream&, Milk&); //���������� ��������� ������
	static void read(Stack<Milk>&); //������ ������ �� �����
	static void write(Stack<Milk>&); //������ ������ � ����
};