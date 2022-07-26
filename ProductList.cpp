#include "ProductList.h"
#include <algorithm>

std::vector<Item> ProductList::sortingByPrice(std::list<Item> myList2)
{
    return std::vector<Item>();
}

void ProductList::readingDataFromCSVFile()
{
    std::cout << "xddd";
    std::cout << content.size();
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
        std::cout << content.size();
    }
    else
        std::cout << "Could not open the file\n";

    for (int i = 0; i < content.size(); i++) {
        bool value;
        if (content[i][4] == "1")
            value = true;
        else
            value = false;
        Item item(stoi(content[i][0]), content[i][1], content[i][2], stod(content[i][3]), value, content[i][5]);
        //int ID, std::string name, std::string description, double price, bool availability, std::string supplier
        myList.push_back(item);
       
    }
    std::list<Item>::iterator it;
    int aaaa = 0;
    for (it = myList.begin(); it != myList.end(); it++)
    {
        // Access the object through iterator
        std::cout << "xddd";
        std::string id = it->getName();
        std::cout << aaaa << " ";
        std::cout << id << std::endl;
        aaaa++;
    }
}
