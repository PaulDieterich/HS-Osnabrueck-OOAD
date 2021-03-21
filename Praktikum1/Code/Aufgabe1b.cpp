#include <iostream>
#include <string.h>
#include <memory>

class Countable {
    public:
    Countable():ident(ncount) {
        std::cout << "0x" << std::hex << reinterpret_cast<std::uintptr_t>(this)<< std::dec << " Object " << ident << "/" << ncount++ << " created.\n";
    }
    ~Countable() {
        std::cout << "0x" << std::hex << reinterpret_cast<std::uintptr_t>(this)<< std::dec << " Object " << ident << " destroyed.\n";
    }
    std::uint64_t identifier() const {
         return ident; 
         }
    private:
    std::uint64_t ident;
    static std::uint64_t ncount;
};
class Konto : public Countable{
private: 
   
   
public: 
    std::uint32_t ident; 
    std::unique_ptr<Kunde> inhaber;
    Konto(std::uint32_t i): ident(i){};
    void print(){ std::cout << "Ident: " << ident << std::endl; }

};

class Kunde : public Countable{
private:
  
 
public:
    std::string name;
    std::unique_ptr<Konto> konto;
    Kunde(std::string n): name(n){};
    void print(){ std::cout << "Name: " << name << std::endl; }
    
};
std::unique_ptr<Konto> createOwnerAccount(const std::string& name, std::uint32_t account){
        std::unique_ptr<Konto> konto = std::make_unique<Konto>(account);
        konto->inhaber = std::make_unique<Kunde>(name);
        return konto;
}
int main(){
   
   
    std::unique_ptr<Konto> kontoPaul =  createOwnerAccount("Paul",3);
    kontoPaul->print();
    kontoPaul->inhaber->print();
    
   
   
       
    

    return 0;
}