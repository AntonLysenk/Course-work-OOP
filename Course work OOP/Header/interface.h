#pragma once

#include "bread.h"
#include "bun.h"
#include "flour.h"
#include "milk.h"
#include "pasta.h"
#include "cheese.h"
#include "date.h"
#include "correctInput.h"
#include "algorithms.h"
#include "accounts.h"

class Interface {
public:
	static void menuProducts(Stack<Milk>& stMilk, Stack<Cheese>& stCheese, Stack<Bread>& stBread,
		Stack<Bun>& stBun, Stack<Flour>& stFlour, Stack<Pasta>& stPasta) //���� ���������
	{
		int k = 0, v = 0;
		enum menuProduct { Milk = 1, Cheese, Bread, Bun, Pasta, Flour, Back };
		while (true) {
			system("cls");
			cout << "-------�������� ������� ��� ������------" << endl;
			cout << "1 > ������" << endl;
			cout << "2 > ���" << endl;
			cout << "3 > ����" << endl;
			cout << "4 > �������" << endl;
			cout << "5 > ��������" << endl;
			cout << "6 > ����" << endl;
			cout << "7 > �����" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case Milk: 
				Interface::menuWorkAdmin(stMilk);
				break;
			case Cheese: 
				Interface::menuWorkAdmin(stCheese);
				break;
			case Bread:	
				Interface::menuWorkAdmin(stBread);
				break;
			case Bun: 
				Interface::menuWorkAdmin(stBun);
				break;
			case Pasta:	
				Interface::menuWorkAdmin(stPasta);
				break;
			case Flour:	
				Interface::menuWorkAdmin(stFlour);
				break;
			case Back: 
				cout << "�� ����� ������ ��������� �����?" << endl;
				cout << "1-��" << endl;
				cout << "0-���" << endl;
				cout << "> ";
				correctInput(v);
				if (v) {
					system("cls");
					return;
				}
				else
					system("cls");
				break;
			default:
				cout << "������!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void menuWorkAdmin(Stack<Type>& stack) //���� ������ � ������� ��������������
	{
		int k = 0, v = 0;
		enum menuFork { View = 1, Add, Delete, Edit, Search, Sort, Back };
		Type object;
		while (true) {
			system("cls");
			cout << "--------������ � ������� � ������ ��������������----------" << endl;
			cout << "1 > ��������" << endl;
			cout << "2 > ����������" << endl;
			cout << "3 > ��������" << endl;
			cout << "4 > ��������������" << endl;
			cout << "5 > �����" << endl;
			cout << "6 > ����������" << endl;
			cout << "7 > �����" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case View:
				Interface::printMenu(stack);
				break;
			case Add:
				cin >> object;
				cout << "����� ����� ������� ��������!" << endl;
				system("pause");
				stack.push(object);
				break;
			case Delete:
				Interface::deleteMenu(stack);
				break;
			case Edit:
				Interface::editMenu(stack);
				break;
			case Search:
				Interface::searchMenu(stack);
				break;
			case Sort:
				Interface::sortMenu(stack);
				break;
			case Back:
				cout << "�� ����� ������ ��������� �����?" << endl;
				cout << "1-��" << endl;
				cout << "0-���" << endl;
				cout << "> ";
				correctInput(v);
				if (v) {
					system("cls");
					return;
				}
				else
					system("cls");
				break;
			default:
				cout << "������!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void menuWorkUser(Stack<Type>& stack) //���� ������ � ������� ������������
	{
		int k = 0, v = 0;
		enum menuFork { View = 1, Search, Sort, Back };
		while (true) {
			system("cls");
			cout << "--------������ � ������� � ������ ������������------------" << endl;
			cout << "1 > ��������" << endl;
			cout << "2 > �����" << endl;
			cout << "3 > ����������" << endl;
			cout << "4 > �����" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case View:
				Interface::printMenu(stack);
				break;
			case Search:
				Interface::searchMenu(stack);
				break;
			case Sort:
				Interface::sortMenu(stack);
				break;
			case Back:
				cout << "�� ����� ������ ��������� �����?" << endl;
				cout << "1-��" << endl;
				cout << "0-���" << endl;
				cout << "> ";
				correctInput(v);
				if (v) {
					system("cls");
					return;
				}
				else
					system("cls");
				break;
			default:
				cout << "������!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void sortMenu(Stack<Type>& stack) //���� ����������
	{
		enum sort { Name = 1, Price, Delivery, Back };
		int k = 0, v = 0;
		int flag = 0;
		char flag1;
		while (true) {
			system("cls");
			cout << "------------���� ����������-------------" << endl;
			cout << "1 > �� ��������" << endl;
			cout << "2 > �� ����" << endl;
			cout << "3 > �� ���� ��������" << endl;
			cout << "4 > �����" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case Name:
				Algorithms::sort(stack);
				cout << "������ ������� �������������!" << endl;
				system("pause");
				break;
			case Price:
				cout << "1 > ������� �������" << endl;
				cout << "2 > ������� �������" << endl;
				cout << "> ";
				correctInput(flag);
				Algorithms::sort(stack, flag);
				cout << "������ ������� �������������!" << endl;
				system("pause");
				break;
			case Delivery:
				cout << "1 > ������� �����" << endl;
				cout << "2 > ������� ������" << endl;
				cout << "> ";
				correctInput(flag1);
				Algorithms::sort(stack, flag1);
				cout << "������ ������� �������������!" << endl;
				system("pause");
				break;
			case Back:
				cout << "�� ����� ������ ��������� �����?" << endl;
				cout << "1-��" << endl;
				cout << "0-���" << endl;
				cout << "> ";
				correctInput(v);
				if (v) {
					system("cls");
					return;
				}
				else
					system("cls");
				break;
			default: 
				cout << "������!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void deleteMenu(Stack<Type>& stack) //���� ��������
	{
		int k = 0, v = 0;
		enum delet { Name = 1, Price, Delivery, Manufact, Shelf, ShelfOut, Back };
		string name;
		double price;
		Date deliveryDate;
		Date shelfLife;
		string manufacturer;
		while (true) {
			system("cls");
			cout << "-------�������� �������� ��� ��������---------" << endl;
			cout << "1 > �� ��������" << endl;
			cout << "2 > �� ����" << endl;
			cout << "3 > �� ���� ��������" << endl;
			cout << "4 > �� ����������" << endl;
			cout << "5 > �� ����� ��������" << endl;
			cout << "6 > ������� ������ � �������� ������ ��������" << endl;
			cout << "7 > �����" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case Name:
				cout << "������� �������� ������: ";
				if (cin.peek() == '\n')
					cin.ignore();
				getline(cin, name);
				Algorithms::del(stack, name, 1);
				break;
			case Price:
				cout << "������� ����: ";
				cin >> price;
				Algorithms::del(stack, price);
				break;
			case Delivery:
				cout << "������� ���� ��������: ";
				cin >> deliveryDate;
				Algorithms::del(stack, deliveryDate, 1);
				break;
			case Manufact:
				cout << "������� ����������: ";
				if (cin.peek() == '\n')
					cin.ignore();
				getline(cin, manufacturer);
				Algorithms::del(stack, manufacturer, 2);
				break;
			case Shelf:
				cout << "������� ���� ��������: ";
				cin >> shelfLife;
				Algorithms::del(stack, shelfLife, 2);
				break;
			case ShelfOut:
				Algorithms::del(stack);
				break;
			case Back:
				cout << "�� ����� ������ ��������� �����?" << endl;
				cout << "1-��" << endl;
				cout << "0-���" << endl;
				cout << "> ";
				correctInput(v);
				if (v) {
					system("cls");
					return;
				}
				else
					system("cls");
				break;
			default: 
				cout << "������!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void editMenu(Stack<Type>& stack) //���� ��������������
	{
		string name;
		int k = 0, v = 0;
		Type object;
		cout << "������� �������� ������: ";
		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, name);
		cout << endl;
		if (Algorithms::search(stack, object, name)) {
			system("pause");
			system("cls");
			while (true) {
				system("cls");
				cout << "-------�������� ����� ���� ���������������------" << endl;
				cout << "1 > ��������" << endl;
				cout << "2 > ����" << endl;
				cout << "3 > ���� ��������" << endl;
				cout << "4 > ����������" << endl;
				cout << "5 > ���� ��������" << endl;
				cout << "6 > �����" << endl;
				cout << "> ";
				correctInput(k);
				if (k == 6) {
					cout << "�� ����� ������ ��������� �����?" << endl;
					cout << "1-��" << endl;
					cout << "0-���" << endl;
					cout << "> ";
					correctInput(v);
					if (v) {
						system("cls");
						return;
					}
					else
						system("cls");
					break;
				}
				Algorithms::editObj(stack, name, k);
			}
		}
		else {
			cout << "����� � ��������� ������ �� ������!" << endl;
		}
	}
	template <class Type>
	static void searchMenu(Stack<Type>& stack) //���� ������
	{
		int k = 0, v = 0;
		enum search { Name = 1, Price, Delivery, Shelf, Manufact, Back };
		string name;
		double price = 0;
		Date deliveryDate;
		Date shelfLife;
		Date null;
		string manufacturer;

		Type object;
		Stack<Type> stack1;
		while (true) {
			system("cls");
			cout << "---------�������� �������� ������----------" << endl;
			cout << "1 > �� �������� ������" << endl;
			cout << "2 > �� ����" << endl;
			cout << "3 > �� ���� ��������" << endl;
			cout << "4 > �� ���� ����� ��������" << endl;
			cout << "5 > �� ����������" << endl;
			cout << "6 > �����" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case Name:
				stack1.Stack::~Stack();
				cout << "������� �������� ������: ";
				if (cin.peek() == '\n')
					cin.ignore();
				getline(cin, name);
				Algorithms::search(stack, stack1, name, 1);
				if (stack1.isEmpty()) {
					cout << "������ �� �������!" << endl;
					system("pause");
				}
				else {
					cout << "������ ������� �������!" << endl;
					object.print();
					do {
						object = stack1.top(stack1.getTmp());
						cout << endl;
						cout << object;
					} while (stack1.next());
					cout << endl;
					system("pause");
				}
				break;
			case Price:
				stack1.Stack::~Stack();
				system("cls");
				cout << "------��������-----" << endl;
				cout << "1 > ����� ������� � ����� ������ ���������" << endl;
				cout << "2 > ����� ������� � ����� ������ ���������" << endl;
				cout << "3 > ����� ������� � ��������� �����" << endl;
				cout << "> ";
				correctInput(k);
				if (k < 1 || k > 3)
					cout << "������ ������!" << endl;
				else {
					cout << "������� ����: ";
					cin >> price;
					Algorithms::search(stack, stack1, price, k);
					if (stack1.isEmpty()) {
						cout << "������ �� �������!" << endl;
						system("pause");
					}
					else {
						cout << "������ ������� �������!" << endl;
						object.print();
						do {
							object = stack1.top(stack1.getTmp());
							cout << endl;
							cout << object;
						} while (stack1.next());
						cout << endl;
						system("pause");
					}
				}
				break;
			case Delivery:
				stack1.Stack::~Stack();
				deliveryDate = null;
				system("cls");
				cout << "------��������-----" << endl;
				cout << "1 > ����� ������� � ����� ������ ���������" << endl;
				cout << "2 > ����� ������� � ����� ������ ���������" << endl;
				cout << "3 > ����� ������� � ��������� �����" << endl;
				cout << "> ";
				correctInput(k);
				if (k < 1 || k > 3)
					cout << "������ ������!" << endl;
				else {
					cout << "������� ����: ";
					cin >> deliveryDate;
					Algorithms::search(stack, stack1, deliveryDate, k);
					if (stack1.isEmpty()) {
						cout << "������ �� �������!" << endl;
						system("pause");
					}
					else {
						cout << "������ ������� �������!" << endl;
						object.print();
						do {
							object = stack1.top(stack1.getTmp());
							cout << endl;
							cout << object;
						} while (stack1.next());
						cout << endl;
						system("pause");
					}
				}
				break;
			case Shelf:
				stack1.Stack::~Stack();
				shelfLife = null;
				char t;
				system("cls");
				cout << "------��������-----" << endl;
				cout << "1 > ����� ������� � ����� ������ ���������" << endl;
				cout << "2 > ����� ������� � ����� ������ ���������" << endl;
				cout << "3 > ����� ������� � ��������� �����" << endl;
				cout << "> ";
				correctInput(t);
				if (t < '1' || t > '3')
					cout << "������ ������!" << endl;
				else {
					cout << "������� ����: ";
					cin >> shelfLife;
					Algorithms::search(stack, stack1, shelfLife, t);
					if (stack1.isEmpty()) {
						cout << "������ �� �������!" << endl;
						system("pause");
					}
					else {
						cout << "������ ������� �������!" << endl;
						object.print();
						do {
							object = stack1.top(stack1.getTmp());
							cout << endl;
							cout << object;
						} while (stack1.next());
						cout << endl;
						system("pause");
					}
				}
				break;
			case Manufact:
				stack1.Stack::~Stack();
				cout << "������� ���������� ������: ";
				if (cin.peek() == '\n')
					cin.ignore();
				getline(cin, manufacturer);
				Algorithms::search(stack, stack1, manufacturer, 2);
				if (stack1.isEmpty()) {
					cout << "������ �� �������!" << endl;
					system("pause");
				}
				else {
					cout << "������ ������� �������!" << endl;
					object.print();
					do {
						object = stack1.top(stack1.getTmp());
						cout << endl;
						cout << object;
					} while (stack1.next());
					cout << endl;
					system("pause");
				}
				break;
			case Back: 
				cout << "�� ����� ������ ��������� �����?" << endl;
				cout << "1-��" << endl;
				cout << "0-���" << endl;
				cout << "> ";
				correctInput(v);
				if (v) {
					system("cls");
					return;
				}
				else
					system("cls");
				break;
			default: 
				cout << "������!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void printMenu(Stack<Type>& stack) //���� ���������
	{
		if (stack.isEmpty()) {
			cout << "� ����� ������ �����������!" << endl;
			system("pause");
			system("cls");
			return;
		}
		Type object;
		object.print(); // ����� �����
		do {
			object = stack.top(stack.getTmp());
			cout << endl << object;
		} while (stack.next());
		stack.setTmp(stack.getHead());
		cout << endl;
		system("pause");
		system("cls");
	}
	static void modAdmin(Stack<Milk>& stMilk, Stack<Cheese>& stCheese, Stack<Bread>& stBread,
		Stack<Bun>& stBun, Stack<Flour>& stFlour, Stack<Pasta>& stPasta, Stack<Accounts>& stAccounts) //���� ��������������
	{
		int k = 0, v = 0;
		bool flag = true;
		enum menuAdmin { Manage = 1, Data, Back };
		while (true) {
			system("cls");
			cout << "-----------������ ��������������--------------" << endl;
			cout << "1 > ���������� �������� �������� �������������" << endl;
			cout << "2 > ������ � �������" << endl;
			cout << "3 > �����" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case Manage:
				Accounts::manageMenu(stAccounts);
				break;
			case Data:
				Interface::menuProducts(stMilk, stCheese, stBread, stBun, stFlour, stPasta);
				break;
			case Back:
				cout << "�� ����� ������ ��������� �����?" << endl;
				cout << "1-��" << endl;
				cout << "0-���" << endl;
				cout << "> ";
				correctInput(v);
				if (v) {
					system("cls");
					return;
				}
				else
					system("cls");
				break;
			default:
				cout << "������!" << endl;
				break;
			}
			system("cls");
		}
	}
	static void modUser(Stack<Milk>& stMilk, Stack<Cheese>& stCheese, Stack<Bread>& stBread,
		Stack<Bun>& stBun, Stack<Flour>& stFlour, Stack<Pasta>& stPasta) //���� ������������
	{
		int k = 0, v = 0;
		enum menuProduct { Milk = 1, Cheese, Bread, Bun, Pasta, Flour, Back };
		while (true) {
			system("cls");
			cout << "-------�������� ������� ��� ������------" << endl;
			cout << "1 > ������" << endl;
			cout << "2 > ���" << endl;
			cout << "3 > ����" << endl;
			cout << "4 > �������" << endl;
			cout << "5 > ��������" << endl;
			cout << "6 > ����" << endl;
			cout << "7 > �����" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case Milk: 
				Interface::menuWorkUser(stMilk);
				break;
			case Cheese: 
				Interface::menuWorkUser(stCheese);
				break;
			case Bread:	
				Interface::menuWorkUser(stBread);
				break;
			case Bun: 
				Interface::menuWorkUser(stBun);
				break;
			case Pasta:	
				Interface::menuWorkUser(stPasta);
				break;
			case Flour:	
				Interface::menuWorkUser(stFlour);
				break;
			case Back:
				cout << "�� ����� ������ ��������� �����?" << endl;
				cout << "1-��" << endl;
				cout << "0-���" << endl;
				cout << "> ";
				correctInput(v);
				if (v) {
					system("cls");
					return;
				}
				else
					system("cls");
				break;
			default:
				cout << "������!" << endl;
				break;
			}
		}
	}
};