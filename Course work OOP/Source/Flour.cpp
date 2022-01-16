#include "main.h"
#include <iomanip>

void Flour::setStructure(string structur) {
	structure = structur;
}

string Flour::getStructure() {
	return structure;
}

istream& operator>>(istream& is, Flour& flour) {
	
	string productName;
	double price;
	Date deliveryDate;
	Date shelfLife;
	string manufacturer;
	double weight;
	const string str1 = "���������";
	const string str2 = "�������";
	const string str3 = "�������";
	const string str4 = "��������������";
	int k;

	cout << "������� �������� ������: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, productName);
	flour.setName(productName);
	cout << "������� ���� ������: ";
	is >> price;
	flour.setPrice(price);
	cout << "������� ���� ��������: ";
	is >> deliveryDate;
	flour.setDeliveryDate(deliveryDate);
	cout << "������� ���� ����� ��������: ";
	is >> shelfLife;
	flour.setShelfLife(shelfLife);
	cout << "������� ����������: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, manufacturer);
	flour.setManufact(manufacturer);
	cout << "������� ��� ������: ";
	is >> weight;
	flour.setWeight(weight);
	cout << "������� ������� ������: " << endl;
	cout << "1 > ���������" << endl;
	cout << "2 > �������" << endl;
	cout << "3 > �������" << endl;
	cout << "4 > ��������������" << endl;
	cout << "> ";
	cin >> k;
	switch (k)
	{
	case 1:flour.setStructure(str1);
		break;
	case 2:flour.setStructure(str2);
		break;
	case 3:flour.setStructure(str3);
		break;
	case 4:flour.setStructure(str4);
		break;
	default: cout << "������!" << endl;
		break;
	}
	return is;
}

ostream& operator<<(ostream& os, Flour& flour) {
	Date delivDate = flour.getDeliveryDate();
	Date shelfLife = flour.getShelfLife();
	os << "|" << setw(13) << flour.getName() << "|" << setw(8) << flour.getPrice() << "|" << setw(6) << delivDate << "|"
		<< setw(6) << shelfLife << "|" << setw(13) << flour.getManufact() << "|" << setw(8) << flour.getWeight() << "|"
		<< setw(15) << flour.getStructure() << "|";
	return os;
}

void Flour::print() {
	cout << setiosflags(ios::fixed) // ���������� ������������������ ���
		<< setiosflags(ios::showpoint) // ������ ���������� ���������� ����� 
		<< setprecision(2); // ��� ����� ����� ������� ;

	cout << "|" << setw(13) << "����. ������" << "|" << setw(8) << "����" << "|" << setw(14) << "���� �������." << "|" << setw(14)
		<< "���� ����." << "|" << setw(13) << "���������" << "|" << setw(8) << "���, �" << "|" << setw(15) << "������" << "|";
}

void Flour::read(Stack<Flour>& stFlour) {
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
	ifstream file(FILE_OF_FLOUR, ios::in);

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

	Flour* flours = new Flour[number_of_strings / 7];
	Data* data = new Data[number_of_strings / 7];

	ifstream fin(FILE_OF_FLOUR, ios::in);

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
		flours[i].setName(data[i].productName);
		flours[i].setPrice(data[i].price);
		data[i].deliveryDate = data[i].deliveryDateStr;
		flours[i].setDeliveryDate(data[i].deliveryDate);
		data[i].shelfLife = data[i].shelfLifeStr;
		flours[i].setShelfLife(data[i].shelfLife);
		flours[i].setManufact(data[i].manufacturer);
		flours[i].setWeight(data[i].weight);
		flours[i].setStructure(data[i].structure);
		stFlour.push(flours[i]);
	}

	fin.close();
}

void Flour::write(Stack<Flour>& stFlour) {
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
	count = stFlour.getCount();

	Flour* flours = new Flour[count];
	Data* data = new Data[count];

	for (int i = 0; i < count; i++) {
		flours[i] = stFlour.top(stFlour.getTmp());
		stFlour.next();
		data[i].productName = flours[i].getName();
		data[i].price = flours[i].getPrice();
		data[i].deliveryDate = flours[i].getDeliveryDate();
		data[i].shelfLife = flours[i].getShelfLife();
		data[i].manufacturer = flours[i].getManufact();
		data[i].weight = flours[i].getWeight();
		data[i].structure = flours[i].getStructure();
	}

	ofstream fout(FILE_OF_FLOUR, ios::out);

	for (int i = 0; i < count; i++) {
		fout << data[i].productName << '\n' << data[i].price << '\n' << data[i].deliveryDate << '\n' << data[i].shelfLife
			<< '\n' << data[i].manufacturer << '\n' << data[i].weight << '\n' << data[i].structure << '\n';
	}

	fout.close();

}