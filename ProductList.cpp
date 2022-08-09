#pragma once
#include "ProductList.h"


void ProductList::readingDataFromCSVFile()
{
    std::vector < std::vector < std::string >> content;
    std::vector < std::string > row;
    std::string line, word;
    std::fstream file("Items.csv", std::ios::in);
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

    srand(time(NULL));
    std::vector<std::string> vectorCategory{ "fresh", "short expiry date", "at your own risk" };
    //std::vector<std::string> vectorCategory{ "1", "2", "3" };
    for (int i = 0; i < content.size(); i++) {
        bool value;
        if (content[i][4] == "1")
            value = true;
        else
            value = false;
        Item *item = new Item(stoi(content[i][0]), content[i][1], content[i][2], stod(content[i][3]), value, content[i][5], vectorCategory[rand() % 3 + 0], rand() % 10 + 1);
        //int ID, std::string name, std::string description, double price, bool availability, std::string supplier
        vectorofAll.push_back(item);
       
    }
}

std::vector<Item*> ProductList::filteringSuppliers(std::vector<Item*>& arr)
{
    std::vector <Item*> supplierVector;
    std::string chosenSupplier{};

    while (chosenSupplier != "1" && chosenSupplier != "2" && chosenSupplier != "3") {
        std::cout << "Type number to choose supplier to filter:\n";
        std::cout << "1. Spain \n";
        std::cout << "2. Poland\n";
        std::cout << "3. France\n";

        std::cin >> chosenSupplier;
    }

    if (chosenSupplier == "1")
        chosenSupplier = "Spain";

    if (chosenSupplier == "2")
        chosenSupplier = "Poland";

    if (chosenSupplier == "3")
        chosenSupplier = "France";
    
    int temp2 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]->getSupplier() == chosenSupplier)
        {
            std::cout << temp2 << " " << arr[i]->getSupplier() << "||" << arr[i]->getName() << "||" << arr[i]->getPrice() << "\n";
            supplierVector.push_back(arr[i]);
            temp2++;
        }

    }
   

    return supplierVector;

}

std::vector<Item*> ProductList::filteringCategory(std::vector<Item*>& arr)
{
    std::vector <Item*> categoryVector1;
    std::string chosenCategory{};

    while (chosenCategory != "1" && chosenCategory != "2" && chosenCategory != "3") {

        std::cout << "Type number to choose category to filter:\n";
        std::cout << "1. Fresh\n";
        std::cout << "2. Short expiry date\n";
        std::cout << "3. At your own risk \n";

        std::cin >> chosenCategory;
    }

    if (chosenCategory == "1")
        chosenCategory = "fresh";

    if (chosenCategory == "2")
        chosenCategory = "short expiry date";

    if (chosenCategory == "3")
        chosenCategory = "at your own risk";

    int temp = 0;


  
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]->getSupplier() == chosenCategory)
        {
            std::cout << temp << " " << arr[i]->getSupplier() << "||" << arr[i]->getName() << "||" << arr[i]->getPrice() << "\n";
            categoryVector1.push_back(arr[i]);
            temp++;
        }

    }

    return categoryVector1;
}

void ProductList::displayProducts(std::vector<Item*>& arr)
{
    for(int i =0;i<arr.size();i++)
        std::cout << arr[i]->getID() - 1 << "||" << arr[i]->getName() << "||" << arr[i]->getPrice() << "$||" << arr[i]->getQuantity() << std::endl;

}

void ProductList::quickSortbyName(std::vector<Item*>&arr, int l, int r)
{
    if (l < r) {
        int pivot = l;
        int i = l;
        int j = r;
        while (i < j) {
            while (arr[i]->getName() <= arr[pivot]->getName() && i < r)
                i++;
            while (arr[j]->getName() > arr[pivot]->getName())
                j--;
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[pivot], arr[j]);
        quickSortbyName(arr, l, j - 1);
        quickSortbyName(arr, j + 1, r);
    }

}

void ProductList::quickSortbyPrice(std::vector<Item*>& arr, int l, int r)
{
    if (l < r) {
        int pivot = l;
        int i = l;
        int j = r;
        while (i < j) {
            while (arr[i]->getPrice() <= arr[pivot]->getPrice() && i < r)
                i++;
            while (arr[j]->getPrice() > arr[pivot]->getPrice())
                j--;
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[pivot], arr[j]);
        quickSortbyPrice(arr, l, j - 1);
        quickSortbyPrice(arr, j + 1, r);
    }
}