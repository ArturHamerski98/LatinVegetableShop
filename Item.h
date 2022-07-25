#pragma once
#include<iostream>
#include<list>
class Item
{
    int ID;
    std::string supplier;
    std::string name;
    std::string description;
    int weight;
    double price;
    struct productCart {
        std::string name;
        std::string description;
        int weight;
        double price;
    };
    productCart prodCart;
public:
    Item(std::string supplier, std::string name, std::string description, int weight, double price);
    int getID();
    std::string getSupplier();
    std::string getName();
    std::string getDescription();
    int getWeight();
    double getPrice();
};