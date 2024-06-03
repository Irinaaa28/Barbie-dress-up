#ifndef BARBIE_H
#define BARBIE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

#include "Blouse.h"
#include "Dress.h"
#include "Skirt.h"
#include "Pants.h"
#include "AlreadyAddedGarment.h"
#include "NothingToRemove.h"
#include "NonExistentGarment.h"

class Barbie
{
protected:
    Blouse* currentBlouse;
    Dress* currentDress;
    Skirt* currentSkirt;
    Pants* currentPants;
    std::vector<std::unique_ptr<Garment>> garments;
    static int garmentCount;
    static int numberOfChanges;
public:
    Barbie(); 
    void addGarment(std::unique_ptr<Garment> g, const std::string& errorMessage); 
    void addBlouse(std::unique_ptr<Blouse> blouse);
    void addDress(std::unique_ptr<Dress> dress);
    void addSkirt(std::unique_ptr<Skirt> skirt);
    void addPants(std::unique_ptr<Pants> pants); 
    template <typename T>
    void removeGarment(const std::string& errorMessage);
    void removeBlouse();
    void removeDress(); 
    void removeSkirt(); 
    void removePants();
    static int GetGarmentCount(void);
    static void ViewChanges();
};

#endif // BARBIE_H