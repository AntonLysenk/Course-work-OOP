#pragma once
#include<iostream>

using namespace std;
template<typename T>
void correctInput(T& value) //Проверка корректности ввода
{
	cin >> value;
	while (cin.fail())
	{
		cin.clear();	
		cin.ignore(32767, '\n');	
		cout << "Неверный ввод. Попробуйте еще раз: ";
		cin >> value;	
	}
}