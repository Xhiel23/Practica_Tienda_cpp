#include "Order.hpp"
class Customer{
    public:
        std::string customerName;
        std::string customerSurname;
        std::vector<Order> orders;
        std::string returnInfoToSave();
};

