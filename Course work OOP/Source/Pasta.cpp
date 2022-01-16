#include "main.h"
#include <iomanip>

void Pasta::setVariety(string varie) {
	variety = varie;
}

string Pasta::getVariety() {
	return variety;
}

istream& operator>>(istream& is, Pasta& pasta) {

	string productName;
	double price;
	Date deliveryDate;
	Date shelfLife;
	string manufacturer;
	double weight;
	const string var1 = "������ �, ������ ����";
	const string var2 = "������ �, �����. ���� ����.";
	int k;

	cout << "������� �������� ������: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, productName);
	pasta.setName(productName);
	cout << "������� ���� ������: ";
	is >> price;
	pasta.setPrice(price);
	cout << "������� ���� ��������: ";
	is >> deliveryDate;
	pasta.setDeliveryDate(deliveryDate);
	cout << "������� ���� ����� ��������: ";
	is >> shelfLife;
	pasta.setShelfLife(shelfLife);
	cout << "������� ����������: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, manufacturer);
	pasta.setManufact(manufacturer);
	cout << "������� ��� ������: ";
	is >> weight;
	pasta.setWeight(weight);
	cout << "������� ������� ������: " << endl;
	cout << "1 > ������ �, ������ ����" << endl;
	cout << "2 > ������ �, �����. ���� ����." << endl;
	cout << "> ";
	cin >> k;
	switch (k)
	{
	case 1:pasta.setVariety(var1);
		break;
	case 2:pasta.setVariety(var2);
		break;
	default: cout << "������!" << endl;
		break;
	}
	return is;
}

ostream& operator<<(ostream& os, Pasta& pasta) {
	Date delivDate = pasta.getDeliveryDate();
	Date shelfLife = pasta.getShelfLife();
	os << "|" << setw(19) << pasta.getName() << "|" << setw(8) << pasta.getPrice() << "|" << setw(6) << delivDate << "|"
		<< setw(6) << shelfLife << "|" << setw(15) << pasta.getManufact() << "|" << setw(8) << pasta.getWeight() << "|"
		<< setw(28) << pasta.getVariety() << "|";
	return os;
}

void Pasta::print() {
	cout << setiosflags(ios::fixed) // ���������� ������������������ ���
		<< setiosflags(ios::showpoint) // ������ ���������� ���������� ����� 
		<< setprecision(2); // ��� ����� ����� ������� ;

	cout << "|" << setw(19) << "����. ������" << "|" << setw(8) << "����" << "|" << setw(14) << "���� �������." << "|" << setw(14)
		<< "���� ����." << "|" << setw(15) << "���������" << "|" << setw(8) << "���, �" << "|" << setw(28) << "����" << "|";
}

void Pasta::read(Stack<Pasta>& stPasta) {
	struct Data {
		string productName; //�������� ��������
		double price = 0; //����
		string deliveryDateStr; //���� �������� ������
		string shelfLifeStr; //���� �������� ������
		Date deliveryDate; //���� ��������
		Date shelfLife; //���� ��������
		string manufacturer; //�������������
		double weight = 0; //���
		string variety; //����
	};

	int number_of_strings = 0;
	string waste;
	ifstream file(FILE_OF_PASTA, ios::in);

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

	Pasta* pasta = new Pasta[number_of_strings / 7];
	Data* data = new Data[number_of_strings / 7];

	ifstream fin(FILE_OF_PASTA, ios::in);

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
			getline(fin, data[i].variety, '\n');
		}
	}

	for (int i = 0; i < number_of_strings / 7; i++) {
		pasta[i].setName(data[i].productName);
		pasta[i].setPrice(data[i].price);
		data[i].deliveryDate = data[i].deliveryDateStr;
		pasta[i].setDeliveryDate(data[i].deliveryDate);
		data[i].shelfLife = data[i].shelfLifeStr;
		pasta[i].setShelfLife(data[i].shelfLife);
		pasta[i].setManufact(data[i].manufacturer);
		pasta[i].setWeight(data[i].weight);
		pasta[i].setVariety(data[i].variety);
		stPasta.push(pasta[i]);
	}

	fin.close();
}

void Pasta::write(Stack<Pasta>& stPasta) {
	struct Data {
		string productName; //�������� ��������
		double price = 0; //����
		string deliveryDateStr; //���� �������� ������
		string shelfLifeStr; //���� �������� ������
		Date deliveryDate; //���� ��������
		Date shelfLife; //���� ��������
		string manufacturer; //�������������
		double weight = 0; //���
		string variety; //����
	};

	int count = 0;
	count = stPasta.getCount();

	Pasta* pasta = new Pasta[count];
	Data* data = new Data[count];

	for (int i = 0; i < count; i++) {
		pasta[i] = stPasta.top(stPasta.getTmp());
		stPasta.next();
		data[i].productName = pasta[i].getName();
		data[i].price = pasta[i].getPrice();
		data[i].deliveryDate = pasta[i].getDeliveryDate();
		data[i].shelfLife = pasta[i].getShelfLife();
		data[i].manufacturer = pasta[i].getManufact();
		data[i].weight = pasta[i].getWeight();
		data[i].variety = pasta[i].getVariety();
	}

	ofstream fout(FILE_OF_PASTA, ios::out);

	for (int i = 0; i < count; i++) {
		fout << data[i].productName << '\n' << data[i].price << '\n' << data[i].deliveryDate << '\n' << data[i].shelfLife
			<< '\n' << data[i].manufacturer << '\n' << data[i].weight << '\n' << data[i].variety << '\n';
	}

	fout.close();
}