#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include "stack.h"
#include "hash.h"

using namespace std;

class Accounts {
	string login; //Логин аккаунта
	string password; //Пароль аккаунта
	string salt; //Соль
	string hash; //Хеш
	int role{}; //Роль, где 1 – admin, 2 – user
public:
	//Установить логин
	void setLogin(string);
	//Получить логин
	string getLogin();
	//Установить пароль
	void setPassword(string);
	//Получить пароль
	string getPassword();
	//Установить соль
	void setSalt(string);
	//Получить соль
	string getSalt();
	//Установить хеш
	void setHash(string);
	//Получить хеш
	string getHash();
	//Установить роль
	void setRole(int);
	//Получить роль
	int getRole();
	//Вход
	static int enter(Stack<Accounts>&);
	//Звездочки вместо пароля
	string enterPassword();
	//Поиск логина (сравнение)
	bool findLogin(Stack<Accounts>&, Accounts&, string);
	//Проверка пароля
	bool isCheakPassword(Stack<Accounts>&, Accounts&, string);
	//Проверка логина на повторность
	bool isCheakLogin(Stack<Accounts>&, string);
	//Регистрация нового пользователя
	static void registration(Stack<Accounts>&);
	//Меню управления учетными записями
	static void manageMenu(Stack<Accounts>&);
	//Редактирование роли
	static void editRole(Stack<Accounts>&);
	//Удаление аккаунта
	static void delAccount(Stack<Accounts>&);
	//Чтение учетных записей из файла
	static void read(Stack<Accounts>&);
	//Запись учетных записей в файл
	static void write(Stack<Accounts>&);
};

extern void mainHash(Stack<Accounts>&, Accounts&);
