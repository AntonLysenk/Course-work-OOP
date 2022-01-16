#include "main.h"

int Authorization(Stack<Accounts>&);
int menuAuthorization();

int main() {
	system("color E0");
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	Stack<Milk> stMilk;
	Stack<Cheese> stCheese;
	Stack<Bread> stBread;
	Stack<Bun> stBun;
	Stack<Flour> stFlour;
	Stack<Pasta> stPasta;
	Stack<Accounts> stAccounts;

	enum main { Admin = 1, User, Back };

	Milk::read(stMilk);
	Cheese::read(stCheese);
	Bread::read(stBread);
	Bun::read(stBun);
	Flour::read(stFlour);
	Pasta::read(stPasta);
	Accounts::read(stAccounts);

	while (true) {
		switch (Authorization(stAccounts)) {
		case Admin:
			Interface::modAdmin(stMilk, stCheese, stBread, stBun, stFlour, stPasta, stAccounts);
			break;
		case User:
			Interface::modUser(stMilk, stCheese, stBread, stBun, stFlour, stPasta);
			break;
		case Back:
			Milk::write(stMilk);
			Cheese::write(stCheese);
			Bread::write(stBread);
			Bun::write(stBun);
			Flour::write(stFlour);
			Pasta::write(stPasta);
			Accounts::write(stAccounts);
			return 0;
		default:
			cout << "������!" << endl;
			break;
		}
	}
}

int menuAuthorization() {
	int k = 0;
	cout << "---------�����������---------" << endl;
	cout << "1 > ����" << endl;
	cout << "2 > ������������������" << endl;
	cout << "3 > �����" << endl;
	cout << "> ";
	correctInput(k);
	return k;
}

int Authorization(Stack<Accounts>& stAccounts) {
	int flag = -1, v = 0;
	enum autorization { Input = 1, Regist, Back };
	while (flag == -1) {
		switch (menuAuthorization()) {
		case Input:
			flag = Accounts::enter(stAccounts);
			break;
		case Regist:
			Accounts::registration(stAccounts);
			break;
		case Back:
			cout << "�� ����� ������ ��������� ������?" << endl;
			cout << "1-��" << endl;
			cout << "0-���" << endl;
			cout << "> ";
			correctInput(v);
			if (v) {
				system("cls");
				return Back;
			}
			else
				system("cls");
			break;
		default:
			cout << "������!" << endl;
			break;
		}
	}
	return flag;
}