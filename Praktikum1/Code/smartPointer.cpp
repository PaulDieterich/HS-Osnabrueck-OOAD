#include <iostream>
#include <string>
#include <memory>


class Entity{
public:
    Entity(){
        std::cout << "CREATE ENTITY!" << std::endl;
    }
    ~Entity(){
        std::cout << "DELETE ENTITY!" << std::endl;
    }
    void unique_print(){
        std::cout << "UNIQUE-ENTITY IS PRINTING" << std::endl;
    }
    void shared_print(){
        std::cout << "SHARED-ENTITY IS PRINTING" << std::endl;
    }

};

int main(){

            // Erstellt eine Speicherstelle auf die nur einmal mit einem Pointer drauf verwiesen werden kann.
            // Der Poiner wird automatisch gelöscht nachdem er nicht mehr gebraucht wird.
            {
                std::unique_ptr<Entity> uniqueEntity = std::make_unique<Entity>();
                uniqueEntity->unique_print();
            }
            //Referenzcounting 
            
                 std::shared_ptr<Entity> se0;
                {
                    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
                    std::cout << sharedEntity << std::endl;
                    sharedEntity->shared_print();
                    se0 = sharedEntity;
                    se0->shared_print();
                    std::cout << "SHARED ENTITY WURDE "<< sharedEntity.use_count() << " MAL GENUTZT"<<std::endl; //gibt die anzahl von genutzten pointern zurück
                }
            std::cout << se0 << std::endl;
            std::weak_ptr<Entity> weakEntity;
            weakEntity = se0;
           std::cout << se0.use_count() << std::endl;

    
    return 0;
}