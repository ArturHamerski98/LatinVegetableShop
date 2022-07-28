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

std::vector<std::string> ProductList::filteringSuppliers()
{
    std::vector <std::string> supplierVector;
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

   
    for (auto item = myList.begin(); item != myList.end(); item++) {
        if (item->getSupplier() == chosenSupplier)
            std::cout << item->getSupplier() << "||" << item->getName() << "||" << item->getPrice() << "\n";
            int x = 5;
    }

    //COUT SUPLIERvector
    return supplierVector;
    
}

std::vector<std::string> ProductList::filteringCategory()
{
   std::vector <std::string> categoryVector1;
   std:: string chosenCategory{};

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


    for (auto item = myList.begin(); item != myList.end(); item++) {
        if(chosenCategory ==(item->getCategory()))
            std::cout << item->getID() << "||" << item->getName() << "||" << item->getCategory() << "$||" << std::endl;
    }
    return categoryVector1;
}

void ProductList::displayProducts()
{
    for (auto item = myList.begin(); item != myList.end(); item++) {
      
        std::cout << item->getID()<<"||" << item->getName() << "||" << item->getCategory() << "$||" << std::endl;
    }

}

void askAfterFiltering() {

    std::cout << "What are you want to do now?\n";

    std::cout << "1. Add product to cart\n";
    std::cout << "2. Sorting products by name\n";
    std::cout << "3. Sorting products by price\n";
    std::cout << "4. Back to MENU\n";

    int choice{};
    std::cin >> choice; 


    switch (choice) {

    case 1: 
    case 2:
    case 3: 
    case 4: 

    }
}