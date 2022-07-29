#include "ProductList.h"

void ProductList::quickSort(std::vector<double>& arr, double l, double r) {
    if (l < r) {
        double pivot = l;
        double i = l;
        double j = r;
        while (i < j) {
            while (arr[i] <= arr[pivot] && i < r)
                i++;
            while (arr[j] > arr[pivot])
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

std::vector<Item> ProductList::filteringSuppliers(std::string chosenSupplier)
{
    std::vector <Item> supplierVector;
    std::vector<double> supplierPrices;
    for (auto i : myList) {
        supplierPrices.push_back(i.getPrice());
    }
    double n = supplierPrices.size() - 1;
    quickSort(supplierPrices, 0, n);
    int i = 0;
    for (auto item = myList.begin(); item != myList.end(); item++) {
        
        if (item->getSupplier() == chosenSupplier)
            std::cout << item->getSupplier() << "||" << item->getName() << "||" << supplierPrices[i] << "\n";
        i++;
    }

    //COUT SUPLIERvector
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

void ProductList::displayProducts()
{
    for (auto item = myList.begin(); item != myList.end(); item++) {
      
        std::cout << item->getID()<<"||" << item->getName() << "||" << item->getCategory() << "$||" << std::endl;
        //dodac zeby nie wyswietlala sie tylko nazwa ale tez ID||NAZWA||CENA
    }

}
