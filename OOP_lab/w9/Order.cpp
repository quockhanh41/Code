#include "Order.h"
#include <iostream>

Order::Order(int order_id, const std::string& customer_name, const std::string& phone_number,
             const std::string& shipping_address, PaymentStrategy* payment_strategy)
    : order_id(order_id), customer_name(customer_name), phone_number(phone_number),
      shipping_address(shipping_address), payment_strategy(payment_strategy) {}

void Order::add_product(const Product& product) {
    products.push_back(product);
}

double Order::calculate_total_price() const {
    double total_price = 0.0;
    for (const auto& product : products) {
        total_price += product.price * product.quantity;
    }
    return total_price;
}

void Order::process_order() {
    double total_price = calculate_total_price();
    payment_strategy->pay(total_price);
}
