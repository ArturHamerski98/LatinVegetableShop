#include "User.h"

void User::setLogin()
{
	std::cout << "Enter fullname:";
	std::cin >> login;
	if (!(std::regex_match(name, std::regex("[^\s]+"))))
	{
		std::cout << "Invalid input, name should look like: Zbigniew\n";
		this->setName();
	}
}

void User::setPassword()
{
}

void User::setName()
{
	std::cout << "Enter fullname:";
	std::cin >> name;
	if (!(std::regex_match(name, std::regex("^[A-Za-z]+$"))))
	{
		std::cout << "Invalid input, name should look like: Zbigniew\n";
		this->setName();
	}
}

void User::setEmail()
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

void User::setShippingAdress()
{
	std::cout << "Enter shipping adrss:";
	std::cin >> shippingAdress;
}

void User::setBillingAdress()
{
	std::cout << "Enter billing adress:";
	std::cin >> billingAdress;
}

void User::createAccount()
{
	setLogin();
	setPassword();
	setEmail();
	setName();

}
