#ifndef _PRODUCT_HPP_
#define _PRODUCT_HPP_

#include <iostream>
using namespace std;

class Product {

private:
    string name {};
    string description {};
    double price {};
    unsigned int stock_quantity {};

    static constexpr const char *name_def {"Undefined name"};
    static constexpr const char *description_def {"No product description"};

public:
    Product(string name_val = name_def, string description_val = description_def, double price_val = 0, unsigned int quantity_val = 0) 
    : name{name_val}, description{description_val}, price{price_val}, stock_quantity{quantity_val} { };
    bool operator==(const Product &rhs) const {return price == rhs.price;}
    bool operator<(const Product &rhs) const {return price < rhs.price;}
};


#endif /* _PRODUCT_HPP_ */