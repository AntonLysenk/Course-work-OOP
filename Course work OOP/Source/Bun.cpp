#include "main.h"
#include <iomanip>

void Bun::setFilling(string fill) {
	filling = fill;
}

string Bun::getFilling() {
	return filling;
}

istream& operator>>(istream& is, Bun& bun) {
	
	string productName;
	double price;
	Date deliveryDate;
	Date shelfLife;
	string manufacturer;
	double weight;
	const string fill1 = "С корицей";
	const string fill2 = "С повидлом";
	const string fill3 = "Со сгущенкой";
	const string fill4 = "С маком";
	int k;

	cout << "Введите название товара: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, productName);
	bun.setName(productName);
	cout << "Введите цену товара: ";
	is >> price;
	bun.setPrice(price);
	cout << "Введите дату поставки: ";
	is >> deliveryDate;
	bun.setDeliveryDate(deliveryDate);
	cout << "Введите дату срока годности: ";
	is >> shelfLife;
	bun.setShelfLife(shelfLife);
	cout << "Введите поставщика: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, manufacturer);
	bun.setManufact(manufacturer);
	cout << "Введите вес товара: ";
	is >> weight;
	bun.setWeight(weight);
	cout << "Введите начинку товара: " << endl;
	cout << "1 > С корицей" << endl;
	cout << "2 > С повидлом" << endl;
	cout << "3 > Со сгущенкой" << endl;
	cout << "4 > С маком" << endl;
	cout << "> ";
	cin >> k;
	switch (k)
	{
	case 1:bun.setFilling(fill1);
		break;
	case 2:bun.setFilling(fill2);
		break;
	case 3:bun.setFilling(fill3);
		break;
	case 4:bun.setFilling(fill4);
		break;
	default: cout << "Ошибка!" << endl;
		break;
	}
	return is;
}

ostream& operator<<(ostream& os, Bun& bun) {
	Date delivDate = bun.getDeliveryDate();
	Date shelfLife = bun.getShelfLife();
	os << "|" << setw(17) << bun.getName() << "|" << setw(8) << bun.getPrice() << "|" << setw(6) << delivDate << "|"
		<< setw(6) << shelfLife << "|" << setw(21) << bun.getManufact() << "|" << setw(8) << bun.getWeight() << "|"
		<< setw(13) << bun.getFilling() << "|";
	return os;
}

void Bun::print() {
	cout << setiosflags(ios::fixed) // нормальный неэкспоненциальный вид
		<< setiosflags(ios::showpoint) // всегда показывать десятичную точку 
		<< setprecision(2); // два знака после запятой ;

	cout << "|" << setw(17) << "Назв. товара" << "|" << setw(8) << "Цена" << "|" << setw(14) << "Дата поставк." << "|" << setw(14)
		<< "Срок годн." << "|" << setw(21) << "Поставщик" << "|" << setw(8) << "Вес, г" << "|" << setw(13) << "Начинка" << "|";
}

void Bun::read(Stack<Bun>& stBun) {
	struct Data {
		string productName; //Название продукта
		double price = 0; //Цена
		string deliveryDateStr; //Дата поставки строка
		string shelfLifeStr; //Срок годности строка
		Date deliveryDate; //Дата поставки
		Date shelfLife; //Срок годности
		string manufacturer; //Производитель
		double weight = 0; //Вес
		string fill; //Начинка
	};

	int number_of_strings = 0;
	string waste;
	ifstream file(FILE_OF_BUN, ios::in);

	if (!file.is_open())
		cout << "Указанный файл не существует!" << endl;
	else {
		if (file.is_open())
		{
			string temp;
			while (getline(file, temp))
				number_of_strings++;
		}
	}

	file.close();

	Bun* buns = new Bun[number_of_strings / 7];
	Data* data = new Data[number_of_strings / 7];

	ifstream fin(FILE_OF_BUN, ios::in);

	if (!fin.is_open())
		cout << "Указанный файл не существует!" << endl;
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
			getline(fin, data[i].fill, '\n');
		}
	}

	for (int i = 0; i < number_of_strings / 7; i++) {
		buns[i].setName(data[i].productName);
		buns[i].setPrice(data[i].price);
		data[i].deliveryDate = data[i].deliveryDateStr;
		buns[i].setDeliveryDate(data[i].deliveryDate);
		data[i].shelfLife = data[i].shelfLifeStr;
		buns[i].setShelfLife(data[i].shelfLife);
		buns[i].setManufact(data[i].manufacturer);
		buns[i].setWeight(data[i].weight);
		buns[i].setFilling(data[i].fill);
		stBun.push(buns[i]);
	}

	fin.close();
}

void Bun::write(Stack<Bun>& stBun) {
	struct Data {
		string productName; //Название продукта
		double price = 0; //Цена
		string deliveryDateStr; //Дата поставки строка
		string shelfLifeStr; //Срок годности строка
		Date deliveryDate; //Дата поставки
		Date shelfLife; //Срок годности
		string manufacturer; //Производитель
		double weight = 0; //Вес
		string fill; //Начинка
	};

	int count = 0;
	count = stBun.getCount();

	Bun* buns = new Bun[count];
	Data* data = new Data[count];

	for (int i = 0; i < count; i++) {
		buns[i] = stBun.top(stBun.getTmp());
		stBun.next();
		data[i].productName = buns[i].getName();
		data[i].price = buns[i].getPrice();
		data[i].deliveryDate = buns[i].getDeliveryDate();
		data[i].shelfLife = buns[i].getShelfLife();
		data[i].manufacturer = buns[i].getManufact();
		data[i].weight = buns[i].getWeight();
		data[i].fill = buns[i].getFilling();
	}

	ofstream fout(FILE_OF_BUN, ios::out);

	for (int i = 0; i < count; i++) {
		fout << data[i].productName << '\n' << data[i].price << '\n' << data[i].deliveryDate << '\n' << data[i].shelfLife
			<< '\n' << data[i].manufacturer << '\n' << data[i].weight << '\n' << data[i].fill << '\n';
	}

	fout.close();
}