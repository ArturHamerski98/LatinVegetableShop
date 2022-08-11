#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <regex>
#include "CheckOutAndPayment.h"
#include <fstream>
#include <string>
#include <iostream>
#include <limits>
#include <ostream>
#include<fstream>
#include <ctime>
#include "User.h"
#include "Menu.h"

void CheckOutAndPayment::setName()
{
	//if(Menu::Isloged > 0) czy mzna zrobic Isloged static tak zeby nie bylo obiektu a kalsy ?? 
	std::cout << "Enter name:";
	std::cin >> name;
	if (!(std::regex_match(name, std::regex("^[A-Za-z]+$"))))
	{
		std::cout << "Invalid input, name should look like: Zbigniew\n";
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
	choosePayment();
	orderConfirmation();
}

void CheckOutAndPayment::saveData()
{
	std::ofstream outputData("outputData.csv", std::ios::app);
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
std::string CheckOutAndPayment::GetName()
{
	return CheckOutAndPayment::name;
}
void CheckOutAndPayment::orderConfirmation() {
	std::string plik = ".\\orderfile\\";
	plik += name + ".csv";
	std::ofstream zapis(plik);
	time_t now = time(0);
	tm* ltm = localtime(&now);
	zapis << GetName() << ";" << "Total price: " << totalPrice << "; Bought items: " << boughtItems << "; Data: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << std::endl;
	zapis.close();
}

void CheckOutAndPayment::choosePayment() {

	int payment, cardNumber, csv, exp, blik;

	std::cout << "Choose method of payment: \n";
	std::cout << "1. Credit card\n";
	std::cout << "2. Blik\n";

	std::cin >> payment;

	switch (payment) {

	case 1:
		CreditCardNumber();
		CSVNumber();
		ExpirationDate();
		break;
	case 2:
		BlikNumberrr();
		break;
	}
}

void CheckOutAndPayment::CreditCardNumber()
{
	std::string GivenCardNumber;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << " Credit Card Number:";
	std::cin >> GivenCardNumber;
	if (!(std::regex_match(GivenCardNumber, std::regex("^[0-9]{12}$"))))
	{
		std::cout << "Invalid input, Credit Card Number have 12 digit \n";
		this->CreditCardNumber();
	}
}

void CheckOutAndPayment::CSVNumber()
{
	std::string CSVNumber;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << " CSV Number:";
	std::cin >> CSVNumber;
	if (!(std::regex_match(CSVNumber, std::regex("^[0-9]{4}$"))))
	{
		std::cout << "Invalid input, CSV Number have 4 digit \n";
		this->CSVNumber();
	}
}

void CheckOutAndPayment::ExpirationDate()
{
	std::string ExpirationDateNumber;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << " Expiration Date:";
	std::cin >> ExpirationDateNumber;
	if (!(std::regex_match(ExpirationDateNumber, std::regex("^[0-9]{2}/[0-9]{2}$"))))
	{
		std::cout << "Invalid input, Expiration Date should look like: 08/18 \n";
		this->ExpirationDate();
	}
}

void CheckOutAndPayment::BlikNumberrr()
{
	std::string BlikNumber;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << " Blik Number:";
	std::cin >> BlikNumber;
	if (!(std::regex_match(BlikNumber, std::regex("^[0-9]{6}$"))))
	{
		std::cout << "Invalid input, Blik Number should look like: 083518 \n";
		this->BlikNumberrr();
	}
}