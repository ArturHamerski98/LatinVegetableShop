#include "ProductList.h"
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>

void ProductList::readingDataFromCSVFile()
{
    std::vector < std::vector < std::string >> content;
    std::vector < std::string > row;
    std::string line, word;
    std::fstream file("C:\\Users\\xgrj78\\source\\repos\\ArturHamerski98\\LatinVegetableShop\\Items.csv", std::ios::in);
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

    for (int i = 0; i < content.size(); i++) {
        bool availability;
        if (content[i][4] == "1")
            availability = true;
        else
            availability = false;
        Item item(stoi(content[i][0]), content[i][1], content[i][2], stod(content[i][3]), availability, content[i][5]);
        myList.push_back(item);
    }
}

std::vector<std::string> ProductList::filteringSuppliers(std::string choosenSupplier)
{
    std::vector <std::string> supplierVector;



    for (auto item = myList.begin(); item != myList.end(); item++) {
        if (item->getSupplier() == choosenSupplier)
            std::cout << item->getSupplier() << "||" << item->getName() << "||" << item->getPrice() << "\n";
        int x = 5;
    }
    return supplierVector;

}

void ProductList::displayProducts()
{
    for (auto name = myList.begin(); name != myList.end(); name++) {
        std::string id = name->getName();
        //std::cout << id << std::endl;
    }

}