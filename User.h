#pragma once
#include<iostream>
#include<list>
class User
{
public:
	std::string login;
	std::string password;
	std::string name;
	std::string eMail;
	std::string shippingAdress;
	std::string billingAdress;

	void setLogin();
	void setPassword();
	void setName();
	void setEmail();
	void setShippingAdress();
	void setBillingAdress();
	void createAccount();

};