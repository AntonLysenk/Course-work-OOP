#include "main.h"

void Date::setDays(int d) //Конструктор по умолчанию
{
	days = d;
}

int Date::getDays()
{
	return days;
}

void Date::setMonths(int m) {
	months = m;
}

int Date::getMonths() {
	return months;
}

void Date::setYears(int y) {
	years = y;
}

int Date::getYears() {
	return years;
}

bool operator< (const Date& date1, const Date& date2) {
	if (date2.years > date1.years) {
		return true;
	}
	else if (date2.months > date1.months) {
		return true;
	}
	else if (date2.days > date1.days) {
		return true;
	}
	else {
		return false;
	}
}

bool operator> (const Date& date1, const Date& date2) {
	if (date2.years < date1.years) {
		return true;
	}
	else if (date2.months < date1.months) {
		return true;
	}
	else if (date2.days < date1.days) {
		return true;
	}
	else {
		return false;
	}
}

bool operator== (const Date& date1, const Date& date2) {
	if ((date1.days == date2.days) && (date1.months == date2.months) && (date1.years == date2.years))
		return true;
	else
		return false;
}

Date& Date::operator= (string buf) {
	days += (buf[0] - 48) * 10;
	days += buf[1] - 48;
	months += (buf[3] - 48) * 10;
	months += buf[4] - 48;
	years += (buf[6] - 48) * 1000;
	years += (buf[7] - 48) * 100;
	years += (buf[8] - 48) * 10;
	years += buf[9] - 48;
	return *this;
}

Date& Date::operator= (const Date& date) {
	days = date.days;
	months = date.months;
	years = date.years;
	return *this;
}

 istream& operator>>(istream& is, Date& date) {
	string buf;
	is >> buf;
	date.days += (buf[0] - 48) * 10;
	date.days += buf[1] - 48;
	date.months += (buf[3] - 48) * 10;
	date.months += buf[4] - 48;
	date.years += (buf[6] - 48) * 1000;
	date.years += (buf[7] - 48) * 100;
	date.years += (buf[8] - 48) * 10;
	date.years += buf[9] - 48;
	return is;

}

ostream& operator<<(ostream& os, Date& date) {
	os << date.days << setw(1) << "." << setw(2) << date.months << setw(1) << "." << setw(4) << date.years;
	return os;
}