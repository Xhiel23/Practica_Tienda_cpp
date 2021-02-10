#include "Order.hpp"

Order::Order(int orderDay, int orderMonth, int orderYear){
    this->orderDay = orderDay;
    this->orderMonth = orderMonth;
    this->orderYear = orderYear;
    this->totalProducts = 0;
    this->totalPrice = 0;
}
Order::Order(){
    this->orderDay = 0;
    this->orderMonth = 0;
    this->orderYear = 0;
    this->totalProducts = 0;
    this->totalPrice = 0;
}

void Order::computeBill(){
    for(Product product:this->products){
        this->totalProducts += product.getQuantity();
        this->totalPrice += product.getQuantity()*product.price;
    }
}

void Order::printOrders(){
    for(Product product:this->products){
        product.orderProductInfo();
    }
    computeBill();
    print("Total : ");
    print(std::to_string(totalPrice));
}

