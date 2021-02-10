#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <windows.h>
#include <boost/algorithm/string.hpp>

int input(std::string text);
void print(std::string text);
void print(int id, std::string text);
bool checkDataRange(int min, int max, int choice);
std::string inputString(std::string text);
std::string timeStamp();
void saveErrorToLog(std::vector<std::string> errors);
void saveToFile(std::vector<std::string> lines, std::string fileName);
