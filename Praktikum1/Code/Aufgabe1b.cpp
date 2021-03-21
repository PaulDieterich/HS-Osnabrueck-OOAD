#include <iostream>
#include <string.h>
#include <memory>

class Konto{
private: 
    std::uint32_t ident; 
public: 
    Konto(std::uint32_t i): ident(i){};
    void print(){ std::cout << "Ident: " << ident << std::endl; }

};

class Kunde{
private:
    std::string name;
public:
    Kunde(std::string n): name(n){};
    void print(){ std::cout << "Name: " << name << std::endl; }
};


int main(){

    std::unique_ptr<Konto> createOwnerAccount(const std::string& name, std::uint32_t account){
            
    }

    return 0;
}