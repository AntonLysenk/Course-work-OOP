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
		Stack<Bun>& stBun, Stack<Flour>& stFlour, Stack<Pasta>& stPasta) //Меню продуктов
	{
		int k = 0, v = 0;
		enum menuProduct { Milk = 1, Cheese, Bread, Bun, Pasta, Flour, Back };
		while (true) {
			system("cls");
			cout << "-------Выберите продукт для работы------" << endl;
			cout << "1 > Молоко" << endl;
			cout << "2 > Сыр" << endl;
			cout << "3 > Хлеб" << endl;
			cout << "4 > Булочки" << endl;
			cout << "5 > Макароны" << endl;
			cout << "6 > Мука" << endl;
			cout << "7 > Назад" << endl;
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
				cout << "Вы точно хотите вернуться назад?" << endl;
				cout << "1-Да" << endl;
				cout << "0-Нет" << endl;
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
				cout << "Ошибка!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void menuWorkAdmin(Stack<Type>& stack) //Меню работы с данными администратора
	{
		int k = 0, v = 0;
		enum menuFork { View = 1, Add, Delete, Edit, Search, Sort, Back };
		Type object;
		while (true) {
			system("cls");
			cout << "--------Работа с данными в режиме администратора----------" << endl;
			cout << "1 > Просмотр" << endl;
			cout << "2 > Добавление" << endl;
			cout << "3 > Удаление" << endl;
			cout << "4 > Редактирование" << endl;
			cout << "5 > Поиск" << endl;
			cout << "6 > Сортировка" << endl;
			cout << "7 > Назад" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case View:
				Interface::printMenu(stack);
				break;
			case Add:
				cin >> object;
				cout << "Новый товар успешно добавлен!" << endl;
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
				cout << "Вы точно хотите вернуться назад?" << endl;
				cout << "1-Да" << endl;
				cout << "0-Нет" << endl;
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
				cout << "Ошибка!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void menuWorkUser(Stack<Type>& stack) //Меню работы с данными пользователя
	{
		int k = 0, v = 0;
		enum menuFork { View = 1, Search, Sort, Back };
		while (true) {
			system("cls");
			cout << "--------Работа с данными в режиме пользователя------------" << endl;
			cout << "1 > Просмотр" << endl;
			cout << "2 > Поиск" << endl;
			cout << "3 > Сортировка" << endl;
			cout << "4 > Назад" << endl;
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
				cout << "Вы точно хотите вернуться назад?" << endl;
				cout << "1-Да" << endl;
				cout << "0-Нет" << endl;
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
				cout << "Ошибка!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void sortMenu(Stack<Type>& stack) //Меню сортировок
	{
		enum sort { Name = 1, Price, Delivery, Back };
		int k = 0, v = 0;
		int flag = 0;
		char flag1;
		while (true) {
			system("cls");
			cout << "------------Меню сортировок-------------" << endl;
			cout << "1 > По названию" << endl;
			cout << "2 > По цене" << endl;
			cout << "3 > По дате поставки" << endl;
			cout << "4 > Назад" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case Name:
				Algorithms::sort(stack);
				cout << "Товары успешно отсортированы!" << endl;
				system("pause");
				break;
			case Price:
				cout << "1 > Сначала дешевые" << endl;
				cout << "2 > Сначала дорогие" << endl;
				cout << "> ";
				correctInput(flag);
				Algorithms::sort(stack, flag);
				cout << "Товары успешно отсортированы!" << endl;
				system("pause");
				break;
			case Delivery:
				cout << "1 > Сначала новые" << endl;
				cout << "2 > Сначала старые" << endl;
				cout << "> ";
				correctInput(flag1);
				Algorithms::sort(stack, flag1);
				cout << "Товары успешно отсортированы!" << endl;
				system("pause");
				break;
			case Back:
				cout << "Вы точно хотите вернуться назад?" << endl;
				cout << "1-Да" << endl;
				cout << "0-Нет" << endl;
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
				cout << "Ошибка!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void deleteMenu(Stack<Type>& stack) //Меню удаления
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
			cout << "-------Выберите параметр для удаления---------" << endl;
			cout << "1 > По названию" << endl;
			cout << "2 > По цене" << endl;
			cout << "3 > По дате поставки" << endl;
			cout << "4 > По поставщику" << endl;
			cout << "5 > По сроку годности" << endl;
			cout << "6 > Удалить товары с истекшим сроком годности" << endl;
			cout << "7 > Назад" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case Name:
				cout << "Введите название товара: ";
				if (cin.peek() == '\n')
					cin.ignore();
				getline(cin, name);
				Algorithms::del(stack, name, 1);
				break;
			case Price:
				cout << "Введите цену: ";
				cin >> price;
				Algorithms::del(stack, price);
				break;
			case Delivery:
				cout << "Введите дату поставки: ";
				cin >> deliveryDate;
				Algorithms::del(stack, deliveryDate, 1);
				break;
			case Manufact:
				cout << "Введите поставщика: ";
				if (cin.peek() == '\n')
					cin.ignore();
				getline(cin, manufacturer);
				Algorithms::del(stack, manufacturer, 2);
				break;
			case Shelf:
				cout << "Введите срок годности: ";
				cin >> shelfLife;
				Algorithms::del(stack, shelfLife, 2);
				break;
			case ShelfOut:
				Algorithms::del(stack);
				break;
			case Back:
				cout << "Вы точно хотите вернуться назад?" << endl;
				cout << "1-Да" << endl;
				cout << "0-Нет" << endl;
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
				cout << "Ошибка!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void editMenu(Stack<Type>& stack) //Меню редактирования
	{
		string name;
		int k = 0, v = 0;
		Type object;
		cout << "Введите название товара: ";
		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, name);
		cout << endl;
		if (Algorithms::search(stack, object, name)) {
			system("pause");
			system("cls");
			while (true) {
				system("cls");
				cout << "-------Выберите какое поле отредактировать------" << endl;
				cout << "1 > Название" << endl;
				cout << "2 > Цену" << endl;
				cout << "3 > Дату поставки" << endl;
				cout << "4 > Поставщика" << endl;
				cout << "5 > Срок годности" << endl;
				cout << "6 > Назад" << endl;
				cout << "> ";
				correctInput(k);
				if (k == 6) {
					cout << "Вы точно хотите вернуться назад?" << endl;
					cout << "1-Да" << endl;
					cout << "0-Нет" << endl;
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
			cout << "Товар с введенным именем не найден!" << endl;
		}
	}
	template <class Type>
	static void searchMenu(Stack<Type>& stack) //Меню поиска
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
			cout << "---------Выберите параметр поиска----------" << endl;
			cout << "1 > По названию товара" << endl;
			cout << "2 > По цене" << endl;
			cout << "3 > По дате поставки" << endl;
			cout << "4 > По дате срока годности" << endl;
			cout << "5 > По поставщику" << endl;
			cout << "6 > Назад" << endl;
			cout << "> ";
			correctInput(k);
			switch (k) {
			case Name:
				stack1.Stack::~Stack();
				cout << "Введите название товара: ";
				if (cin.peek() == '\n')
					cin.ignore();
				getline(cin, name);
				Algorithms::search(stack, stack1, name, 1);
				if (stack1.isEmpty()) {
					cout << "Товары не найдены!" << endl;
					system("pause");
				}
				else {
					cout << "Товары успешно найдены!" << endl;
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
				cout << "------Выберите-----" << endl;
				cout << "1 > Поиск товаров с ценой меньше введенной" << endl;
				cout << "2 > Поиск товаров с ценой больше введенной" << endl;
				cout << "3 > Поиск товаров с введенной ценой" << endl;
				cout << "> ";
				correctInput(k);
				if (k < 1 || k > 3)
					cout << "Ошибка выбора!" << endl;
				else {
					cout << "Введите цену: ";
					cin >> price;
					Algorithms::search(stack, stack1, price, k);
					if (stack1.isEmpty()) {
						cout << "Товары не найдены!" << endl;
						system("pause");
					}
					else {
						cout << "Товары успешно найдены!" << endl;
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
				cout << "------Выберите-----" << endl;
				cout << "1 > Поиск товаров с датой меньше введенной" << endl;
				cout << "2 > Поиск товаров с датой больше введенной" << endl;
				cout << "3 > Поиск товаров с введенной датой" << endl;
				cout << "> ";
				correctInput(k);
				if (k < 1 || k > 3)
					cout << "Ошибка выбора!" << endl;
				else {
					cout << "Введите дату: ";
					cin >> deliveryDate;
					Algorithms::search(stack, stack1, deliveryDate, k);
					if (stack1.isEmpty()) {
						cout << "Товары не найдены!" << endl;
						system("pause");
					}
					else {
						cout << "Товары успешно найдены!" << endl;
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
				cout << "------Выберите-----" << endl;
				cout << "1 > Поиск товаров с датой меньше введенной" << endl;
				cout << "2 > Поиск товаров с датой больше введенной" << endl;
				cout << "3 > Поиск товаров с введенной датой" << endl;
				cout << "> ";
				correctInput(t);
				if (t < '1' || t > '3')
					cout << "Ошибка выбора!" << endl;
				else {
					cout << "Введите дату: ";
					cin >> shelfLife;
					Algorithms::search(stack, stack1, shelfLife, t);
					if (stack1.isEmpty()) {
						cout << "Товары не найдены!" << endl;
						system("pause");
					}
					else {
						cout << "Товары успешно найдены!" << endl;
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
				cout << "Введите поставщика товара: ";
				if (cin.peek() == '\n')
					cin.ignore();
				getline(cin, manufacturer);
				Algorithms::search(stack, stack1, manufacturer, 2);
				if (stack1.isEmpty()) {
					cout << "Товары не найдены!" << endl;
					system("pause");
				}
				else {
					cout << "Товары успешно найдены!" << endl;
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
				cout << "Вы точно хотите вернуться назад?" << endl;
				cout << "1-Да" << endl;
				cout << "0-Нет" << endl;
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
				cout << "Ошибка!" << endl;
				break;
			}
		}
	}
	template <class Type>
	static void printMenu(Stack<Type>& stack) //Меню просмотра
	{
		if (stack.isEmpty()) {
			cout << "В стеке данные отсутствуют!" << endl;
			system("pause");
			system("cls");
			return;
		}
		Type object;
		object.print(); // Вывод шапки
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
		Stack<Bun>& stBun, Stack<Flour>& stFlour, Stack<Pasta>& stPasta, Stack<Accounts>& stAccounts) //Меню администратора
	{
		int k = 0, v = 0;
		bool flag = true;
		enum menuAdmin { Manage = 1, Data, Back };
		while (true) {
			system("cls");
			cout << "-----------Модуль администратора--------------" << endl;
			cout << "1 > Управление учётными записями пользователей" << endl;
			cout << "2 > Работа с данными" << endl;
			cout << "3 > Назад" << endl;
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
				cout << "Вы точно хотите вернуться назад?" << endl;
				cout << "1-Да" << endl;
				cout << "0-Нет" << endl;
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
				cout << "Ошибка!" << endl;
				break;
			}
			system("cls");
		}
	}
	static void modUser(Stack<Milk>& stMilk, Stack<Cheese>& stCheese, Stack<Bread>& stBread,
		Stack<Bun>& stBun, Stack<Flour>& stFlour, Stack<Pasta>& stPasta) //Меню пользователя
	{
		int k = 0, v = 0;
		enum menuProduct { Milk = 1, Cheese, Bread, Bun, Pasta, Flour, Back };
		while (true) {
			system("cls");
			cout << "-------Выберите продукт для работы------" << endl;
			cout << "1 > Молоко" << endl;
			cout << "2 > Сыр" << endl;
			cout << "3 > Хлеб" << endl;
			cout << "4 > Булочки" << endl;
			cout << "5 > Макароны" << endl;
			cout << "6 > Мука" << endl;
			cout << "7 > Назад" << endl;
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
				cout << "Вы точно хотите вернуться назад?" << endl;
				cout << "1-Да" << endl;
				cout << "0-Нет" << endl;
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
				cout << "Ошибка!" << endl;
				break;
			}
		}
	}
};