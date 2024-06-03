#include "Barbie.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

int Barbie::garmentCount = 0;
int Barbie::numberOfChanges = 0;

Barbie::Barbie(): currentBlouse(nullptr), currentDress(nullptr), currentSkirt(nullptr), currentPants(nullptr) {}
void Barbie::addGarment(std::unique_ptr<Garment> g, const std::string& errorMessage) 
{
    for (const auto& garment : garments) 
        if (garment->isSameType(*g)) 
            throw AlreadyAddedGarment(errorMessage);
    garments.push_back(std::move(g));
    garmentCount++;
    numberOfChanges++;
}
void Barbie::addBlouse(std::unique_ptr<Blouse> blouse) 
{
    addGarment(std::move(blouse), "blouse already added!");
    if (!garments.empty()) 
        garments.back()->addedGarment();
}
void Barbie::addDress(std::unique_ptr<Dress> dress) 
{
    addGarment(std::move(dress), "dress already added!");
    if (!garments.empty()) 
        garments.back()->addedGarment();
}
void Barbie::addSkirt(std::unique_ptr<Skirt> skirt) 
{
    addGarment(std::move(skirt), "skirt already added!");
    if (!garments.empty()) 
        garments.back()->addedGarment();
}
void Barbie::addPants(std::unique_ptr<Pants> pants) 
{
    addGarment(std::move(pants), "pants already added!");
    if (!garments.empty()) 
        garments.back()->addedGarment();
}

template <typename T>
void Barbie::removeGarment(const std::string& errorMessage) 
{
    auto it = std::find_if(garments.begin(), garments.end(),[](const std::unique_ptr<Garment>& garment) 
    {
        return dynamic_cast<T*>(garment.get()) != nullptr;
    });
    if (it != garments.end()) 
    {
        (*it)->removedGarment(); 
        garments.erase(it);
        garmentCount--;
        numberOfChanges++;
    } 
    else 
        throw NothingToRemove(errorMessage);
}
void Barbie::removeBlouse() 
{
    removeGarment<Blouse>("There is no blouse to remove!");
}
void Barbie::removeDress() 
{
    removeGarment<Dress>("There is no dress to remove!");
}
void Barbie::removeSkirt() 
{
    removeGarment<Skirt>("There is no skirt to remove!");
}
void Barbie::removePants()
{
    removeGarment<Pants>("There are no pants to remove!");
}
int Barbie::GetGarmentCount(void)
{
    return garmentCount;
}
void Barbie::ViewChanges()
{
    if (numberOfChanges == 0)
        std::cout << "You haven't changed Barbie's look yet." << std::endl;
    else if (numberOfChanges == 1)  
        std::cout << "You've made " << numberOfChanges << " change at Barbie's look so far." << std::endl;
    else std::cout << "You've made " << numberOfChanges << " changes at Barbie's look so far." << std::endl;
}