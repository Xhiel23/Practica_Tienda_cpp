#include "utilities.hpp"

class Language
{
private:
    std::string langKey;
    std::string fileName;
    void setLanguageText();
public:
    std::map<std::string, std::string> languageText;
    Language(std::string langKey, std::string fileName);
    
};

