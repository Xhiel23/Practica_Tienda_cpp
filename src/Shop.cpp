#include "Shop.hpp"

Shop::Shop(std::string shopName){
    this->shopName = shopName;
    this->sales = {0,0,0,0,0,0,0,0,0,0,0,0};
}

void Shop::addCustomer(std::string name, std::string surname){
    Customer newCustomer;
    newCustomer.customerName = name;
    newCustomer.customerSurname = surname;
    customerList.push_back(newCustomer);

}

void Shop::removeCustomer(std::string name, std::string surname){
    customerList.erase(customerList.begin()+customerIndex(name,surname));
}

bool Shop::existsCustomer(std::string name, std::string surname){
    bool exists = false;
    for(std::vector<Customer>::iterator cust = customerList.begin(); cust < customerList.end(); cust++){
        if(cust->customerName == name && cust->customerSurname == surname){
            exists = true;
        }
    }
    return exists;
}
int Shop::customerIndex(std::string name, std::string surname){
    int index = -1;
    for(int i = 0; i<customerList.size();  i++){
        if(customerList[i].customerName == name && customerList[i].customerSurname == surname){
            index = i;
        }
    }
    return index;
}
void Shop::addFood(std::string foodName, std::string foodType, double foodPrice){
    Product newProduct;
    newProduct.productName = foodName;
    newProduct.productType = foodType;
    newProduct.price = foodPrice;
    availableFoods.push_back(newProduct);
    
}
bool Shop::existsFood(std::string foodName, std::string foodType){
    bool exists = false;
    for(std::vector<Product>::iterator food = availableFoods.begin(); food < availableFoods.end(); food++){
        if(food->productName == foodName && food->productType == foodType){
            exists = true;
        }
    }
    return exists;
}
int Shop::foodIndex(std::string foodName, std::string foodType){
    int index = -1;
    for(int i = 0; i<this->availableFoods.size();  i++){
        if(this->availableFoods[i].productName == foodName && this->availableFoods[i].productType == foodType){
            index = i;
        }
    }
    return index;
}
int Shop::foodIndex(std::string foodName){
    int index = -1;
    for(int i = 0; i<this->availableFoods.size();  i++){
        if(this->availableFoods[i].productName == foodName){
            index = i;
        }
    }
    return index;
}
void Shop::printFoodInfo(std::string productName, std::string productType){
    print(availableFoods[foodIndex(productName,productType)].productInfo());
}
void Shop::printFoodInfo(Product product){
    print(product.productInfo());
}
std::vector<std::string> Shop::allOrders(){
    std::string line = "";
    std::vector<std::string> ordersInfo;
    for(Customer customer:this->customerList){
        for(Order order:customer.orders){
            line = customer.customerName + ";" + customer.customerSurname + ";" + std::to_string(order.orderDay) + ";" + std::to_string(order.orderMonth) + ";" +std::to_string(order.orderYear) +";";
            for(Product product:order.products){
                line += product.productName + ";" + std::to_string(product.getQuantity()) + ";" +std::to_string(product.price) + ";";
            }
            ordersInfo.push_back(line);
            line = "";
        }
    }
    return ordersInfo;
}
bool Shop::loadCustomers(std::string fileName){
    char line[255];
    std::ifstream file;
    std::string delimeter = ";";
    std::map<std::string, std::string> namesText;
    std::map<std::string, std::string>::iterator itr;
    file.open(fileName);
    if(!file){
        return false;
    }
    while(!file.eof()){
        file.getline(line,255);
        std::vector<std::string> strs;
        boost::algorithm::split(strs, line, boost::is_any_of(delimeter));
        namesText[strs.at(0)] = strs.at(1);
    }
    file.close();
    for (itr = namesText.begin(); itr != namesText.end(); itr++){
        Customer newCustomer;
        newCustomer.customerName = itr->first;
        newCustomer.customerSurname = itr->second;
        this->customerList.push_back(newCustomer);
    }
    return true;
}

bool Shop::loadProducts(){
    char line[255];
    std::ifstream file;
    std::string delimeter = ";";
    file.open("Exports/foods.csv");
    if(!file){
        return false;
    }
    while(!file.eof()){
        file.getline(line,255);
        std::vector<std::string> strs;
        boost::algorithm::split(strs, line, boost::is_any_of(delimeter));
        Product newProduct = Product(strs.at(0),strs.at(1),std::stof(strs.at(2)));
        this->availableFoods.push_back(newProduct);
    }
    file.close();
    return true;
}

bool Shop::loadOrders(){
    char line[255];
    std::ifstream file;
    std::string delimeter = ";";
    file.open("Exports/orders.csv");
    if(!file){
        return false;
    }
    while(!file.eof()){
        file.getline(line,255);
        std::vector<std::string> strs;
        boost::algorithm::split(strs, line, boost::is_any_of(delimeter));
        int customerIndex = this->customerIndex(strs.at(0),strs.at(1));
        Order newOrder;
        newOrder.orderDay = std::stoi(strs.at(2));
        newOrder.orderMonth = std::stoi(strs.at(3));
        newOrder.orderYear = std::stoi(strs.at(4));
        this->customerList[customerIndex].orders.push_back(newOrder);
        int orderIndex = this->findOrderIndex(strs.at(0),strs.at(1),std::stoi(strs.at(2)),std::stoi(strs.at(3)),std::stoi(strs.at(4)));
        for(int i=5; i<strs.size();i= i+3){
            Product orderProduct;
            orderProduct.productName = strs.at(i);
            orderProduct.productType = strs.at(i+1);
            orderProduct.setQuantity(std::stoi(strs.at(i+2)));
            this->customerList[customerIndex].orders[orderIndex].products.push_back(orderProduct);
        }
    }
    file.close();
    return true;
}
void Shop::addOrder(std::string customerName, std::string customerSurname, int day, int month, int year){
    int index = customerIndex(customerName,customerSurname);
    Order newOrder;
    newOrder.orderDay = day;
    newOrder.orderMonth = month;
    newOrder.orderYear = year;
    this->customerList[index].orders.push_back(newOrder);
}

void Shop::modifyOrder(std::string customerName, std::string customerSurname, int day, int month, int year ,int dataToChange, int id){
    int indexCust = customerIndex(customerName,customerSurname);
    int indexOr = findOrderIndex(customerName,customerSurname,day,month,year);
    switch (id)
    {
    case 0:
        this->customerList[indexCust].orders[indexOr].orderDay = dataToChange;
        break;
    case 1:
        this->customerList[indexCust].orders[indexOr].orderMonth = dataToChange;
        break;
    case 2:  
        this->customerList[indexCust].orders[indexOr].orderYear = dataToChange;  
        break;
    }
}

void Shop::addProductToOrder(std::string customerName, std::string customerSurname, int day, int month, int year, Product product, int quantity){
    int indexCust = this->customerIndex(customerName,customerSurname);
    int indexOrder = this->findOrderIndex(customerName,customerSurname,day,month,year);
    product.setQuantity(quantity);
    this->customerList[indexCust].orders[indexOrder].products.push_back(product);
}


int Shop::findOrderIndex(std::string customerName, std::string customerSurname, int day, int month, int year){
    int indexCust = this->customerIndex(customerName,customerSurname);
    for(int i = 0; i<this->customerList[indexCust].orders.size(); i++){
        if(this->customerList[indexCust].orders[i].orderDay == day && this->customerList[indexCust].orders[i].orderMonth == month && this->customerList[indexCust].orders[i].orderYear == year){
            return i;
        }
    }
    return -1;
}
