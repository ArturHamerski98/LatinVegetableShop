#include "ProductList.h"

int ProductList::ranndomCategory() {

    // srand(time(NULL));

    return static_cast<int>(rand() % 2 + 0);
}

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

        std::vector<std::string> vectorCategory{ "fresh", "short expiry date", "at your own risk" };
        std::string category = vectorCategory[ranndomCategory()];

        Item item(stoi(content[i][0]), content[i][1], content[i][2], stod(content[i][3]), value, content[i][5],category);
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

void ProductList::filteringSuppliers(std::string choosenSupplier)
{
    std::vector <std::string> supplierVector;

    for (auto item = myList.begin(); item != myList.end(); item++) {
        if (item->getSupplier() == choosenSupplier)
            std::cout << item->getSupplier() << "||" << item->getName() << "||" << item->getPrice() << "\n";
            int x = 5;
    } 
}

void ProductList::displayProducts()
{
    for (auto name = myList.begin(); name != myList.end(); name++) {
       // std::string id = name->getName();
       
        //std::cout << id << std::endl;
        std::cout << name->getName() << "||" << name->getPrice() << "||" << name->getID();
        //std::cout <<  << std::endl;
    }
}

void  ProductList::filteringCategory(std::string choosenCategory) {

    std::vector <std::string> categoryVector1;

    for (auto item = myList.begin(); item != myList.end(); item++) {
        if (item->getCategory() == choosenCategory)
            std::cout << item->getCategory() << "||" << item->getName() << "||" << item->getPrice() << "\n";
        int x = 5;
    }
}


/*void ProductList::sortingByName(int arr[], int l, int r) {

        if (l < r) {
            int pivot = l;
            int i = l;
            int j = r;
            while (i < j) {
                while (arr[i] <= arr[pivot] && i < r)
                    i++;
                while (arr[j] > arr[pivot])
                    j--;
                if (i < j) {
                   swap(&arr[i], &arr[j]);
                }
            }
            swap(&arr[pivot], &arr[j]);
            sortingByName(arr, l, j - 1);
            sortingByName(arr, j + 1, r);
        }
 }*/
