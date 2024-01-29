#include <iostream>
#pragma once 
class Product {
public:
    int product_id;
    std::string product_name;
    double price;
    int quantity;

    Product(int id, const std::string& name, double p, int q);
};
