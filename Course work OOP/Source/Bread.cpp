#include "main.h"
#include <iomanip>

void Bread::setStructure(string structur) {
	structure = structur;
}

string Bread::getStructure() {
	return structure;
}

istream& operator>>(istream& is, Bread& bread) {
	
	string productName;
	double price;
	Date deliveryDate;
	Date shelfLife;
	string manufacturer;
	double weight;
	const string str1 = "���������";
	const string str2 = "������";
	const string str3 = "�����-���������";
	const string str4 = "� ���������";
	int k;

	cout << "������� �������� ������: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, productName);
	bread.setName(productName);
	cout << "������� ���� ������: ";
	is >> price;
	bread.setPrice(price);
	cout << "������� ���� ��������: ";
	is >> deliveryDate;
	bread.setDeliveryDate(deliveryDate);
	cout << "������� ���� ����� ��������: ";
	is >> shelfLife;
	bread.setShelfLife(shelfLife);
	cout << "������� ����������: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, manufacturer);
	bread.setManufact(manufacturer);
	cout << "������� ��� ������: ";
	is >> weight;
	bread.setWeight(weight);
	cout << "������� ������ ������: " << endl;
	cout << "1 > ���������" << endl;
	cout << "2 > ������" << endl;
	cout << "3 > �����-���������" << endl;
	cout << "4 > � ���������" << endl;
	cout << "> ";
	cin >> k;
	switch (k)
	{
	case 1:bread.setStructure(str1);
		break;
	case 2:bread.setStructure(str2);
		break;
	case 3:bread.setStructure(str3);
		break;
	case 4:bread.setStructure(str4);
		break;
	default: cout << "������!" << endl;
		break;
	}
	return is;
}

ostream& operator<<(ostream& os, Bread& bread) {
	Date delivDate = bread.getDeliveryDate();
	Date shelfLife = bread.getShelfLife();
	os << "|" << setw(17) << bread.getName() << "|" << setw(8) << bread.getPrice() << "|" << setw(6) << delivDate << "|"
		<< setw(6) << shelfLife << "|" << setw(14) << bread.getManufact() << "|" << setw(8) << bread.getWeight() << "|"
		<< setw(16) << bread.getStructure() << "|";
	return os;
}

void Bread::print() {
	cout << setiosflags(ios::fixed) // ���������� ������������������ ���
		<< setiosflags(ios::showpoint) // ������ ���������� ���������� ����� 
		<< setprecision(2); // ��� ����� ����� ������� ;

	cout << "|" << setw(17) << "����. ������" << "|" << setw(8) << "����" << "|" << setw(14) << "���� �������." << "|" << setw(14)
		<< "���� ����." << "|" << setw(14) << "���������" << "|" << setw(8) << "���, �" << "|" << setw(16) << "������" << "|";
}


void Bread::read(Stack<Bread>& stBread) {

	struct Data {
		string productName; //�������� ��������
		double price = 0; //����
		string deliveryDateStr; //���� �������� ������
		string shelfLifeStr; //���� �������� ������
		Date deliveryDate; //���� ��������
		Date shelfLife; //���� ��������
		string manufacturer; //�������������
		double weight = 0; //���
		string structure; //������
	};

	int number_of_strings = 0;
	string waste;
	ifstream file(FILE_OF_BREAD, ios::in);

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

	Bread* breads = new Bread[number_of_strings / 7];
	Data* data = new Data[number_of_strings / 7];

	ifstream fin(FILE_OF_BREAD, ios::in);

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
			fin >> data[i].weight;
			getline(fin, waste, '\n');
			getline(fin, data[i].structure, '\n');
		}
	}

	for (int i = 0; i < number_of_strings / 7; i++) {
		breads[i].setName(data[i].productName);
		breads[i].setPrice(data[i].price);
		data[i].deliveryDate = data[i].deliveryDateStr;
		breads[i].setDeliveryDate(data[i].deliveryDate);
		data[i].shelfLife = data[i].shelfLifeStr;
		breads[i].setShelfLife(data[i].shelfLife);
		breads[i].setManufact(data[i].manufacturer);
		breads[i].setWeight(data[i].weight);
		breads[i].setStructure(data[i].structure);
		stBread.push(breads[i]);
	}

	fin.close();
}

void Bread::write(Stack<Bread>& stBread) {

	struct Data {
		string productName; //�������� ��������
		double price = 0; //����
		string deliveryDateStr; //���� �������� ������
		string shelfLifeStr; //���� �������� ������
		Date deliveryDate; //���� ��������
		Date shelfLife; //���� ��������
		string manufacturer; //�������������
		double weight = 0; //���
		string structure; //������
	};

	int count = 0;
	count = stBread.getCount();

	Bread* breads = new Bread[count];
	Data* data = new Data[count];

	for (int i = 0; i < count; i++) {
		breads[i] = stBread.top(stBread.getTmp());
		stBread.next();
		data[i].productName = breads[i].getName();
		data[i].price = breads[i].getPrice();
		data[i].deliveryDate = breads[i].getDeliveryDate();
		data[i].shelfLife = breads[i].getShelfLife();
		data[i].manufacturer = breads[i].getManufact();
		data[i].weight = breads[i].getWeight();
		data[i].structure = breads[i].getStructure();
	}

	ofstream fout(FILE_OF_BREAD, ios::out);

	for (int i = 0; i < count; i++) {
		fout << data[i].productName << '\n' << data[i].price << '\n' << data[i].deliveryDate << '\n' << data[i].shelfLife
			<< '\n' << data[i].manufacturer << '\n' << data[i].weight << '\n' << data[i].structure << '\n';
	}

	fout.close();
}