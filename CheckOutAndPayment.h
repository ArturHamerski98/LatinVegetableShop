#pragma once
#include<iostream>
#include<fstream>
#include "Cart.h"
class CheckOutAndPayment
{

	double totalPrice;
	std::string name;
	std::string eMail;
	std::string phoneNumber;
	std::string billingAdress;
	std::string shippingAdress;
	std::string boughtItems;
	
public:
	CheckOutAndPayment()
	{
		name = "";
		eMail = "";
		phoneNumber = "000000000";
		billingAdress = "";
		shippingAdress = "";
	}
	void orderConfirmation();
	void setName();
	void setEMail();
	void setPhoneNumber();
	void setBillingAdress();
	void setShipingAdress();
	void checkOut();
	void saveData();
	void setBoughtItems(std::string items);
	void setTotalPrice(double tp);
	std::string GetName();
	void choosePayment();
	void CreditCardNumber();
	void CSVNumber();
	void ExpirationDate();
	void BlikNumberrr();

};

