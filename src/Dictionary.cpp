#include "Dictionary.hpp"
#include <regex>

void Dictionary::addDefinition(const std::string& term, const std::string& definition) {
    m_definitions[term] = definition;
}

std::string Dictionary::getDefinition(const std::string& term) const {
    auto it = m_definitions.find(term);
    if (it != m_definitions.end()) {
        return it->second;
    }
    return "Nie znaleziono definicji";
}

std::vector<std::string> Dictionary::search(const std::string& pattern) const {
    std::vector<std::string> results; //wektor wyników
    std::string regexPattern = std::regex_replace(pattern, std::regex("\\*"), ".*"); 
    regexPattern = std::regex_replace(regexPattern, std::regex("\\?"), ".");
    std::regex regex(regexPattern);



    for (const auto& [term, definition] : m_definitions) {
        if (std::regex_match(term, regex)) {
            results.push_back(term + ": " + definition);
        }
    }
    return results;
}

void Dictionary::printAllDefinitions() const {
    for (const auto& [term, definition] : m_definitions) {
        std::cout << term << ":\t" << definition << std::endl;
    }
}