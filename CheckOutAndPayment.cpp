#pragma once
#include <regex>
#include "CheckOutAndPayment.h"
#include <fstream>
#include <string>
#include <iostream>
#include <limits>

void CheckOutAndPayment::setName()
{
	std::cout << "Enter name:";
	std::cin >> name;
	if (!(std::regex_match(name, std::regex("^[A-Za-z]+$"))))
	{
		std::cout << "Invalid input, name should look like: Zbigniew Krawczyk\n";
		this->setName();
	}
}

void CheckOutAndPayment::setEMail()
{
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << "Enter email:";
	
	std::cin >> eMail;
	if (!(std::regex_match(eMail, std::regex("^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$"))))
	{
		std::cout << "Invalid input, email should look like: xyz@gmail.com\n";
		
		this->setEMail();
	}
}

void CheckOutAndPayment::setPhoneNumber()
{
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << "Enter phone number:";
	std::cin >> phoneNumber;
	if (!(std::regex_match(phoneNumber, std::regex("^[0-9]{3}-[0-9]{3}-[0-9]{3}$"))))
	{
		std::cout << "Invalid input, phone numer should look like: 123-456-789\n";
		this->setPhoneNumber();
	}
		
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
	std::ofstream outputData("outputData.csv",std::ios::app);
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
