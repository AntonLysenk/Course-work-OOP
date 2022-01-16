#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Date {
	int days;
	int months;
	int years;
public:
	Date(int d, int m, int y) : days(d), months(m), years(y) {} //����������� � �����������
	Date() : days(0), months(0), years(0) {} //����������� �� ���������
	void setDays(int); //���������� ����
	int getDays(); //�������� ����
	void setMonths(int); //���������� �����
	int getMonths(); //�������� �����
	void setYears(int); //���������� ���
	int getYears(); //�������� ���
	friend bool operator< (const Date&, const Date&); //���������� ��������� ������
	friend bool operator> (const Date&, const Date&); //���������� ��������� ������
	friend bool operator== (const Date&, const Date&); //���������� ��������� ==
	Date& operator= (string); //���������� ��������� �����
	Date& operator= (const Date&); //���������� ��������� �����
	friend istream& operator>>(istream&, Date&); //���������� ��������� �����
	friend ostream& operator<<(ostream&, Date&); //���������� ��������� ������
};

