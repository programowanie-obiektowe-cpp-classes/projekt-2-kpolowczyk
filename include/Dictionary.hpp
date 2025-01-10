#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class Dictionary {
public:
    void addDefinition(const std::string& term, const std::string& definition);
    std::string getDefinition(const std::string& term) const;
    std::vector<std::string> search(const std::string& pattern) const;
    void printAllDefinitions() const;

private:
    std::unordered_map<std::string, std::string> m_definitions;
    bool matchPattern(const std::string& term, const std::string& pattern) const;   
};

#endif 
