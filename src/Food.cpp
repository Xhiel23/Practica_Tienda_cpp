#include "Food.hpp"
#include <iomanip>

Product::Product(std::string productName, std::string productType, float price){
    this->productName = productName;
    this->productType = productType;
    this->price = price;
    this->quantity = 0;
};
Product::Product(){
    this->productName = "default";
    this->productType = "default";
    this->price = 0;
    this->quantity = 0;
}
void Product::setQuantity(int quantity){
    this->quantity = quantity;
};
int Product::getQuantity(){
    return this->quantity;
}

std::string Product::productInfo(){
    return this->productName + " - " + this->productType + " - " + std::to_string(this->price) + " euros/un. \n";
}

std::string Product::orderProductInfo(){
    return this->productName + " - " + std::to_string(this->quantity) + " - " + std::to_string(this->price) + " - " + std::to_string(this->quantity*this->price) + "\n";
}

std::string Product::saveProductToFile(){
    return this->productName + ";" + this->productType + ";" + std::to_string(this->price) + ";";
}


