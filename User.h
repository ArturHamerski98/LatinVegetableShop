#pragma once
#include<iostream>
#include<list>
#include<vector>
#include <limits>
class User
{
public:
	std::string login;
	std::string password;
	std::string name;
	std::string eMail;
	std::string shippingAdress;
	std::string billingAdress;
	bool isAdmin;
	int Isloged = -1;
	std::vector < std::vector < std::string >> allUsers;
	void setLogin();
	void setPassword();
	void setName();
	void setEmail();
	void setShippingAdress();
	void setBillingAdress();
	void createAccount();
	void saveAccpuntData();

	void LogIn();
};