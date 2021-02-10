#include "Customer.hpp"
std::string Customer::returnInfoToSave(){
    return this->customerName + ";" + this->customerSurname +";";
}
