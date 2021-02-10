#include "Language.hpp"

Language::Language(std::string langKey, std::string fileName)
{
    this->langKey = langKey;
    this->fileName = fileName;
    setLanguageText();
}

void Language::setLanguageText(){
    char line[255];
    std::ifstream file;
    std::string delimeter = ";";
    file.open(this->fileName);
    while(!file.eof()){
        file.getline(line,255);
        std::vector<std::string> strs;
        boost::algorithm::split(strs, line, boost::is_any_of(delimeter));
        languageText[strs.at(0)] = strs.at(1);
    }
    file.close();
}