#include "ProductList.h"

void ProductList::quickSort(std::vector<Item>& arr, int l, int r) {
    if (l < r) {
        int pivot = l;
        int i = l;
        int j = r;
        while (i < j) {
            while (arr[i].getPrice() <= arr[pivot].getPrice() && i < r)
                i++;
            while (arr[j].getPrice() > arr[pivot].getPrice())
                j--;
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[pivot], arr[j]);
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, r);
    }
}
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

    srand(time(NULL));
    std::vector<std::string> vectorCategory{ "fresh", "short expiry date", "at your own risk" };
    for (int i = 0; i < content.size(); i++) {
        bool value;
        if (content[i][4] == "1")
            value = true;
        else
            value = false;
        Item item(stoi(content[i][0]), content[i][1], content[i][2], stod(content[i][3]), value, content[i][5], vectorCategory[rand() % 3 + 0]);
        //int ID, std::string name, std::string description, double price, bool availability, std::string supplier
        myList.push_back(item);

    }
    std::list<Item>::iterator it;
    int aaaa = 0;
    for (it = myList.begin(); it != myList.end(); it++)
    {
        // Access the object through iterator
        std::string id = it->getName();
        //std::cout << aaaa << " ";
        //std::cout << id << std::endl;
        aaaa++;
    }

   

}

std::vector<Item> ProductList::filteringSuppliers(std::string choosenSupplier)
{
    std::vector <Item> supplierVector;
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

    for(auto item = myList.begin(); item != myList.end(); item++) {
            supplierVector.push_back(*item);           
    }

    int temp2 = 0;
    quickSortbyName(supplierVector, 0, supplierVector.size() - 1);
    for (auto i : supplierVector) {
        if (i.getSupplier() == chosenSupplier)
        {
            std::cout << i.getSupplier() << " " << i.getName() << " " << i.getPrice()<<"\n";
        }
            
    }

    return supplierVector;

}
std::vector<std::string> ProductList::filteringCategory(std::string chosenCategory)
{
    std::vector <std::string> categoryVector1;

    for (auto item = myList.begin(); item != myList.end(); item++) {
        if(chosenCategory==(item->getCategory()))
            std::cout << item->getID() << "||" << item->getName() << "||" << item->getCategory() << "$||" << std::endl;
        //dodac zeby nie wyswietlala sie tylko nazwa ale tez ID||NAZWA||CENA
    }
    
    
    return categoryVector1;
}

void ProductList::quickSortbyName(std::vector<Item>& arr, int l, int r)
{
    if (l < r) {
        int pivot = l;
        int i = l;
        int j = r;
        while (i < j) {
            while (arr[i].getName() <= arr[pivot].getName() && i < r)
                i++;
            while (arr[j].getName() > arr[pivot].getName())
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

void ProductList::displayProducts()
{
    for (auto item = myList.begin(); item != myList.end(); item++) {
      
        std::cout << item->getID()<<"||" << item->getName() << "||" << item->getCategory() << "$||" << std::endl;
        //dodac zeby nie wyswietlala sie tylko nazwa ale tez ID||NAZWA||CENA
    }

}
