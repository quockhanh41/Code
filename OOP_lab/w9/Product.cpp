#include "Product.h"
Product::Product(int id, const std::string& name, double p, int q)
    : product_id(id), product_name(name), price(p), quantity(q) {}