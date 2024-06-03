#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

#include "Wardrobe.h"
#include "Garment.h"
#include "Blouse.h"
#include "Dress.h"
#include "Skirt.h"
#include "Pants.h"
#include "AlreadyAddedGarment.h"
#include "NonExistentGarment.h"
#include "NothingToRemove.h"
#include "Barbie.h"
#include "OtherFunctions.h"

int main()
{
    std::unique_ptr<Blouse> blouse1 = std::make_unique<Blouse>("#BT1CR", "Red");
    std::unique_ptr<Blouse> blouse2 = std::make_unique<Blouse>("#BT1CB", "Blue");
    std::unique_ptr<Blouse> blouse3 = std::make_unique<Blouse>("#BT1CG", "Green");
    std::unique_ptr<Blouse> blouse4 = std::make_unique<Blouse>("#BT1CY", "Yellow");

    std::unique_ptr<Dress> dress1 = std::make_unique<Dress>("#DT1CR", "Red");
    std::unique_ptr<Dress> dress2 = std::make_unique<Dress>("#DT1CB", "Blue");
    std::unique_ptr<Dress> dress3 = std::make_unique<Dress>("#DT1CG", "Green");
    std::unique_ptr<Dress> dress4 = std::make_unique<Dress>("#DT1CY", "Yellow");

    std::unique_ptr<Skirt> skirt1 = std::make_unique<Skirt>("#ST1CR", "Red");
    std::unique_ptr<Skirt> skirt2 = std::make_unique<Skirt>("#ST1CB", "Blue");
    std::unique_ptr<Skirt> skirt3 = std::make_unique<Skirt>("#ST1CG", "Green");
    std::unique_ptr<Skirt> skirt4 = std::make_unique<Skirt>("#ST1CY", "Yellow");

    std::unique_ptr<Pants> pants1 = std::make_unique<Pants>("#PT1CR", "Red");
    std::unique_ptr<Pants> pants2 = std::make_unique<Pants>("#PT1CB", "Blue");
    std::unique_ptr<Pants> pants3 = std::make_unique<Pants>("#PT1CG", "Green");
    std::unique_ptr<Pants> pants4 = std::make_unique<Pants>("#PT1CY", "Yellow");

    Barbie myBarbie;

    char key;
    bool continuegame;
    std::cout << "Press any key to start dressing up Barbie: " << std::endl; 
    std::cin >> key;
    std::cout << "Do you want to change Barbie's look? \n Yes (1) \t No (0)" << std::endl;
    std::cin >> continuegame;
    if (continuegame == 1)
    {
        std::cout << "Great! So let's get started\nOpen your mind and create the best outfit for Barbie!\n";
        while (continuegame == 1)
        {
            bool addClothes;
            std::cout << "Do you want to add some clothes?\nYes(1) \t No(0)" << std::endl;
            std::cin >> addClothes;
            while (addClothes != 0)
            {
                try
                {
                    std::string addGarmentType;
                    std::cout << "What kind of clothes do you want to add?" << std::endl;
                    std::cin >> addGarmentType;
                    if (toLower(addGarmentType) == "blouse")
                    {
                        int numberBlouse;
                        std::cout << "Add a blouse code and a blouse color from the wardrobe:\n";
                        blouse1->describe();
                        blouse2->describe();
                        blouse3->describe();
                        blouse4->describe();
                        std::cin >> numberBlouse;
                        try
                        {
                            checkNumber(numberBlouse);
                        }
                        catch(const NonExistentGarment& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                        if (numberBlouse == 1) 
                            myBarbie.addBlouse(std::make_unique<Blouse>(*blouse1));
                        else if (numberBlouse == 2) 
                            myBarbie.addBlouse(std::make_unique<Blouse>(*blouse2));
                        else if (numberBlouse == 3) 
                            myBarbie.addBlouse(std::make_unique<Blouse>(*blouse3));
                        else if (numberBlouse == 4) 
                            myBarbie.addBlouse(std::make_unique<Blouse>(*blouse4));
                    }  
                    else if (toLower(addGarmentType) == "dress")
                    {
                        int numberDress;
                        std::cout << "Add a dress code and a dress color from the wardrobe:\n";
                        dress1->describe();
                        dress2->describe();
                        dress3->describe();
                        dress4->describe();
                        std::cin >> numberDress;
                        try
                        {
                            checkNumber(numberDress);
                        }
                        catch(const NonExistentGarment& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                        if (numberDress == 1)
                            myBarbie.addDress(std::make_unique<Dress>(*dress1));
                        else if (numberDress == 2)
                            myBarbie.addDress(std::make_unique<Dress>(*dress2));
                        else if (numberDress == 3)
                            myBarbie.addDress(std::make_unique<Dress>(*dress3));
                        else if (numberDress == 4)
                            myBarbie.addDress(std::make_unique<Dress>(*dress4));
                    }
                    else if (toLower(addGarmentType) == "skirt")
                    {
                        int numberSkirt;
                        std::cout << "Add a skirt code and a skirt color from the wardrobe:\n";
                        skirt1->describe();
                        skirt2->describe();
                        skirt3->describe();
                        skirt4->describe();
                        std::cin >> numberSkirt;
                        try
                        {
                           checkNumber(numberSkirt);
                        }
                        catch(const NonExistentGarment& e)
                        {
                           std::cerr << e.what() << '\n';
                        }
                        if (numberSkirt == 1) 
                            myBarbie.addSkirt(std::make_unique<Skirt>(*skirt1));
                        else if (numberSkirt == 2) 
                            myBarbie.addSkirt(std::make_unique<Skirt>(*skirt2));
                        else if (numberSkirt == 3) 
                            myBarbie.addSkirt(std::make_unique<Skirt>(*skirt3));
                        else if (numberSkirt == 4) 
                            myBarbie.addSkirt(std::make_unique<Skirt>(*skirt4));
                    }
                    else if (toLower(addGarmentType) == "pants")
                    {
                        int numberPants;
                        std::cout << "Add a pants code and a pants color from the wardrobe:\n";
                        pants1->describe();
                        pants2->describe();
                        pants3->describe();
                        pants4->describe();
                        std::cin >> numberPants;
                        try
                        {
                            checkNumber(numberPants);
                        }
                        catch(const NonExistentGarment& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                        if (numberPants == 1) 
                            myBarbie.addPants(std::make_unique<Pants>(*pants1));
                        else if (numberPants == 2) 
                            myBarbie.addPants(std::make_unique<Pants>(*pants2));
                        else if (numberPants == 3) 
                            myBarbie.addPants(std::make_unique<Pants>(*pants3));
                        else if (numberPants == 4) 
                            myBarbie.addPants(std::make_unique<Pants>(*pants4));
                    }    
                }
                catch(const AlreadyAddedGarment& e)
                {
                    std::cerr << "Error: " <<  e.what() << '\n';
                }
                std::cout << "Do you want to add anything else?\nYes(1) \t No(0)\n";
                std::cin >> addClothes;
            }
            bool removeClothes;
            std::cout << "Do you want to remove some clothes?\nYes(1) \t No(0)" << std::endl;
            std::cin >> removeClothes;
            while (removeClothes != 0)
            {
                try
                {
                    std::string removeGarmentType;
                    std::cout << "What kind of clothes do you want to remove?" << std::endl;
                    std::cin >> removeGarmentType;
                    if (toLower(removeGarmentType) == "blouse")
                        myBarbie.removeBlouse();
                    else if (toLower(removeGarmentType) == "dress")
                        myBarbie.removeDress();
                    else if (toLower(removeGarmentType) == "skirt")
                        myBarbie.removeSkirt();
                    else if (toLower(removeGarmentType) == "pants")
                        myBarbie.removePants();
                }
                catch(const NothingToRemove& e)
                {
                    std::cerr << "Error: " << e.what() << '\n';
                }
                std::cout << "Do you want to remove anything else?\nYes(1) \t No(0)\n";
                std::cin >> removeClothes;
            }
            bool change;
            std::cout << "Do you want to see how many changes have you done so far?\nYes(1) \t No(0)\n";
            std::cin >> change;
            if (change == 1)
                myBarbie.ViewChanges();
            std::cout << "Do you want to change something at Barbie's current look?\nYes(1) \t No(0)\n";
            std::cin >> continuegame;
        }
    }
    Display(myBarbie);
    std::cout << "That's the end of the game!" << std::endl;
    return 0;
}