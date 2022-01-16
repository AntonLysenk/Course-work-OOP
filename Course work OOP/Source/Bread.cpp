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
	const string str1 = "Пшеничный";
	const string str2 = "Ржаной";
	const string str3 = "Ржано-пшеничный";
	const string str4 = "С семечками";
	int k;

	cout << "Введите название товара: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, productName);
	bread.setName(productName);
	cout << "Введите цену товара: ";
	is >> price;
	bread.setPrice(price);
	cout << "Введите дату поставки: ";
	is >> deliveryDate;
	bread.setDeliveryDate(deliveryDate);
	cout << "Введите дату срока годности: ";
	is >> shelfLife;
	bread.setShelfLife(shelfLife);
	cout << "Введите поставщика: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, manufacturer);
	bread.setManufact(manufacturer);
	cout << "Введите вес товара: ";
	is >> weight;
	bread.setWeight(weight);
	cout << "Введите состав товара: " << endl;
	cout << "1 > Пшеничный" << endl;
	cout << "2 > Ржаной" << endl;
	cout << "3 > Ржано-пшеничный" << endl;
	cout << "4 > С семечками" << endl;
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
	default: cout << "Ошибка!" << endl;
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
	cout << setiosflags(ios::fixed) // нормальный неэкспоненциальный вид
		<< setiosflags(ios::showpoint) // всегда показывать десятичную точку 
		<< setprecision(2); // два знака после запятой ;

	cout << "|" << setw(17) << "Назв. товара" << "|" << setw(8) << "Цена" << "|" << setw(14) << "Дата поставк." << "|" << setw(14)
		<< "Срок годн." << "|" << setw(14) << "Поставщик" << "|" << setw(8) << "Вес, г" << "|" << setw(16) << "Состав" << "|";
}


void Bread::read(Stack<Bread>& stBread) {

	struct Data {
		string productName; //Название продукта
		double price = 0; //Цена
		string deliveryDateStr; //Дата поставки строка
		string shelfLifeStr; //Срок годности строка
		Date deliveryDate; //Дата поставки
		Date shelfLife; //Срок годности
		string manufacturer; //Производитель
		double weight = 0; //Вес
		string structure; //Состав
	};

	int number_of_strings = 0;
	string waste;
	ifstream file(FILE_OF_BREAD, ios::in);

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

	Bread* breads = new Bread[number_of_strings / 7];
	Data* data = new Data[number_of_strings / 7];

	ifstream fin(FILE_OF_BREAD, ios::in);

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
		string productName; //Название продукта
		double price = 0; //Цена
		string deliveryDateStr; //Дата поставки строка
		string shelfLifeStr; //Срок годности строка
		Date deliveryDate; //Дата поставки
		Date shelfLife; //Срок годности
		string manufacturer; //Производитель
		double weight = 0; //Вес
		string structure; //Состав
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