#include "utilities.hpp"
class Product
{
    private:
        int quantity;
    public:
        std::string productName;
        std::string productType;
        float price;
        Product();
        Product(std::string productName, std::string productType, float price);
        void setQuantity(int quantity);
        int getQuantity();
        std::string productInfo();
        std::string orderProductInfo();
        std::string saveProductToFile();
};

