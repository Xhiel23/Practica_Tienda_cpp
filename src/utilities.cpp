#include "utilities.hpp"
int input(std::string text){
    print(text);
    int data;
    std::cin >> data;
    return data;
}
void print(std::string text){
    std::cout << text;
}

void print(int id, std::string text){
    std::cout << "[" << id << "]" << " " << text << "\n";
}

bool checkDataRange(int min, int max, int choice){
    return (choice>=min && choice<=max);
}
std::string inputString(std::string text){
    print(text);
    std::string data;
    std::cin >> data;
    return data;
}
std::string timeStamp(){
    auto currentTime = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(currentTime);
    std::stringstream stream;
    stream << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return stream.str();
}
void saveErrorToLog(std::vector<std::string> errors) {
    std::ofstream file;
    file.open("Exports/errorLog.csv", std::ios::out);
    if (!file) {
        print("No log file \n");
    }else {
        for(std::string errorLine:errors){
            file << errorLine + "\n";
        }
        file.close();
    }
}
void saveToFile(std::vector<std::string> lines, std::string fileName){
    std::ofstream file;
    file.open(fileName,std::ios::out);
    if(!file){
        print("No file \n");
    }else{
        for(int i = 0; i<lines.size(); i++){
            if(i != lines.size()-1){
                file << lines[i] + "\n";
            }else{
                file << lines[i];
            }
        }
        file.close();
    }
}
