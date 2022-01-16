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
	const string str1 = "Твердый";
	const string str2 = "Творожный";
	const string str3 = "Плавленный";
	const string str4 = "Копчёный";
	int k;

	cout << "Введите название товара: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, productName);
	cheese.setName(productName);
	cout << "Введите цену товара: ";
	is >> price;
	cheese.setPrice(price);
	cout << "Введите дату поставки: ";
	is >> deliveryDate;
	cheese.setDeliveryDate(deliveryDate);
	cout << "Введите дату срока годности: ";
	is >> shelfLife;
	cheese.setShelfLife(shelfLife);
	cout << "Введите поставщика: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, manufacturer);
	cheese.setManufact(manufacturer);
	cout << "Введите % жирности товара: ";
	is >> fatContent;
	cheese.setFat(fatContent);
	cout << "Введите состав товара: " << endl;
	cout << "1 > Твердый" << endl;
	cout << "2 > Творожный" << endl;
	cout << "3 > Плавленный" << endl;
	cout << "4 > Копчёный" << endl;
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
	default: cout << "Ошибка!" << endl;
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
	cout << setiosflags(ios::fixed) // нормальный неэкспоненциальный вид
		<< setiosflags(ios::showpoint) // всегда показывать десятичную точку 
		<< setprecision(2); // два знака после запятой ;

	cout << "|" << setw(15) << "Назв. товара" << "|" << setw(8) << "Цена" << "|" << setw(14) << "Дата поставк." << "|" << setw(14)
		<< "Срок годн." << "|" << setw(14) << "Поставщик" << "|" << setw(12) << "Жирность, %" << "|" << setw(11) << "Тип" << "|";
}

void Cheese::read(Stack<Cheese>& stCheese) {

	struct Data {
		string productName; //Название продукта
		double price = 0; //Цена
		string deliveryDateStr; //Дата поставки строка
		string shelfLifeStr; //Срок годности строка
		Date deliveryDate; //Дата поставки
		Date shelfLife; //Срок годности
		string manufacturer; //Производитель
		double fatContent = 0; //Процент жирности
		string structure; //Состав
	};

	int number_of_strings = 0;
	string waste;
	ifstream file(FILE_OF_CHEESE, ios::in);

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

	Cheese* cheese = new Cheese[number_of_strings / 7];
	Data* data = new Data[number_of_strings / 7];

	ifstream fin(FILE_OF_CHEESE, ios::in);

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
		string productName; //Название продукта
		double price = 0; //Цена
		string deliveryDateStr; //Дата поставки строка
		string shelfLifeStr; //Срок годности строка
		Date deliveryDate; //Дата поставки
		Date shelfLife; //Срок годности
		string manufacturer; //Производитель
		double fatContent = 0; //Процент жирности
		string structure; //Состав
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