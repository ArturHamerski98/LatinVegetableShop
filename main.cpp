#include <iostream>
#include "Item.h"
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::list<Item> myList;
    /*
    Item lodowka("Media Expert", "Lodowka1", "Super lodowka", 50, 340.00);
    Item odkurzacz("Media Expert", "Lodowka2", "Super lodowka", 50, 1300.00);
    Item Suszarka("Media Expert", "Lodowka3", "Super lodowka", 50, 1000.00);
    Item TV("Media Expert", "Lodowka4", "Super lodowka", 50, 1000.00);
    myList.push_back(lodowka);
    myList.push_back(odkurzacz);
    myList.push_back(Suszarka);
    myList.push_back(TV);*/
    //std::list<Item>::iterator it;
    //for (it = myList.begin(); it != myList.end(); it++)
    //{
    //    // Access the object through iterator
    //    int id = it->getPrice();
    //   
    //    std::cout << id << std::endl;
    //}


    std::vector < std::vector < std::string >> content;
    std::vector < std::string > row;
    std::string line, word;
    std::fstream file("items.csv", std::ios::in);
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
        //int a = stoi(content[i][3]);
        //double b = stod(content[i][4]);
        //Item item(content[i][0], content[i][1], content[i][2], stoi(content[i][3]), stod(content[i][4]));
        //myList.push_back(item);
        /*std::cout << content[i][0] << std::endl;
        std::cout << content[i][1] << std::endl;
        std::cout << content[i][2] << std::endl;
        std::cout << content[i][3] << std::endl;
        std::cout << content[i][4] << std::endl;
        std::cout << content[i][5] << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;*/
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
        std::string id = it->getName();
        std::cout << aaaa << " ";
        std::cout << id << std::endl;
        aaaa++;
    }
    
    return 0;
}