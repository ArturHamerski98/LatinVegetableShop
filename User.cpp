#include "User.h"
#include <regex>
#include<fstream>
#include <ostream>
#include <iostream>
#include <limits>
#include <sstream>
#include <conio.h>

void User::setLogin()
{
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << "Enter login ";
	std::cin >> login; // do zrobienia validacja spacji 
	if (!(std::regex_match(login, std::regex("^[a-zA-Z0-9_ ]*$"))))
	{
		std::cout << "Invalid input, login login cannot have spaces\n";
		this->setLogin();
	}
	else {
		std::vector < std::vector < std::string >> content;
		std::vector < std::string > row;
		std::string line, word;
		std::fstream file(".\\user\\Users.csv", std::ios::in);
		if (file.is_open()) {
			while (getline(file, line)) {
				row.clear();
				std::stringstream str(line);
				while (getline(str, word, ','))
					row.push_back(word);
				content.push_back(row);
			}
			file.close();
		}
		else
			std::cout << "Could not open the file\n";

		//std::cout << "cout loginu " << login << std::endl;
		for (int i = 0; i < content.size(); i++)
		{
			//std::cout << content[i][0] << std::endl;		
			if (content[i][0] == login)
			{
				std::cout << "this login is already taken\n";
				this->setLogin();
			}
		}
	}
}

void User::setPassword()
{
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << "Create password:";
	std::cin >> password;

	if (!(std::regex_match(password, std::regex("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$"))))
	{
		std::cout << "Your password must contain minimum eight characters, at least one uppercase letter, one lowercase letter, one number and one special character\n";
		this->setPassword();
	}
}

void User::setName()
{
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
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

		this->setEmail();
	}
}

void User::setShippingAdress()
{
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << "Enter shipping adrss:";
	std::cin >> shippingAdress;
}

void User::setBillingAdress()
{
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	std::cout << "Enter billing adress:";
	std::cin >> billingAdress;
}
void User::saveAccpuntData()
{
	std::string plik = ".\\user\\Users.csv";
	std::ofstream UserData(plik, std::ios::app);
	UserData << this->login << "," << this->password << "," << this->eMail << "," << this->name << "," << this->billingAdress << "," << this->shippingAdress << this->isAdmin << "\n";
	UserData.close();
}

void User::LogIn()
{
	while (true)
	{
		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		std::cout << "login:";
		std::cin >> login;
		if (!(std::regex_match(login, std::regex("^[A-Za-z]+$"))))
		{
			std::cout << "Invalid input, name should look like: Zbigniew\n";

		}
		else {

			std::cout << "Enter password:";
			std::cin >> password;
			std::vector < std::vector < std::string >> content;
			std::vector < std::string > row;
			std::string line, word;
			std::fstream file(".\\user\\Users.csv", std::ios::in);
			if (file.is_open()) {
				while (getline(file, line)) {
					row.clear();
					std::stringstream str(line);
					while (getline(str, word, ','))
						row.push_back(word);
					content.push_back(row);
				}
				file.close();
			}
			else
				std::cout << "Could not open the file\n";

			bool correctlogin;
			for (int i = 0; i < content.size(); i++) {
				if (content[i][1] == password && content[i][0] == login)
				{
					correctlogin = true;
					Isloged = i;
					std::cout << "welcom " << content[i][0] << std::endl;
					eMail = content[i][3];
					name = content[i][3];
					shippingAdress = content[i][4];
					billingAdress = content[i][5];
					if (content[i][6] == "1")
						isAdmin = true;
					break;
				}

			}
			if (correctlogin == true) return;
			std::cout << "invalid data try again" << std::endl;
			this->LogIn();// Rekurencyjnie wczytujemy plik jakies lepsze rozwiazanie ??
		}
	}
	
}
void User::createAccount()
{
	setLogin();

	setPassword();
	setEmail();
	setName();
	setBillingAdress();
	setShippingAdress();
	saveAccpuntData();
}


