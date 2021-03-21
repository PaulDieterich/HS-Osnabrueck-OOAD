# OOAD Pratikum 1
## unique_ptr
**std::unique_ptr<Entity> uniqueEntity = std::make_unique<Entity>();**

    unique_ptr ist ein Pointer wrapper der ein Speicher allokiert, auf diesen speicher kann nur einmalig zugegriffen werden.
    Wenn zwei Pointer auf ein unique_pointer auf die selbe stelle schauen und der erste gelöscht wird, wird auch die speicherstelle freigegeben, somit zeigt der zweite pointer dann auf eine nicht allokierte speicherstelle. 


## shared_ptr
**std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();**

    shared_ptr lassen es zu das mehere pointer auf eine speicherstelle zeigen, diese brauchen etwas mehr speicher da auch gezählt wie viele zugriffe diese speicherstelle hat. Immer wenn ein weiterer Pointer auf diese Stelle zeigt wird ein Referenzzähler hochgezählt
    Der Speicher wird erste wieder freigegeben wenn alle pointer nicht mehr genutzt werden.

    

## weak_ptr
**std::weak_ptr<Entity> weakEntity;** 

**weakEntity = sharedEntity;**

    weak_ptr sind eine besondereit des shared_ptr. Es lassen sich shared_ptr an weak_ptr übergeben aber der Referenzzähler zählt nicht hoch.

    Es kann eine zu Zyklischen Referenzen von std::shared_ptr kommen wenn sich shared_ptr gegenseiting auf sich verweisen.
    Das Problem dabei, wenn es zu einer Zyklischen Abhäigkeit kommt kann der Referenzzähler nie den wert 0 erreichen und damit wird die Ressource nie automatisch gelöscht. 
    Dieses ist ein anwendugszweck für den weak_ptr, da dieser den Referenzzähler nicht seitgenlässt wird es nicht zu einem shared_ptr-Zyklus kommen. 

    



