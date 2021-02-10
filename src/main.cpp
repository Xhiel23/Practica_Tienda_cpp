#include "main.hpp"

int main(){
    std::string key, fileName;
    system("cls");
    print(1, "Eng");
    print(2,"Esp");
    choice = input("Choose a language/Elige un idioma: ");
    if(choice == 1){
        key = "eng";
        fileName = "Imports/eng.csv";
    }else{
        key = "esp";
        fileName = "Imports/esp.csv";
    }
    Language language(key,fileName);
    goOn = true;
    while(goOn){
        system("cls");
        std::cout <<  language.languageText.find("M")->second << "\n";
        print(0,language.languageText.find("MW")->second);
        print(1,language.languageText.find("MOC")->second);
        print(2,language.languageText.find("MWT")->second);
        print(3, language.languageText.find("LOAD")->second);
        print(4,language.languageText.find("MDM")->second);
        print(5,language.languageText.find("MQ")->second);
        choice = input(language.languageText.find("MOPT")->second);
        switch (choice)
        {
        case 0: // Foods
            system("cls");
            print(language.languageText.find("SM")->second + "\n");
            print(0,language.languageText.find("SMA")->second);
            print(1,language.languageText.find("SMR")->second);
            print(2,language.languageText.find("SMM")->second);
            print(3,language.languageText.find("SMC")->second);
            print(4,language.languageText.find("SVC")->second);
            print(5,language.languageText.find("SMP")->second);
            choice = input(language.languageText.find("MOPT")->second);
            switch(choice){
                system("cls");
                case 0: // Add food to the available products
                    foodName = inputString(language.languageText.find("EPN")->second + "\n");
                    print(0,language.languageText.find("D")->second);
                    print(1,language.languageText.find("F")->second);
                    choice = input(language.languageText.find("CFT")->second);
                    if (choice == 0 || choice == 1){
                        if(choice == 0){
                            foodType = language.languageText.find("D")->second;
                        }else{
                            foodType = language.languageText.find("F")->second;
                        }            
                        index = shop.foodIndex(foodName);
                        if(index != -1){
                            print(language.languageText.find("APE")->second + "\n");
                            errorLog.push_back(timeStamp() + " - " + language.languageText.find("APE")->second);
                        }else{
                            foodPrice = std::stof(inputString(language.languageText.find("EPP")->second + "\n"));
                            shop.addFood(foodName,foodType,foodPrice);
                            print(language.languageText.find("APM")->second + "\n");
                        }
                    }else{
                        print(language.languageText.find("AEP")->second + "\n");
                        errorLog.push_back(timeStamp() + " - " + language.languageText.find("AEP")->second);
                        print(language.languageText.find("EWI")->second + "\n");
                        errorLog.push_back(timeStamp() + " - " + language.languageText.find("EWI")->second);
                    }
                    break;
                case 1: // Delete food from available products
                    foodName = inputString(language.languageText.find("EPN")->second + "\n");
                    index = shop.foodIndex(foodName);
                    if(index == -1){
                        print(language.languageText.find("RPE")->second + "\n");
                        errorLog.push_back(timeStamp() + " - " + language.languageText.find("RPE")->second);
                    }else{
                        shop.availableFoods.erase(shop.availableFoods.begin()+index);
                        print(language.languageText.find("RPM")->second + "\n");
                    }
                    break;
                case 2: // Modify food from available product
                    foodName = inputString(language.languageText.find("EPN")->second + "\n");
                    index = shop.foodIndex(foodName);
                    if(index == -1){
                        print(language.languageText.find("CPE")->second + "\n");
                        errorLog.push_back(timeStamp() + " - " + language.languageText.find("CPE")->second);
                    }else{
                        print(0,language.languageText.find("FOP")->second);
                        print(1,language.languageText.find("SOP")->second);
                        print(2,language.languageText.find("TOP")->second);
                        choice = input(language.languageText.find("MOD")->second + "\n");
                        switch (choice)
                        {
                        case 0: // Modify product name
                            shop.availableFoods[index].productName = inputString(language.languageText.find("NNM")->second + "\n");
                            print(language.languageText.find("MPM")->second + "\n");
                            break;
                        case 1: // Modify product type
                            print(0,language.languageText.find("D")->second);
                            print(1,language.languageText.find("F")->second);
                            choice = input(language.languageText.find("CFT")->second);
                            if(choice == 0 || choice == 1){
                                if(choice == 0){
                                    shop.availableFoods[index].productType = "Drink";
                                }else{
                                    shop.availableFoods[index].productType = "Food";
                                }
                                print(language.languageText.find("MPM")->second + "\n");
                            }else{
                                print(language.languageText.find("MPEE")->second + "\n");
                                errorLog.push_back(timeStamp() + " - " + language.languageText.find("MPEE")->second);
                                print(language.languageText.find("EWI")->second + "\n");
                                errorLog.push_back(timeStamp() + " - " + language.languageText.find("EWI")->second);
                            }
                            break;
                        case 2: // Modify product price    
                            shop.availableFoods[index].price = std::stof(inputString(language.languageText.find("NPP")->second + "\n"));
                            print(language.languageText.find("MPM")->second + "\n");
                            break;
                        }
                    }
                    break;
                case 3: // Consult specific product
                    foodName = inputString(language.languageText.find("EPN")->second + "\n");
                    index = shop.foodIndex(foodName);
                    if(index == -1){
                        print(language.languageText.find("CPE")->second + "\n");
                        errorLog.push_back(timeStamp() + " - " + language.languageText.find("CPE")->second);
                    }else{
                        print(shop.availableFoods[index].productInfo() + "\n");
                    }
                    break;
                case 4: // View complete list of products
                    print("----------------------------------------------------- \n");
                    for(Product product:shop.availableFoods){
                        print(product.productInfo());
                        print("----------------------------------------------------- \n");
                    }    
                    break;
                case 5: // Go back
                    break;                
            }
            break;
        case 1: // Customers and orders
            system("cls");
            print(language.languageText.find("SM")->second +"\n");
            print(0,language.languageText.find("SCA")->second);
            print(1,language.languageText.find("SCR")->second);
            print(2,language.languageText.find("SCM")->second);
            print(3, language.languageText.find("SCC")->second);
            print(4,language.languageText.find("SCV")->second);
            print(5,language.languageText.find("SMP")->second);
            choice = input(language.languageText.find("MOPT")->second);
            switch (choice)
            {
            case 0: // Add customer
                customerName = inputString(language.languageText.find("ECN")->second);
                customerSurname = inputString(language.languageText.find("ECT")->second);
                index = shop.customerIndex(customerName,customerSurname);
                if(index != -1){
                    print(language.languageText.find("THF")->second + "\n");
                    errorLog.push_back(timeStamp() + " - " + language.languageText.find("THF")->second);
                }else{
                    shop.addCustomer(customerName,customerSurname);
                    print(language.languageText.find("THN")->second + "\n");
                }
                break;
            case 1: // Remove customer
                customerName = inputString(language.languageText.find("ECN")->second);
                customerSurname = inputString(language.languageText.find("ECT")->second);
                index = shop.customerIndex(customerName,customerSurname);
                if(index == -1){
                    print(language.languageText.find("THW")->second + "\n");
                    errorLog.push_back(timeStamp() + " - " + language.languageText.find("THW")->second);
                }else{
                    shop.removeCustomer(customerName,customerSurname);
                    print(language.languageText.find("THD")->second + "\n");
                }
                break;
            case 2: // Modify customer
                customerName = inputString(language.languageText.find("ECN")->second);
                customerSurname = inputString(language.languageText.find("ECT")->second);
                index = shop.customerIndex(customerName,customerSurname);
                if(index != -1){
                    system("cls");
                    print(0,language.languageText.find("COP")->second);
                    print(1,language.languageText.find("CSP")->second);
                    choice = input(language.languageText.find("MOD")->second + "\n");
                    switch (choice)
                    {
                    case 0:
                        customerName = inputString(language.languageText.find("ECN")->second);
                        shop.customerList[index].customerName = customerName;
                        break;
                    case 1:
                        customerSurname = inputString(language.languageText.find("ECT")->second);
                        shop.customerList[index].customerSurname = customerSurname;
                        break;
                    }
                    print(language.languageText.find("THM")->second + "\n");
                }else{
                    print(language.languageText.find("TPE")->second + "\n");
                    errorLog.push_back(timeStamp() + " - " + language.languageText.find("TPE")->second);
                }
                break;
            case 3: // Consult customer and corresponding orders
                customerName = inputString(language.languageText.find("ECN")->second);
                customerSurname = inputString(language.languageText.find("ECT")->second);
                index = shop.customerIndex(customerName,customerSurname);
                if(index == -1){
                    print(language.languageText.find("TPC")->second + "\n");
                    errorLog.push_back(timeStamp() + " - " + language.languageText.find("TPC")->second);
                }else{
                    system("cls");
                    print(language.languageText.find("COP")->second + ": " + shop.customerList[index].customerName + "\n");
                    print(language.languageText.find("CSP")->second + ": " + shop.customerList[index].customerSurname + "\n");
                    print(language.languageText.find("ORN")->second + ": " + std::to_string(shop.customerList[index].orders.size()) + "\n");
                    print(language.languageText.find("SM")->second +"\n");
                    print(0,language.languageText.find("ODA")->second);
                    print(1,language.languageText.find("ONC")->second);
                    print(2,language.languageText.find("ODD")->second);
                    print(3, language.languageText.find("ODM")->second);
                    print(4, language.languageText.find("ODV")->second);
                    print(5,language.languageText.find("SMP")->second);
                    choice = input(language.languageText.find("MOPT")->second);
                    switch(choice){
                    system("cls");
                    case 0: // Create order
                        day = input(language.languageText.find("TOD")->second);
                        month = input(language.languageText.find("TOM")->second);
                        if(month<1){
                            print(language.languageText.find("MPEE")->second + "\n");
                            errorLog.push_back(timeStamp() + " - " + language.languageText.find("MPEE")->second);
                            print(language.languageText.find("EWI")->second + "\n");
                            errorLog.push_back(timeStamp() + " - " + language.languageText.find("EWI")->second);
                        }else{
                            year = input(language.languageText.find("TOY")->second);
                            shop.addOrder(customerName,customerSurname,day,month,year);
                            print(language.languageText.find("OSC")->second + "\n");           
                        }          
                        break;
                    case 1: // Add product to order
                        day = input(language.languageText.find("TOD")->second);
                        month = input(language.languageText.find("TOM")->second);
                        year = input(language.languageText.find("TOY")->second);
                        index = shop.findOrderIndex(customerName, customerSurname, day,month,year);
                        if(index == -1){
                            print(language.languageText.find("ONF")->second + "\n");
                            errorLog.push_back(timeStamp() + " - " + language.languageText.find("ONF")->second);
                        }else{
                            print(language.languageText.find("AVO")->second + "\n");
                            for(int i = 0; i<shop.availableFoods.size(); i++){
                                print(i,shop.availableFoods[i].productInfo());
                            }
                            choice = input(language.languageText.find("CPTA")->second);
                            if(choice < 0 || choice >shop.availableFoods.size()){
                                print(language.languageText.find("EAPO")->second + "\n");
                                errorLog.push_back(timeStamp() + " - " + language.languageText.find("EAPO")->second);
                                print(language.languageText.find("EWI")->second + "\n");
                                errorLog.push_back(timeStamp() + " - " + language.languageText.find("EWI")->second);
                            }else{
                                quantity = input(language.languageText.find("QUA")->second + "\n");
                                shop.addProductToOrder(customerName, customerSurname, day, month, year, shop.availableFoods[choice], quantity);
                                print(language.languageText.find("APM")->second +"\n");
                            }    
                        }  
                        break;                
                    case 2: // Delete order
                        day = input(language.languageText.find("TOD")->second);
                        month = input(language.languageText.find("TOM")->second);
                        year = input(language.languageText.find("TOY")->second);
                        index = shop.findOrderIndex(customerName,customerSurname,day,month,year);
                        if(index == -1){
                            print(language.languageText.find("ONF")->second + "\n");
                            errorLog.push_back(timeStamp() + " - " + language.languageText.find("ONF")->second);
                        }else{
                            shop.customerList[shop.customerIndex(customerName,customerSurname)].orders.erase(shop.customerList[shop.customerIndex(customerName,customerSurname)].orders.begin()+index);
                            print(language.languageText.find("OSD")->second + "\n");
                        }
                        break;    
                    case 3: // Modify order 
                        day = input(language.languageText.find("TOD")->second);
                        month = input(language.languageText.find("TOM")->second);
                        year = input(language.languageText.find("TOY")->second);
                        index = shop.findOrderIndex(customerName, customerSurname, day,month,year);
                        if(index == -1){
                            print(language.languageText.find("ONF")->second + "\n");
                            errorLog.push_back(timeStamp() + " - " + language.languageText.find("AEP")->second);
                        }else{
                            system("cls");
                            print(language.languageText.find("MOD")->second + "\n");
                            print(0,language.languageText.find("ORDA")->second);
                            print(1,language.languageText.find("ORMO")->second);
                            print(2,language.languageText.find("ORYE")->second);
                            print(3,language.languageText.find("ORQT")->second);
                            print(4,language.languageText.find("SMR")->second);
                            print(5,language.languageText.find("SMP")->second);
                            choice = input(language.languageText.find("MOPT")->second);
                            switch (choice)
                            {
                            case 0: // Modify order day
                                changeData = input(language.languageText.find("TOD")->second);
                                shop.modifyOrder(customerName, customerSurname, day, month, year ,changeData, choice);
                                print(language.languageText.find("OLMD")->second + "\n");
                                break;
                            case 1: // Modify order month
                                month = input(language.languageText.find("TOM")->second);
                                if(month<1){
                                    print(language.languageText.find("MPEE")->second + "\n");
                                    errorLog.push_back(timeStamp() + " - " + language.languageText.find("MPEE")->second);
                                    print(language.languageText.find("EWI")->second + "\n");
                                    errorLog.push_back(timeStamp() + " - " + language.languageText.find("EWI")->second);
                                }else{
                                    shop.modifyOrder(customerName, customerSurname, day, month, year ,changeData, choice);
                                    print(language.languageText.find("OLMD")->second + "\n");
                                }
                                
                                break;
                            case 2: // Modify order year
                                changeData = input(language.languageText.find("TOY")->second);
                                shop.modifyOrder(customerName, customerSurname, day, month, year ,changeData, choice);
                                print(language.languageText.find("OLMD")->second + "\n");
                                break;
                            case 3: // Modify product quantity
                                print(language.languageText.find("AVO")->second + "\n");
                                for(int i = 0; i<shop.customerList[shop.customerIndex(customerName,customerSurname)].orders[index].products.size(); i++){
                                    print(i,shop.customerList[shop.customerIndex(customerName,customerSurname)].orders[index].products[i].orderProductInfo());
                                }
                                choice = input(language.languageText.find("CPTA")->second);
                                if(choice < 0 || choice >shop.customerList[shop.customerIndex(customerName,customerSurname)].orders[index].products.size()){
                                    print(language.languageText.find("EAPO")->second + "\n");
                                    errorLog.push_back(timeStamp() + " - " + language.languageText.find("EAPO")->second);
                                    print(language.languageText.find("EWI")->second + "\n");
                                    errorLog.push_back(timeStamp() + " - " + language.languageText.find("EWI")->second);
                                }else{
                                    quantity = input(language.languageText.find("QUA")->second + "\n");
                                    shop.customerList[shop.customerIndex(customerName,customerSurname)].orders[index].products[choice].setQuantity(quantity);
                                    print(language.languageText.find("OLMD")->second + "\n");
                                }    
                                break;
                            case 4: // Delete product
                                print(language.languageText.find("AVO")->second + "\n");
                                for(int i = 0; i<shop.customerList[shop.customerIndex(customerName,customerSurname)].orders[index].products.size(); i++){
                                    print(i,shop.customerList[shop.customerIndex(customerName,customerSurname)].orders[index].products[i].orderProductInfo());
                                }
                                choice = input(language.languageText.find("CPTA")->second);
                                if(choice < 0 || choice >shop.customerList[shop.customerIndex(customerName,customerSurname)].orders[index].products.size()){
                                    print(language.languageText.find("EAPO")->second + "\n");
                                    errorLog.push_back(timeStamp() + " - " + language.languageText.find("EAPO")->second);
                                    print(language.languageText.find("EWI")->second + "\n");
                                    errorLog.push_back(timeStamp() + " - " + language.languageText.find("EWI")->second);
                                }else{
                                    shop.customerList[shop.customerIndex(customerName,customerSurname)].orders[index].products.erase(shop.customerList[shop.customerIndex(customerName,customerSurname)].orders[index].products.begin()+choice);
                                    print(language.languageText.find("RPM")->second + "\n");
                                }    
                                break;          
                            case 5: // Go back
                                break;
                            }
                        }
                        break;
                    case 4: // View list of orders
                        for(Order order:shop.customerList[shop.customerIndex(customerName,customerSurname)].orders){
                            print("-------------------------------- \n");
                            print("Date: " + std::to_string(order.orderDay) + "/" + std::to_string(order.orderMonth) + "/" + std::to_string(order.orderYear));
                            print("\n");
                            print("-------------------------------- \n");
                            for(Product product:order.products){
                                print(product.orderProductInfo());
                                print("\n"); 
                            }
                            order.computeBill();
                            print("Total: " + std::to_string(order.totalPrice) + " euros" + "\n");
                        } 
                        break; 
                    case 5: // Go back
                        break;   
                }
                }
                break;
            case 4: // Print orders
                print("----------------------------------------------------- \n");
                for(Customer customer:shop.customerList){
                    print(language.languageText.find("COP")->second + ": " + shop.customerList[index].customerName + "\n");
                    print(language.languageText.find("CSP")->second + ": " + shop.customerList[index].customerSurname + "\n");
                    print(language.languageText.find("ORN")->second + ": " + std::to_string(shop.customerList[index].orders.size()) + "\n");
                    print("----------------------------------------------------- \n");
                }
                break;
            case 5:
                break;
            }
            break;
        case 2: // Save to file
            system("cls");
            print(language.languageText.find("WDY")->second + "\n");
            print(0,language.languageText.find("AVP")->second);
            print(1,language.languageText.find("AVC")->second);
            print(2,language.languageText.find("AVOP")->second);
            print(3,language.languageText.find("SMP")->second);
            choice = input(language.languageText.find("MOPT")->second);
            switch (choice)
            {
            case 0: // Save products
                for(Product product:shop.availableFoods){
                    products.push_back(product.saveProductToFile());
                }    
                saveToFile(products,"Exports/foods.csv");   
                print(language.languageText.find("SFM")->second + "\n");
                break;
            case 1: // Save customer
                for(Customer customer:shop.customerList){
                    customers.push_back(customer.returnInfoToSave());
                }
                saveToFile(customers,"Exports/customers.csv");
                print(language.languageText.find("SFM")->second + "\n");
                break;
            case 2: // Save orders
                for(std::string string:shop.allOrders()){
                    orders.push_back(string);
                }
                saveToFile(orders,"Exports/orders.csv");
                print(language.languageText.find("SFM")->second + "\n");
                break;    
            case 3: // Go back
                break;
            }
            break;
        case 3: // Load from file
            system("cls");
            print(language.languageText.find("WDYL")->second + "\n");
            print(0,language.languageText.find("AVP")->second);
            print(1,language.languageText.find("AVC")->second);
            print(2,language.languageText.find("AVOP")->second);
            print(3,language.languageText.find("SMP")->second);
            choice = input(language.languageText.find("MOPT")->second);
            switch(choice){
                case 0: //Load products
                    isOk = shop.loadProducts();
                    if(isOk){
                        print(language.languageText.find("RFM")->second +"\n");
                    }else{
                        print(language.languageText.find("RDE")->second + "\n");
                        errorLog.push_back(timeStamp() + " - " + language.languageText.find("RDE")->second);
                    }
                    break;
                case 1: // Load customers
                    isOk = shop.loadCustomers("Exports/customers.csv");
                    if(isOk){
                        print(language.languageText.find("RFM")->second +"\n");
                    }else{
                        print(language.languageText.find("RDE")->second + "\n");
                        errorLog.push_back(timeStamp() + " - " + language.languageText.find("RDE")->second);
                    }
                    break;
                case 2: // Load orders
                    //isOk = shop.loadCustomers("Exports/customers.csv");
                    //if(isOk){
                    //    print(language.languageText.find("RFM")->second +"\n");
                    //}else{
                    //    print(language.languageText.find("RDE")->second + "\n");
                    //    errorLog.push_back(timeStamp() + " - " + language.languageText.find("RDE")->second);
                    //}
                    break;       
            }
            break;    
        case 4: // Statistics
            system("cls");
            for(Customer customer:shop.customerList){
                for(Order order:customer.orders){
                    for(Product product:order.products){
                        shop.sales[order.orderMonth-1] += product.getQuantity();
                    }
                }
            }
            print(language.languageText.find("JAN")->second + " | ");
            print(language.languageText.find("FEB")->second + " | ");
            print(language.languageText.find("MAR")->second + " | ");
            print(language.languageText.find("APR")->second + " | ");
            print(language.languageText.find("MAY")->second + " | ");
            print(language.languageText.find("JUN")->second + " | ");
            print(language.languageText.find("JUL")->second + " | ");
            print(language.languageText.find("SEP")->second + " | ");
            print(language.languageText.find("OCT")->second + " | ");
            print(language.languageText.find("NOV")->second + " | ");
            print(language.languageText.find("DEC")->second + " | " + " \n ");
            for(int sale:shop.sales){
                print(std::to_string(sale) + "  |  ");
            }
            print("\n");
            break;
        case 5:
            goOn = false;
            break;
        }
        saveErrorToLog(errorLog);
        system("pause");
    }
    return 0;
}