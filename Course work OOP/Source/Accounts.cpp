#include "main.h"

void Accounts::setLogin(string log) {
	login = log;
}

string Accounts::getLogin() {
	return login;
}

void Accounts::setPassword(string passw) {
	password = passw;
}

string Accounts::getPassword() {
	return password;
}

void Accounts::setSalt(string sl) {
	salt = sl;
}

string Accounts::getSalt() {
	return salt;
}

void Accounts::setHash(string hs) {
	hash = hs;
}

string Accounts::getHash() {
	return hash;
}

void Accounts::setRole(int rl) {
	role = rl;
}

int Accounts::getRole() {
	return role;
}

//����
int Accounts::enter(Stack<Accounts>& stAccounts)
{
	bool flag_1 = false, l = false;
	string login, password;
	int role = 2;
	int num = 0;
	Accounts account;
	while (!flag_1)
	{
		cout << "=========================" << endl;
		cout << "������� �����: ";
		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, login);
		account.findLogin(stAccounts, account, login);
		cout << "������� ������: ";
		password = account.enterPassword();
		cout << endl;
		cout << "=========================" << endl;
		cout << endl;
		flag_1 = account.isCheakPassword(stAccounts, account, password);
		if (!flag_1)
		{
			cout << "�������� ����� ��� ������!" << endl << endl;
			cout << "1 > ���������� ����" << endl;
			cout << "0 > �����" << endl;
			cout << "> ";
			correctInput(l);
			if (!l)
				flag_1 = true;
			else
				flag_1 = false;
			system("cls");
		}
		else
		{
			if (account.getRole() == 1) {
				cout << "�� ����� � ������� ��� �������������!" << endl;
				system("pause");
				system("cls");
				return 1;
			}
			else {
				cout << "�� ����� � ������� ��� ������������!" << endl;
				system("pause");
				system("cls");
				return 2;
			}
		}
	}
	return -1;
}

//��������� ������ ������
string Accounts::enterPassword() {
	string pass;
	int ch = 0;
	while (true)
	{
		ch = _getch();
		if (ch == 13)
			break;

		if (ch == 8)
		{
			cout << (char)8 << ' ' << char(8);
			if (!pass.empty())
				pass.erase(pass.length() - 1);
		}
		else
		{
			cout << '*';
			pass += (char)ch;
		}
	}
	return pass;
}

//����� ������ (���������)
bool Accounts::findLogin(Stack<Accounts>& stAccounts, Accounts& account, string login) {
	int i = 0;
	if (stAccounts.isEmpty()) {
		cout << "���� ��������� ����!" << endl;
		return false;
	}
	do {
		account = stAccounts.top(stAccounts.getTmp());
		if (account.getLogin() == login) {
			stAccounts.setTmp(stAccounts.getHead());
			return true;
		}
	} while (stAccounts.next());
	return false;
}

//�������� ������
bool Accounts::isCheakPassword(Stack<Accounts>& stAccounts, Accounts& account, string password)
{
	string salt = account.getSalt();
	string hash = sha256(sha256(password + salt) + sha256(password));
	if (account.getHash() == hash)
		return true;
	return false;
}

//�������� ������ �� �����������
bool Accounts::isCheakLogin(Stack<Accounts>& stAccounts, string login)
{
	Accounts account;
	if (stAccounts.isEmpty())
		return true;
	do {
		account = stAccounts.top(stAccounts.getTmp());
		if (login == account.getLogin())
			return false;
	} while (stAccounts.next());
	return true;
}

