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
	const string var1 = "Группа В, высший сорт";
	const string var2 = "Группа А, тверд. сорт пшен.";
	int k;

	cout << "Введите название товара: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, productName);
	pasta.setName(productName);
	cout << "Введите цену товара: ";
	is >> price;
	pasta.setPrice(price);
	cout << "Введите дату поставки: ";
	is >> deliveryDate;
	pasta.setDeliveryDate(deliveryDate);
	cout << "Введите дату срока годности: ";
	is >> shelfLife;
	pasta.setShelfLife(shelfLife);
	cout << "Введите поставщика: ";
	if (cin.peek() == '\n')
		cin.ignore();
	getline(is, manufacturer);
	pasta.setManufact(manufacturer);
	cout << "Введите вес товара: ";
	is >> weight;
	pasta.setWeight(weight);
	cout << "Введите начинку товара: " << endl;
	cout << "1 > Группа В, высший сорт" << endl;
	cout << "2 > Группа А, тверд. сорт пшен." << endl;
	cout << "> ";
	cin >> k;
	switch (k)
	{
	case 1:pasta.setVariety(var1);
		break;
	case 2:pasta.setVariety(var2);
		break;
	default: cout << "Ошибка!" << endl;
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
	cout << setiosflags(ios::fixed) // нормальный неэкспоненциальный вид
		<< setiosflags(ios::showpoint) // всегда показывать десятичную точку 
		<< setprecision(2); // два знака после запятой ;

	cout << "|" << setw(19) << "Назв. товара" << "|" << setw(8) << "Цена" << "|" << setw(14) << "Дата поставк." << "|" << setw(14)
		<< "Срок годн." << "|" << setw(15) << "Поставщик" << "|" << setw(8) << "Вес, г" << "|" << setw(28) << "Сорт" << "|";
}

void Pasta::read(Stack<Pasta>& stPasta) {
	struct Data {
		string productName; //Название продукта
		double price = 0; //Цена
		string deliveryDateStr; //Дата поставки строка
		string shelfLifeStr; //Срок годности строка
		Date deliveryDate; //Дата поставки
		Date shelfLife; //Срок годности
		string manufacturer; //Производитель
		double weight = 0; //Вес
		string variety; //Сорт
	};

	int number_of_strings = 0;
	string waste;
	ifstream file(FILE_OF_PASTA, ios::in);

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

	Pasta* pasta = new Pasta[number_of_strings / 7];
	Data* data = new Data[number_of_strings / 7];

	ifstream fin(FILE_OF_PASTA, ios::in);

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
		string productName; //Название продукта
		double price = 0; //Цена
		string deliveryDateStr; //Дата поставки строка
		string shelfLifeStr; //Срок годности строка
		Date deliveryDate; //Дата поставки
		Date shelfLife; //Срок годности
		string manufacturer; //Производитель
		double weight = 0; //Вес
		string variety; //Сорт
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