#include <windows.h>
#include "Language.hpp"
#include "Shop.hpp"
int choice, index, changeData;
bool goOn, isOk;
Shop shop("My Shop");
std::string customerName,customerSurname;
std::string foodName,foodType;
float foodPrice;
int day,month,year,quantity;
std::vector<std::string> errorLog;
std::vector<std::string> products;
std::vector<std::string> orders;
std::vector<std::string> customers;