//����������� ������ ������������
void Accounts::registration(Stack<Accounts>& stAccounts)
{
	bool flag = false, flag_1 = false;
	Accounts account;
	string login;
	string password;
	cout << "�������� ������ �������� � �������" << endl;
	while (!flag)
	{
		cout << "������� �����: ";
		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, login);
		flag = account.isCheakLogin(stAccounts, login);
		if (!flag)
		{
			cout << "����� ��� �����!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	while (!flag_1)
	{
		cout << "������� ������: ";
		password = account.enterPassword();
		cout << endl;
		if (password == " ")
		{
			cout << "������ ������������ ������!" << endl;
			system("pause");
			system("cls");
		}
		else 
			break;
	}
	account.setLogin(login);
	account.setPassword(password);
	mainHash(stAccounts, account);
	account.setRole(2);
	stAccounts.push(account);
	cout << "������������ ������� ���������������!" << endl;
	system("pause");
	system("cls");
}

//�������������� ����
void Accounts::editRole(Stack<Accounts>& stAccounts) {
	Stack<Accounts> stackTo;
	Accounts account;
	string login;
	int rol = 0;
	bool flag = true;
	cout << "������� ����� ������������� ������: ";
	cin >> login;
	while (flag) {
		cout << "������� ����� ����: " << endl;
		cout << "1 > �����" << endl;
		cout << "2 > ������������" << endl;
		cout << "> ";
		correctInput(rol);
		if (rol == 1 || rol == 2) {
			flag = false;
		}
		else {
			cout << "������ ���� �� ����������!" << endl;
			cout << "���������� ��� ���" << endl;
			system("pause");
			system("cls");
		}
	}
	account.findLogin(stAccounts, account, login);
	if (account.getLogin() != "") {
		while (!stAccounts.isEmpty()) {
			account = stAccounts.pop();
			if (account.getLogin() == login) {
				break;
			}
			else {
				stackTo.push(account);
			}
		}
		while (!stackTo.isEmpty()) {
			stAccounts.push(stackTo.pop());
		}
		account.setRole(rol);
		stAccounts.push(account);
		cout << "���� ������������ � ��������� ������� ������� ��������!" << endl;
		system("pause");
	}
	else {
		cout << "������ � ��������� ������� �����������!" << endl;
		system("pause");
	}
}

//�������� ��������
void Accounts::delAccount(Stack<Accounts>& stAccounts) {
	Stack<Accounts> stackTo;
	Accounts account;
	string login;
	bool a = false;

	cout << "������� ����� ��������� ������: ";
	cin >> login;

	while (!stAccounts.isEmpty()) {
		account = stAccounts.pop();
		if (account.getLogin() == login) {
			a = true;
			cout << "������� � ��������� ������� ������� ������!" << endl;
			system("pause");
			break;
		}
		else {
			stackTo.push(account);
		}
	}
	if (!a) {
		cout << "������� � ��������� ������� �� ������!" << endl;
		system("pause");
	}
	while (!stackTo.isEmpty()) {
		stAccounts.push(stackTo.pop());
	}
}

//���� ���������� �������� ��������
void Accounts::manageMenu(Stack<Accounts>& stAccounts) {
	int k = 0, v = 0;
	while (true) {
		system("cls");
		cout << "--------���������� �������� ��������---------" << endl;
		cout << "1 > ��������� ���� ������� ������" << endl;
		cout << "2 > �������� ������� ������" << endl;
		cout << "3 > �����" << endl;
		cout << "> ";
		correctInput(k);
		switch (k) {
		case 1:
			Accounts::editRole(stAccounts);
			break;
		case 2:
			Accounts::delAccount(stAccounts);
			break;
		case 3:
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

//������ ������� ������� �� �����
void Accounts::read(Stack<Accounts>& stAccounts) {

	struct Data {
		string login; //����� ��������
		string salt; //����
		string hash; //���
		int role{}; //����, ��� 1 � admin, 2 � user
	};

	int number_of_strings = 0;
	ifstream file(FILE_OF_ACCOUNTS, ios::in);

	if (!file.is_open())
		cout << "��������� ���� �� ����������!" << endl;
	else {
		if (file.is_open())
		{
			string temp;
			while (getline(file, temp))
				number_of_strings++;
		}
	}

	file.close();

	Accounts* accounts = new Accounts[number_of_strings];
	Data* data = new Data[number_of_strings];

	ifstream fin(FILE_OF_ACCOUNTS, ios::in);

	if (!fin.is_open())
		cout << "��������� ���� �� ����������!" << endl;
	else {
		for (int i = 0; i < number_of_strings; i++) {
			fin >> data[i].login >> data[i].salt >> data[i].hash >> data[i].role;
		}
	}

	for (int i = 0; i < number_of_strings; i++) {
		accounts[i].setLogin(data[i].login);
		accounts[i].setSalt(data[i].salt);
		accounts[i].setHash(data[i].hash);
		accounts[i].setRole(data[i].role);
		stAccounts.push(accounts[i]);
	}

	fin.close();
}

//������ ������� ������� � ����
void Accounts::write(Stack<Accounts>& stAccounts) {

	struct Data {
		string login; //����� ��������
		string salt; //����
		string hash; //���
		int role{}; //����, ��� 1 � admin, 2 � user
	};

	int count = 0;
	count = stAccounts.getCount();

	Accounts* accounts = new Accounts[count];
	Data* data = new Data[count];

	for (int i = 0; i < count; i++) {
		accounts[i] = stAccounts.top(stAccounts.getTmp());
		stAccounts.next();
		data[i].login = accounts[i].getLogin();
		data[i].salt = accounts[i].getSalt();
		data[i].hash = accounts[i].getHash();
		data[i].role = accounts[i].getRole();
	}

	ofstream fout(FILE_OF_ACCOUNTS, ios::out);

	for (int i = 0; i < count; i++) {
		fout << data[i].login << " " << " " << data[i].salt
			<< " " << data[i].hash << " " << data[i].role << '\n';
	}

	fout.close();
}