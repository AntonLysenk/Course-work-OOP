#pragma once

#include <iostream>

using namespace std;

template <typename type>
struct Node {
	type inf;
	Node<type>* next = nullptr;
};

template <typename type>
class Stack {
	Node<type>* head;
	Node<type>* tmp;
public:
	Stack() : head(nullptr), tmp(nullptr) {} //Конструктор по умолчанию
	~Stack() //Деструктор
	{
		if (!head) {
			delete head;
			head = nullptr;
		}
		else {
			while (head->next) {
				tmp = head;
				head = head->next;
				delete tmp;
				tmp = nullptr;
			}
			delete head;
			head = nullptr;
		}
	}
	Node<type>* getTmp(); //Получить дополнительный указатель
	void setTmp(Node<type>*); //Установить дополнительный указатель
	Node<type>* getHead(); //Получить указатель на начало стека
	void setHead(Node<type>*); //Установить указатель на начало стека
	void push(type inf); //Добавить элемент в стек
	type& top(); //Просмотреть данные с вершины стека
	type& top(Node<type>* top); //Просмотреть данные по переданному указателю
	bool next(); //Переместить дополнительный указатель на следующий элемент стека 
	type pop(); //Удалить элемент находящийся на вершине стека
	bool isEmpty(); //Проверка стека на наличие данных
	void show(); //Вывод данных
	type& operator[](const int index); //Обращение к элементу стека по номеру
	int getCount(); //Получение количества элементов в стеке
};

template <typename type>
Node<type>* Stack<type>::getTmp() {
	return tmp;
}

template <typename type>
void Stack<type>::setTmp(Node<type>* tm) {
	tmp = tm;
}

template <typename type>
Node<type>* Stack<type>::getHead() {
	return head;
}

template <typename type>
void Stack<type>::setHead(Node<type>* hd) {
	head = hd;
}

template <typename type>
void Stack<type>::push(type inf) {
	if (!head) {
		head = new Node <type>;
		head->inf = inf;
		head->next = nullptr;
	}
	else {
		Node<type>* add = new Node <type>;
		add->inf = inf;
		add->next = head;
		head = add;
	}
	tmp = head;
}

template <typename type>
type& Stack<type>::top() {
	return head->inf;
}

template <typename type>
type& Stack<type>::top(Node<type>* top) {
	return top->inf;
}

template <typename type>
bool Stack<type>::next() {
	if (isEmpty())
		return false;
	else if (!tmp->next) {
		return false;
	}
	else
		tmp = tmp->next;
	return true;
}

template <typename type>
type Stack<type>::pop() {
	if (!head) {
		cout << "Stack is empty!" << endl;
	}
	Node <type>* del = head;
	head = head->next;
	type ret = del->inf;
	delete del;
	return ret;
}

template <typename type>
bool Stack<type>::isEmpty() {
	if (head)
		return false;
	else
		return true;
}

template <typename type>
void Stack<type>::show() {
	if (!head)
		cout << "Stack is empty!" << endl;
	else {
		Node<type>* t = head;
		while (t) {
			cout << t->inf << endl;
			t = t->next;
		}
	}
}

template <typename type>
type& Stack<type>::operator[](const int index) {
	tmp = head;
	for (int i = 0; i < index; i++) {
		this->next();
	}
	return this->top(getTmp());
}

template <typename type>
int Stack<type>::getCount() {
	int count = 0;
	if (isEmpty())
		return 0;
	do {
		count++;
	} while (this->next());
	tmp = head;
	return count;
}