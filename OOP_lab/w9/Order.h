#include "Product.h"
#include "payment_strategy.h"
#include <vector>
#pragma once 
class Order {
private:
    int order_id;
    std::string customer_name;
    std::string phone_number;
    std::string shipping_address;
    PaymentStrategy* payment_strategy;
    std::vector<Product> products;

public:
    Order(int order_id, const std::string& customer_name, const std::string& phone_number,
          const std::string& shipping_address, PaymentStrategy* payment_strategy);

    void add_product(const Product& product);

    double calculate_total_price() const;

    void process_order();
};
