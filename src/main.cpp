#include "Dictionary.hpp"
#include <iostream>

int main() {
    Dictionary dict;
    


    bool manual=true;
    int type;
    std::string definicja; 
    std::string klucz;

    while(manual){
    std::cout<<"\n\n----------------------"<<std::endl;
    std::cout<<"1. Dodaj definicje"<<std::endl;
    std::cout<<"2. Znajdz definicje"<<std::endl;
    std::cout<<"3. Szukaj definicji"<<std::endl;
    std::cout<<"4. Drukuj slownik"<<std::endl;
    std::cout<<"5. Zamknij program"<<std::endl;
    std::cout<<"----------------------"<<std::endl;
    std::cin>>type;


    dict.addDefinition("jablko lub gruszka", "owoc");
    dict.addDefinition("jabbko albo arbuz", "jakby owoc");
    dict.addDefinition("appl", "A fruit that is red or green.");
    dict.addDefinition("banana", "A long yellow fruit.");
    dict.addDefinition("grape", "A small, round, purple or green fruit.");



    
    switch (type)
    {
    case 1:
        std::cout << "Wyraz: ";
        std::cin.ignore();
        std::getline(std::cin, klucz);
        std::cout << "Definicja: ";
        std::getline(std::cin, definicja);
        dict.addDefinition(klucz, definicja);
        std::cout <<"\n"<< klucz << ": " << definicja << std::endl;
        break;
    case 2:
    std::cout<<"Wyraz: ";
        std::cin.ignore();
        std::getline(std::cin, klucz);
        definicja=dict.getDefinition(klucz);
        std::cout<<"\n"<<klucz<<": "<<definicja;
        break;
    case 3:
        std::cout<<"Dowolny ciag znakow zastap znakiem *, a dowolna litere jako ?"<<std::endl;
        std::cout<<"Fraza do znalezienia:\t";
        std::cin>>klucz;
        std::cout<<"\n";
        for (const auto& result : dict.search(klucz)) {std::cout << result << std::endl;}
        break;
    case 4:
        dict.printAllDefinitions();
        break;
    case 5:
        manual=false;
        break;
    default:
        break;
    }
    }
    return 0;
}
