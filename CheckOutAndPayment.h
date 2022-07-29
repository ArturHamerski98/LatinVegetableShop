#pragma once
#include<iostream>
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
	void setName();
	void setEMail();
	void setPhoneNumber();
	void setBillingAdress();
	void setShipingAdress();
	void checkOut();
	void saveData();
	void setBoughtItems(std::string items);
	void setTotalPrice(double tp);

};

