#pragma once
#include<iostream>
class CheckOutAndPayment
{
	
	double price;
	std::string name;
	std::string eMail;
	std::string phoneNumber;
	std::string billingAdress;
	std::string shippingAdress;
public:
	CheckOutAndPayment(double price)
	{
		this->price = price;
		name = "";
		eMail = "";
		phoneNumber = "000000000";
		billingAdress = "";
		shippingAdress = "";
	}
	void setName();
	void setEMail();
	void setPhoneNumber();
	void setBillingAdress();
	void setShipingAdress();
	void checkOut();
};

