#pragma once

#include "milky.h"

class Cheese : public Milky {
	string structure;
public:
	Cheese(string name, double pri, Date delivDate, Date shelfLife, string manufact, double fatCont, string str) :
		Milky(name, pri, delivDate, shelfLife, manufact, fatCont), structure(str) {} //����������� � �����������
	Cheese() : Milky(), structure("") {} //����������� �� ���������
	void setStruct(string str); //���������� ������
	string getStruct(); //�������� ������
	virtual void print(); //����� �����
	friend istream& operator>>(istream& is, Cheese&); //���������� ��������� �����
	friend ostream& operator<<(ostream& os, Cheese&); //���������� ��������� ������
	static void read(Stack<Cheese>&); //������ ������ �� �����
	static void write(Stack<Cheese>&); //������ ������ � ����
};
