#pragma once
#include "CheckOutAndPayment.h"



void CheckOutAndPayment::setName()
{
	std::cout << "Enter name:";
	std::cin >> name;
}

void CheckOutAndPayment::setEMail()
{
	std::cout << "Enter email:";
	std::cin >> eMail;
}

void CheckOutAndPayment::setPhoneNumber()
{
	std::cout << "Enter phone number:";
	std::cin >> phoneNumber;
}

void CheckOutAndPayment::setBillingAdress()
{
	std::cout << "Enter billing adress:";
	std::cin >> billingAdress;
}

void CheckOutAndPayment::setShipingAdress()
{
	std::cout << "Enter shipping adrss:";
	std::cin >> shippingAdress;
}

void CheckOutAndPayment::checkOut()
{
	setName();
	setEMail();
	setPhoneNumber();
	setBillingAdress();
	setShipingAdress();
	saveData();
}

void CheckOutAndPayment::saveData()
{
	std::ofstream outputData("outputData.csv");
	outputData << name << ";" << totalPrice << ";" << boughtItems << "\n"; 
	outputData.close();
}

void CheckOutAndPayment::setBoughtItems(std::string items)
{
	boughtItems = items;
}

void CheckOutAndPayment::setTotalPrice(double tp)
{
	totalPrice = tp;
}

void CheckOutAndPayment::orderConfirmation() {
	std::string fileName;
	std::cout << "give file name ";
	std::cin >> fileName;
	fileName += ".csv";
	ofstream zapis(fileName);

	zapis << a << " + " << b << " = " << a + b;

	zapis.close();
	
}
