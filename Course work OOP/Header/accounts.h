#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include "stack.h"
#include "hash.h"

using namespace std;

class Accounts {
	string login; //����� ��������
	string password; //������ ��������
	string salt; //����
	string hash; //���
	int role{}; //����, ��� 1 � admin, 2 � user
public:
	//���������� �����
	void setLogin(string);
	//�������� �����
	string getLogin();
	//���������� ������
	void setPassword(string);
	//�������� ������
	string getPassword();
	//���������� ����
	void setSalt(string);
	//�������� ����
	string getSalt();
	//���������� ���
	void setHash(string);
	//�������� ���
	string getHash();
	//���������� ����
	void setRole(int);
	//�������� ����
	int getRole();
	//����
	static int enter(Stack<Accounts>&);
	//��������� ������ ������
	string enterPassword();
	//����� ������ (���������)
	bool findLogin(Stack<Accounts>&, Accounts&, string);
	//�������� ������
	bool isCheakPassword(Stack<Accounts>&, Accounts&, string);
	//�������� ������ �� �����������
	bool isCheakLogin(Stack<Accounts>&, string);
	//����������� ������ ������������
	static void registration(Stack<Accounts>&);
	//���� ���������� �������� ��������
	static void manageMenu(Stack<Accounts>&);
	//�������������� ����
	static void editRole(Stack<Accounts>&);
	//�������� ��������
	static void delAccount(Stack<Accounts>&);
	//������ ������� ������� �� �����
	static void read(Stack<Accounts>&);
	//������ ������� ������� � ����
	static void write(Stack<Accounts>&);
};

extern void mainHash(Stack<Accounts>&, Accounts&);
