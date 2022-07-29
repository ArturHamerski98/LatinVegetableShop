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
}
