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
	const string str1 = "Пшеничная";
	const string str2 = "Рисовая";
	const string str3 = "Овсяная";
	const string str4 = "Цельнозерновая";
	int k;

	cout << "Введите название товара: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, productName);
	flour.setName(productName);
	cout << "Введите цену товара: ";
	is >> price;
	flour.setPrice(price);
	cout << "Введите дату поставки: ";
	is >> deliveryDate;
	flour.setDeliveryDate(deliveryDate);
	cout << "Введите дату срока годности: ";
	is >> shelfLife;
	flour.setShelfLife(shelfLife);
	cout << "Введите поставщика: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, manufacturer);
	flour.setManufact(manufacturer);
	cout << "Введите вес товара: ";
	is >> weight;
	flour.setWeight(weight);
	cout << "Введите начинку товара: " << endl;
	cout << "1 > Пшеничная" << endl;
	cout << "2 > Рисовая" << endl;
	cout << "3 > Овсяная" << endl;
	cout << "4 > Цельнозерновая" << endl;
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
	default: cout << "Ошибка!" << endl;
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
	cout << setiosflags(ios::fixed) // нормальный неэкспоненциальный вид
		<< setiosflags(ios::showpoint) // всегда показывать десятичную точку 
		<< setprecision(2); // два знака после запятой ;

	cout << "|" << setw(13) << "Назв. товара" << "|" << setw(8) << "Цена" << "|" << setw(14) << "Дата поставк." << "|" << setw(14)
		<< "Срок годн." << "|" << setw(13) << "Поставщик" << "|" << setw(8) << "Вес, г" << "|" << setw(15) << "Состав" << "|";
}

void Flour::read(Stack<Flour>& stFlour) {
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
	ifstream file(FILE_OF_FLOUR, ios::in);

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

	Flour* flours = new Flour[number_of_strings / 7];
	Data* data = new Data[number_of_strings / 7];

	ifstream fin(FILE_OF_FLOUR, ios::in);

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