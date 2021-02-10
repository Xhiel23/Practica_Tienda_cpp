#include "Customer.hpp"
class Shop
{
private:
    
    bool existsCustomer(std::string name,std::string surname);
    
public:
    std::vector<Customer> customerList; 
    std::vector<int> sales;
    std::string shopName;   
    std::vector<Product> availableFoods;
    Shop(std::string shopName);
    int foodIndex(std::string foodName, std::string foodType);
    int foodIndex(std::string foodName);
    void addCustomer(std::string name, std::string surname);
    void removeCustomer(std::string name, std::string surname);
    void modifyCustomer(Customer customer);
    int customerIndex(std::string name,std::string surname);
    bool existsFood(std::string foodName, std::string foodType);
    void addFood(std::string foodName, std::string foodType,double foodPrice);
    void printFoodInfo(std::string productName, std::string productType);
    void printFoodInfo(Product product);
    std::vector<std::string> allOrders();
    bool loadCustomers(std::string fileName);
    bool loadProducts();
    bool loadOrders();
    void addOrder(std::string customerName, std::string customerSurname, int day, int month, int year);
    void modifyOrder(std::string customerName, std::string customerSurname, int day, int month, int year ,int dataToChange, int value);
    int findOrderIndex(std::string customerName, std::string customerSurname, int day, int month, int year);
    void addProductToOrder(std::string customerName, std::string customerSurname, int day, int month, int year, Product product, int quantity);
};

