#pragma once

#include "stack.h"
#include "date.h"
#include <iostream>
#include <string>

const int DATA = 2000;

class Algorithms {
public: 
	//���������� �� ��������
	template <class Type>
	static void sort(Stack<Type>& stack) {
		int len = 0;
		int count = stack.getCount();
		Type* array = new Type[count];
		Type object1, object2;
		string name1, name2;
		Type buf;
		for (int i = 0; i < count; i++) {
			array[i] = stack[i];
		}
		for (int k = 0; k <= count - 1; k++)
		{
			for (int i = k + 1; i < count; i++)
			{
				object1 = array[k];
				name1 = object1.getName();
				object2 = array[i];
				name2 = object2.getName();
				if (name1.length() > name2.length())
					len = name2.length();
				else
					len = name1.length();
				for (int j = 0; j < len; j++)
				{
					object1 = array[k];
					name1 = object1.getName();
					object2 = array[i];
					name2 = object2.getName();
					int a = int(name1[j]);
					int b = int(name2[j]);
					if (a < b)
					{
						buf = array[k];
						array[k] = array[i];
						array[i] = buf;
						break;
					}
					else
						if (a == b)
							continue;
						else
							break;
				}
			}
		}
		stack.Stack::~Stack();
		for (int i = 0; i < count; i++)
		{
			stack.push(array[i]);
		}
	}
	//���������� �� ����
	template <class Type>
	static void sort(Stack<Type>& stack, int flag) {
		Stack<Type> stackTo;
		int count = stack.getCount();
		Type* array = new Type[count];
		Type object;
		switch (flag) {
		case 1:
			for (int i = 0; i < count; i++) {
				array[i] = stack[i];
			}
			for (int i = 0; i < count; i++) 
				for (int j = i; j < count; j++) {
					if (array[i].getPrice() < array[j].getPrice()) {
						object = array[i];
						array[i] = array[j];
						array[j] = object;
					}
				}
			stack.Stack::~Stack();
			for (int i = 0; i < count; i++)
			{
				stack.push(array[i]);
			}
			break;
		case 2:
			for (int i = 0; i < count; i++) {
				array[i] = stack[i];
			}
			for (int i = 0; i < count; i++)
				for (int j = i; j < count; j++) {
					if (array[i].getPrice() > array[j].getPrice()) {
						object = array[i];
						array[i] = array[j];
						array[j] = object;
					}
				}
			stack.Stack::~Stack();
			for (int i = 0; i < count; i++)
			{
				stack.push(array[i]);
			}
			break;
		default:
			cout << "������!" << endl;
			break;
		}
	}
	//���������� �� ���� ��������
	template <class Type>
	static void sort(Stack<Type>& stack, char flag) {
		Stack<Type> stackTo;
		int count = stack.getCount();
		Type* array = new Type[count];
		Type object;
		switch (flag) {
		case '1':
			for (int i = 0; i < count; i++) {
				array[i] = stack[i];
			}
			for (int i = 0; i < count; i++)
				for (int j = i; j < count; j++) {
					if (array[i].getDeliveryDate() > array[j].getDeliveryDate()) {
						object = array[i];
						array[i] = array[j];
						array[j] = object;
					}
				}
			stack.Stack::~Stack();
			for (int i = 0; i < count; i++)
			{
				stack.push(array[i]);
			}
			break;
		case '2':
			for (int i = 0; i < count; i++) {
				array[i] = stack[i];
			}
			for (int i = 0; i < count; i++)
				for (int j = i; j < count; j++) {
					if (array[i].getDeliveryDate() < array[j].getDeliveryDate()) {
						object = array[i];
						array[i] = array[j];
						array[j] = object;
					}
				}
			stack.Stack::~Stack();
			for (int i = 0; i < count; i++)
			{
				stack.push(array[i]);
			}
			break;
		default:
			cout << "������!" << endl;
			break;
		}
	}
	//�������� �� �������� ��� ����������
	template <class Type>
	static 	bool del(Stack<Type>& stack, string value, int flag) {
		Stack<Type> stackTo;
		Type object;
		bool a = false;
		switch (flag) {
		case 1:
			while (!stack.isEmpty()) {
				object = stack.pop();
				if (object.getName() == value) {
					a = true;
				}
				else {
					stackTo.push(object);
				}
			}
			if (!a) {
				cout << "�����(������) � ��������� ��������� �������� �� ������(�� �������)!" << endl;
				system("pause");
			}
			while (!stackTo.isEmpty()) {
				stack.push(stackTo.pop());
			}
			return a;
			break;
		case 2:
			while (!stack.isEmpty()) {
				object = stack.pop();
				if (object.getManufact() == value) {
					a = true;
				}
				else {
					stackTo.push(object);
				}
			}
			if (!a) {
				cout << "�����(������) � ��������� ����������� �������� �� ������(�� �������)!" << endl;
				system("pause");
			}
			while (!stackTo.isEmpty()) {
				stack.push(stackTo.pop());
			}
			return a;
			break;
		default:
			cout << "������!" << endl;
			return a;
			break;
		}
	}
	//�������� �� ����
	template <class Type>
	static bool del(Stack<Type>& stack, double price) {
		Stack<Type> stackTo;
		Type object;
		bool a = false;

		while (!stack.isEmpty()) {
			object = stack.pop();
			if (object.getPrice() == price) {
				cout << "�����(������) � ��������� ����� ������� ������(�������)!" << endl;
				system("pause");
				a = true;
			}
			else {
				stackTo.push(object);
			}
		}
		if (!a) {
			cout << "�����(������) � ��������� ����� �������� �� ������(�� �������)!" << endl;
			system("pause");
		}
		while (!stackTo.isEmpty()) {
			stack.push(stackTo.pop());
		}
		return a;
	}
	//�������� �� ���� �������� ��� ����� ��������
	template <class Type>
	static bool del(Stack<Type>& stack, Date date, int flag) {
		Stack<Type> stackTo;
		Type object;
		bool a = false;

		switch (flag) {
		case 1:
			while (!stack.isEmpty()) {
				object = stack.pop();
				if (object.getDeliveryDate() == date) {
					cout << "�����(������) � ��������� ����� �������� ������� ������(�������)!" << endl;
					system("pause");
					a = true;
				}
				else {
					stackTo.push(object);
				}
			}
			if (!a) {
				cout << "�����(������) � ��������� ����� �������� �� ������(�� �������)!" << endl;
				system("pause");
			}
			while (!stackTo.isEmpty()) {
				stack.push(stackTo.pop());
			}
			return a;
			break;
		case 2:
			while (!stack.isEmpty()) {
				object = stack.pop();
				if (object.getShelfLife() == date) {
					cout << "�����(������) � ��������� ������ �������� ������� ������(�������)!" << endl;
					system("pause");
					a = true;
				}
				else {
					stackTo.push(object);
				}
			}
			if (!a) {
				cout << "�����(������) � ��������� ������ �������� �� ������(�� �������)!" << endl;
				system("pause");
			}
			while (!stackTo.isEmpty()) {
				stack.push(stackTo.pop());
			}
			return a;
			break;
		default:
			cout << "������!" << endl;
			return a;
			break;
		}
	}
	//�������� ������� � �������� ������ ��������
	template <class Type>
	static bool del(Stack<Type>& stack) {
		Stack<Type> stackTo;
		Type object;
		bool a = false;
		char today[128];
		int t_m = 0, t_y = 0, t_d = 0;
		_strdate_s(today, 128);
		t_d = ((today[3] - 48) * 10) + (today[4] - 48);
		t_m = ((today[0] - 48) * 10) + (today[1] - 48);
		t_y = ((today[6] - 48) * 10) + (today[7] - 48) + DATA;
		Date dateNow(t_d, t_m, t_y); //��������� ������� ����

		while (!stack.isEmpty()) {
			object = stack.pop();
			if (object.getShelfLife() < dateNow) {
				cout << "�����(������) � �������� ������ �������� ������� ������(�������)!" << endl;
				system("pause");
				a = true;
			}
			else {
				stackTo.push(object);
			}
		}
		if (!a) {
			cout << "�����(������) � �������� ������ �������� �� ������(�� �������)!" << endl;
			system("pause");
		}
		while (!stackTo.isEmpty()) {
			stack.push(stackTo.pop());
		}
		return a;
	}
	//�������������� ����
	template <class Type>
	static void editObj(Stack<Type>& stack, string sname, int k) {
		string name;
		double price;
		Date deliveryDate;
		Date shelfLife;
		string manufacturer;
		Type object;
		Stack<Type> stackTo;
		enum edit { Name = 1, Price, Delivery, Manufact, Shelf};
		switch (k) {
		case Name:
			cout << "������� ����� ��������: ";
			if (cin.peek() == '\n')
				cin.ignore();
			getline(cin, name);
			while (!stack.isEmpty()) {
				object = stack.pop();
				if (object.getName() == sname) {
					break;
				}
				else {
					stackTo.push(object);
				}
			}
			while (!stackTo.isEmpty()) {
				stack.push(stackTo.pop());
			}
			object.setName(name);
			stack.push(object);
			cout << "��������� ���� ������� ���������������!" << endl;
			system("pause");
			break;
		case Price:
			cout << "������� ����� ����: ";
			cin >> price;
			while (!stack.isEmpty()) {
				object = stack.pop();
				if (object.getName() == sname) {
					break;
				}
				else {
					stackTo.push(object);
				}
			}
			while (!stackTo.isEmpty()) {
				stack.push(stackTo.pop());
			}
			object.setPrice(price);
			stack.push(object);
			cout << "��������� ���� ������� ���������������!" << endl;
			system("pause");
			break;
		case Delivery:
			cout << "������� ����� ���� ��������: ";
			cin >> deliveryDate;
			while (!stack.isEmpty()) {
				object = stack.pop();
				if (object.getName() == sname) {
					break;
				}
				else {
					stackTo.push(object);
				}
			}
			while (!stackTo.isEmpty()) {
				stack.push(stackTo.pop());
			}
			object.setDeliveryDate(deliveryDate);
			stack.push(object);
			cout << "��������� ���� ������� ���������������!" << endl;
			system("pause");
			break;
		case Manufact:
			cout << "������� ������ ����������: ";
			getline(cin, manufacturer);
			while (!stack.isEmpty()) {
				object = stack.pop();
				if (object.getName() == sname) {
					break;
				}
				else {
					stackTo.push(object);
				}
			}
			while (!stackTo.isEmpty()) {
				stack.push(stackTo.pop());
			}
			object.setManufact(manufacturer);
			stack.push(object);
			cout << "��������� ���� ������� ���������������!" << endl;
			system("pause");
			break;
		case Shelf:
			cout << "������� ����� ���� ��������: ";
			cin >> shelfLife;
			while (!stack.isEmpty()) {
				object = stack.pop();
				if (object.getName() == sname) {
					break;
				}
				else {
					stackTo.push(object);
				}
			}
			while (!stackTo.isEmpty()) {
				stack.push(stackTo.pop());
			}
			object.setShelfLife(shelfLife);
			stack.push(object);
			cout << "��������� ���� ������� ���������������!" << endl;
			system("pause");
			break;
		default:
			cout << "������!" << endl;
			break;
		}
	}
	// ����� �� �������� ������
	template <class Type>
	static bool search(Stack<Type>& stack, Type& object, string name) {
		do {
			object = stack.top(stack.getTmp());
			if (object.getName() == name) {
				cout << "����� � �������� ��������� ������� ������!" << endl;
				return true;
			}
		} while (stack.next());
		stack.setTmp(stack.getHead());
		cout << "����� � �������� ��������� �� ������!" << endl;
		return false;
	}
	// ����� �� �������� ������ ��� ����������
	template <class Type>
	static bool search(Stack<Type>& stack, Stack<Type>& stack1, string value, int flag) {
		Type object();
		bool fl = false;
		switch (flag) {
		case 1:
			do {
				object = stack.top(stack.getTmp());
				if (object.getName() == value) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		case 2:
			do {
				object = stack.top(stack.getTmp());
				if (object.getManufact() == value) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		default:
			cout << "������!" << endl;
			return false;
			break;
		}
	}
	// ����� �� ����
	template <class Type>
	static bool search(Stack<Type>& stack, Stack<Type>& stack1, double price, int flag) {
		Type object;
		bool fl = false;
		switch (flag) {
		case 1:
			do {
				object = stack.top(stack.getTmp());
				if (object.getPrice() < price) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		case 2:
			do {
				object = stack.top(stack.getTmp());
				if (object.getPrice() > price) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		case 3:
			do {
				object = stack.top(stack.getTmp());
				if (object.getPrice() == price) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		default:
			cout << "������!" << endl;
			return false;
			break;
		}
	}
	// ����� �� ���� ��������
	template <class Type>
	static bool search(Stack<Type>& stack, Stack<Type>& stack1, Date date, int flag) {
		Type object;
		bool fl = false;
		switch (flag) {
		case 1:
			do {
				object = stack.top(stack.getTmp());
				if (object.getDeliveryDate() < date) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		case 2:
			do {
				object = stack.top(stack.getTmp());
				if (object.getDeliveryDate() > date) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		case 3:
			do {
				object = stack.top(stack.getTmp());
				if (object.getDeliveryDate() == date) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		default:
			cout << "������!" << endl;
			return false;
			break;
		}
	}
	// ����� �� ���� ����� ��������
	template <class Type>
	static bool search(Stack<Type>& stack, Stack<Type>& stack1, Date date, char flag) {
		Type object;
		bool fl = false;
		switch (flag) {
		case '1':
			do {
				object = stack.top(stack.getTmp());
				if (object.getShelfLife() < date) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		case '2':
			do {
				object = stack.top(stack.getTmp());
				if (object.getShelfLife() > date) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		case '3':
			do {
				object = stack.top(stack.getTmp());
				if (object.getShelfLife() == date) {
					stack1.push(object);
					fl = true;
				}
			} while (stack.next());
			stack.setTmp(stack.getHead());
			return fl;
			break;
		default:
			cout << "������!" << endl;
			return false;
			break;
		}
	}
};
