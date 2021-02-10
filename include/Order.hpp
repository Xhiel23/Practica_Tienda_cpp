#include "utilities.hpp"
#include "Food.hpp"
class Order
{
    public:
    std::vector<Product> products;
    int orderDay;
    int orderMonth;
    int orderYear;
    int totalProducts;
    double totalPrice;
    Order(int orderDay, int orderMonth, int orderYear);
    Order();
    void computeBill();
    void printOrders();
};

