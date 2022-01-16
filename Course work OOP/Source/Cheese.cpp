#include "main.h"
#include <iomanip>

void Cheese::setStruct(string str) {
	structure = str;
}

string Cheese::getStruct() {
	return structure;
}

istream& operator>>(istream& is, Cheese& cheese) {

	string productName;
	double price;
	Date deliveryDate;
	Date shelfLife;
	string manufacturer;
	double fatContent;
	const string str1 = "�������";
	const string str2 = "���������";
	const string str3 = "����������";
	const string str4 = "��������";
	int k;

	cout << "������� �������� ������: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, productName);
	cheese.setName(productName);
	cout << "������� ���� ������: ";
	is >> price;
	cheese.setPrice(price);
	cout << "������� ���� ��������: ";
	is >> deliveryDate;
	cheese.setDeliveryDate(deliveryDate);
	cout << "������� ���� ����� ��������: ";
	is >> shelfLife;
	cheese.setShelfLife(shelfLife);
	cout << "������� ����������: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, manufacturer);
	cheese.setManufact(manufacturer);
	cout << "������� % �������� ������: ";
	is >> fatContent;
	cheese.setFat(fatContent);
	cout << "������� ������ ������: " << endl;
	cout << "1 > �������" << endl;
	cout << "2 > ���������" << endl;
	cout << "3 > ����������" << endl;
	cout << "4 > ��������" << endl;
	cout << "> ";
	cin >> k;
	switch (k)
	{
	case 1:cheese.setStruct(str1);
		break;
	case 2:cheese.setStruct(str2);
		break;
	case 3:cheese.setStruct(str3);
		break;
	case 4:cheese.setStruct(str4);
		break;
	default: cout << "������!" << endl;
		break;
	}
	return is;
}

ostream& operator<<(ostream& os, Cheese& cheese) {
	Date delivDate = cheese.getDeliveryDate();
	Date shelfLife = cheese.getShelfLife();
	os << "|" << setw(15) << cheese.getName() << "|" << setw(8) << cheese.getPrice() << "|" << setw(6) << delivDate << "|"
		<< setw(6) << shelfLife << "|" << setw(14) << cheese.getManufact() << "|" << setw(12) << cheese.getFat() << "|"
		<< setw(11) << cheese.getStruct() << "|";
	return os;
}

void Cheese::print() {
	cout << setiosflags(ios::fixed) // ���������� ������������������ ���
		<< setiosflags(ios::showpoint) // ������ ���������� ���������� ����� 
		<< setprecision(2); // ��� ����� ����� ������� ;

	cout << "|" << setw(15) << "����. ������" << "|" << setw(8) << "����" << "|" << setw(14) << "���� �������." << "|" << setw(14)
		<< "���� ����." << "|" << setw(14) << "���������" << "|" << setw(12) << "��������, %" << "|" << setw(11) << "���" << "|";
}

void Cheese::read(Stack<Cheese>& stCheese) {

	struct Data {
		string productName; //�������� ��������
		double price = 0; //����
		string deliveryDateStr; //���� �������� ������
		string shelfLifeStr; //���� �������� ������
		Date deliveryDate; //���� ��������
		Date shelfLife; //���� ��������
		string manufacturer; //�������������
		double fatContent = 0; //������� ��������
		string structure; //������
	};

	int number_of_strings = 0;
	string waste;
	ifstream file(FILE_OF_CHEESE, ios::in);

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

	Cheese* cheese = new Cheese[number_of_strings / 7];
	Data* data = new Data[number_of_strings / 7];

	ifstream fin(FILE_OF_CHEESE, ios::in);

	if (!fin.is_open())
		cout << "��������� ���� �� ����������!" << endl;
	else {
		for (int i = 0; i < number_of_strings / 7; i++) {
			getline(fin, data[i].productName, '\n');
			fin >> data[i].price;
			getline(fin, waste, '\n');
			getline(fin, data[i].deliveryDateStr, '\n');
			getline(fin, data[i].shelfLifeStr, '\n');
			getline(fin, data[i].manufacturer, '\n');
			fin >> data[i].fatContent;
			getline(fin, waste, '\n');
			getline(fin, data[i].structure, '\n');
		}
	}

	for (int i = 0; i < number_of_strings / 7; i++) {
		cheese[i].setName(data[i].productName);
		cheese[i].setPrice(data[i].price);
		data[i].deliveryDate = data[i].deliveryDateStr;
		cheese[i].setDeliveryDate(data[i].deliveryDate);
		data[i].shelfLife = data[i].shelfLifeStr;
		cheese[i].setShelfLife(data[i].shelfLife);
		cheese[i].setManufact(data[i].manufacturer);
		cheese[i].setFat(data[i].fatContent);
		cheese[i].setStruct(data[i].structure);
		stCheese.push(cheese[i]);
	}

	fin.close();
}

void Cheese::write(Stack<Cheese>& stCheese) {

	struct Data {
		string productName; //�������� ��������
		double price = 0; //����
		string deliveryDateStr; //���� �������� ������
		string shelfLifeStr; //���� �������� ������
		Date deliveryDate; //���� ��������
		Date shelfLife; //���� ��������
		string manufacturer; //�������������
		double fatContent = 0; //������� ��������
		string structure; //������
	};

	int count = 0;
	count = stCheese.getCount();

	Cheese* cheese = new Cheese[count];
	Data* data = new Data[count];

	for (int i = 0; i < count; i++) {
		cheese[i] = stCheese.top(stCheese.getTmp());
		stCheese.next();
		data[i].productName = cheese[i].getName();
		data[i].price = cheese[i].getPrice();
		data[i].deliveryDate = cheese[i].getDeliveryDate();
		data[i].shelfLife = cheese[i].getShelfLife();
		data[i].manufacturer = cheese[i].getManufact();
		data[i].fatContent = cheese[i].getFat();
		data[i].structure = cheese[i].getStruct();
	}

	ofstream fout(FILE_OF_CHEESE, ios::out);

	for (int i = 0; i < count; i++) {
		fout << data[i].productName << '\n' << data[i].price << '\n' << data[i].deliveryDate << '\n' << data[i].shelfLife
			<< '\n' << data[i].manufacturer << '\n' << data[i].fatContent << '\n' << data[i].structure << '\n';
	}

	fout.close();
}