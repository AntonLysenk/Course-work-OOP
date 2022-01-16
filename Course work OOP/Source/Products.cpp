#include "products.h"

void Products::setName(string name) 
{ 
	productName = name; 
}
string Products::getName() 
{ 
	return productName; 
}
void Products::setPrice(double pri) 
{ 
	price = pri; 
}
double Products::getPrice() 
{ 
	return price; 
}
void Products::setDeliveryDate(Date date)
{ 
	deliveryDate = date; 
}
Date Products::getDeliveryDate()
{ 
	return deliveryDate; 
}
void Products::setShelfLife(Date date)
{
	shelfLife = date;
}
Date Products::getShelfLife()
{
	return shelfLife;
}
void Products::setManufact(string manufact) 
{ 
	manufacturer = manufact; 
}
string Products::getManufact() 
{ 
	return manufacturer; 
}

//void Products::print()
//{
//
//}
