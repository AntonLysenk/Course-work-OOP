#include "main.h"
#include <iomanip>
#include <cstring>

void Milk::setType(string tp) {
	type = tp;
}

string Milk::getType() {
	return type;
}

istream& operator>>(istream& is, Milk& milk) {

	string productName;
	double price;
	Date deliveryDate;
	Date shelfLife;
	string manufacturer;
	double fatContent;
	const string type1 = "Безлактозное";
	const string type2 = "Пастеризованное";
	const string type3 = "Стерилизованное";
	const string type4 = "Ультрапастеризованное";
	int k;

	cout << "Введите название товара: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, productName);
	milk.setName(productName);
	cout << "Введите цену товара: ";
	is >> price;
	milk.setPrice(price);
	cout << "Введите дату поставки: ";
	is >> deliveryDate;
	milk.setDeliveryDate(deliveryDate);
	cout << "Введите дату срока годности: ";
	is >> shelfLife;
	milk.setShelfLife(shelfLife);
	cout << "Введите поставщика: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, manufacturer);
	milk.setManufact(manufacturer);
	cout << "Введите % жирности товара: ";
	is >> fatContent;
	milk.setFat(fatContent);
	cout << "Введите тип товара: " << endl;
	cout << "1 > Безлактозное" << endl;
	cout << "2 > Пастеризованное" << endl;
	cout << "3 > Стерилизованное" << endl;
	cout << "4 > Ультрапастеризованное" << endl;
	cout << "> ";
	cin >> k;
	switch (k)
	{
	case 1:milk.setType(type1);
		break;
	case 2:milk.setType(type2);
		break;
	case 3:milk.setType(type3);
		break;
	case 4:milk.setType(type4);
		break;
	default: cout << "Ошибка!" << endl;
		break;
	}
	return is;
}

ostream& operator<<(ostream& os, Milk& milk) {
	Date delivDate = milk.getDeliveryDate();
	Date shelfLife = milk.getShelfLife();
	os << "|" << setw(17) << milk.getName() << "|" << setw(8) << milk.getPrice() << "|" << setw(6) << delivDate << "|"
		<< setw(6) << shelfLife << "|" << setw(17) << milk.getManufact() << "|" << setw(12) << milk.getFat() << "|"
		<< setw(22) << milk.getType() << "|";
	return os;
}

void Milk::print() {

	cout << setiosflags(ios::fixed) // нормальный неэкспоненциальный вид
		<< setiosflags(ios::showpoint) // всегда показывать десятичную точку 
		<< setprecision(2); // два знака после запятой ;

	cout << "|" << setw(17) << "Назв. товара" << "|" << setw(8) << "Цена" << "|" << setw(14) << "Дата поставк." << "|" << setw(14) 
		<< "Срок годн." << "|" << setw(17) << "Поставщик" << "|" << setw(12) << "Жирность, %" << "|" << setw(22) << "Тип" << "|";
}

//Чтение данных о молоке из файла
void Milk::read(Stack<Milk>& stMilk) {

	struct Data {
		string productName; //Название продукта
		double price = 0; //Цена
		string deliveryDateStr; //Дата поставки строка
		string shelfLifeStr; //Срок годности строка
		Date deliveryDate; //Дата поставки
		Date shelfLife; //Срок годности
		string manufacturer; //Производитель
		double fatContent = 0; //Процент жирности
		string type; //Тип
	};

	int number_of_strings = 0;
	string waste;
	ifstream file(FILE_OF_MILK, ios::in);

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

	Milk* milks = new Milk[number_of_strings / 7];
	Data* data = new Data[number_of_strings / 7];

	ifstream fin(FILE_OF_MILK, ios::in);

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
			getline(fin, data[i].type, '\n');
		}
	}

	for (int i = 0; i < number_of_strings / 7; i++) {
		milks[i].setName(data[i].productName);
		milks[i].setPrice(data[i].price);
		data[i].deliveryDate = data[i].deliveryDateStr;
		milks[i].setDeliveryDate(data[i].deliveryDate);
		data[i].shelfLife = data[i].shelfLifeStr;
		milks[i].setShelfLife(data[i].shelfLife);
		milks[i].setManufact(data[i].manufacturer);
		milks[i].setFat(data[i].fatContent);
		milks[i].setType(data[i].type);
		stMilk.push(milks[i]);
	}

	fin.close();
}

//Запись данных о молоке в файл
void Milk::write(Stack<Milk>& stMilk) {

	struct Data {
		string productName; //Название продукта
		double price = 0; //Цена
		string deliveryDateStr; //Дата поставки строка
		string shelfLifeStr; //Срок годности строка
		Date deliveryDate; //Дата поставки
		Date shelfLife; //Срок годности
		string manufacturer; //Производитель
		double fatContent = 0; //Процент жирности
		string type; //Тип
	};

	int count = 0;
	count = stMilk.getCount();

	Milk* milks = new Milk[count];
	Data* data = new Data[count];

	for (int i = 0; i < count; i++) {
		milks[i] = stMilk.top(stMilk.getTmp());
		stMilk.next();
		data[i].productName = milks[i].getName();
		data[i].price = milks[i].getPrice();
		data[i].deliveryDate = milks[i].getDeliveryDate();
		data[i].shelfLife = milks[i].getShelfLife();
		data[i].manufacturer = milks[i].getManufact();
		data[i].fatContent = milks[i].getFat();
		data[i].type = milks[i].getType();
	}

	ofstream fout(FILE_OF_MILK, ios::out);

	for (int i = 0; i < count; i++) {
		fout << data[i].productName << '\n' << data[i].price << '\n' << data[i].deliveryDate << '\n' << data[i].shelfLife
			<< '\n' << data[i].manufacturer << '\n' << data[i].fatContent << '\n' << data[i].type << '\n';
	}

	fout.close();
}