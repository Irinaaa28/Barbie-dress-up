#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

std::string toLower(const std::string& str) 
{
    std::string result = str;
    for (char& c : result) 
        c = tolower(c);
    return result;
}

class Wardrobe //interface definition
{
public:
    //pure virtual functions
    virtual void describe() const = 0;
    virtual std::string getCode() const  = 0;//getter code
    virtual std::string getColor() const  = 0;//getter color
};

class Garment : public Wardrobe //abstract class
{
protected:
    std::string garmentCode;
    std::string garmentColor;
public:
    Garment(const std::string& garmentCode, const std::string& garmentColor): garmentCode(garmentCode), garmentColor(garmentColor) {} //constructor
    //pure virtual functions
    virtual void describe() const = 0;
    virtual void addedGarment() const = 0;
    virtual void removedGarment() const = 0;
    virtual std::unique_ptr<Garment> clone() const = 0;
    //implementing some functions from interface
    std::string getCode() const override
    {
        return garmentCode;
    }
    std::string getColor() const override
    {
        return garmentColor;
    }
    bool isSameType(const Garment& other) const
    {
        return typeid(*this) == typeid(other);
    }
    virtual ~Garment() = default;
};

class Blouse : public Garment
{
public:
    Blouse(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
    //interface implementing 
    void describe() const override
    {
        std::cout << "Blouse: " << garmentCode << ", color: " << garmentColor << std::endl;
    }
    void describeBlouse() const 
    {
        std::cout << "A blouse: " << garmentCode << " " << garmentColor << std::endl;
    }
    void addedGarment() const override
    {
        std::cout << "Blouse added successfully!" << std::endl;
    }
    void removedGarment() const override
    {
        std::cout << "Blouse removed successfully!" << std::endl;
    }
    void setBlouse(const std::string& blouseName, const std::string& colorName) //setter
    {
        garmentCode = blouseName;
        garmentColor = colorName;
    }
    std::unique_ptr<Garment> clone() const override // Implementare metoda clone
    {
        return std::make_unique<Blouse>(*this);
    }
    Blouse& operator=(const Blouse& other) //operator=
    {
        if(this != &other)
        {
            garmentCode = other.garmentCode;
            garmentColor = other.garmentColor;
        }
        return *this;
    }
    Blouse(const Blouse& other) : Garment(other) {} // Constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Blouse& b) //operator<<
    {
        os << "Blouse: " << b.garmentCode << ", color: " << b.garmentColor;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Blouse& b) //operator>>
    {
        std::cout << "Blouse_code: ";
        is >> b.garmentCode;
        std::cout << "color: ";
        is >> b.garmentColor;
        return is;
    }
    Blouse(Blouse&& other) noexcept: Garment(std::move(other)) //move constructor
    {
        other.garmentCode.clear();
        other.garmentColor.clear();
    }
    Blouse& operator=(Blouse&& other) noexcept //move assignment operator for Blouse
    {
        if (this != &other)
        {
            garmentCode = std::move(other.garmentCode);
            garmentColor = std::move(other.garmentColor);
            other.garmentCode.clear();
            other.garmentColor.clear();
        }
        return *this;
    }
};

class Dress : public Garment
{
public:
    Dress(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
    //interface implementing
    void describe() const override
    {
        std::cout << "Dress: " << garmentCode << ", color: " << garmentColor << std::endl;
    }
    void describeDress() const 
    {
        std::cout << "A dress: " << garmentCode << " " << garmentColor << std::endl;
    }
    void addedGarment() const override
    {
        std::cout << "Dress added successfully!" << std::endl;
    }
    void removedGarment() const override
    {
        std::cout << "Dress removed successfully!" << std::endl;
    }
    std::unique_ptr<Garment> clone() const override 
    {
        return std::make_unique<Dress>(*this);
    }
    void setDress(const std::string& dressName, const std::string& colorName) //setter
    {
        garmentCode = dressName;
        garmentColor = colorName;
    }
    Dress& operator=(const Dress& other) //operator=
    {
        if (this != &other)
        {
            garmentCode = other.garmentCode;
            garmentColor = other.garmentColor;
        }
        return *this;
    }
    Dress(const Dress& other): Garment(other) {} //constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Dress& d) //operator<<
    {
        os << "Dress: " << d.garmentCode << ", color: " << d.garmentColor;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Dress& d) //operator>>
    {
        std::cout << "Dress_code: ";
        is >> d.garmentCode;
        std::cout << "color: ";
        is >> d.garmentColor;
        return is;
    }
    Dress(Dress&& other) noexcept: Garment(std::move(other)) //move constructor
    {
        other.garmentCode.clear();
        other.garmentColor.clear();
    }
    Dress& operator=(Dress&& other) noexcept //move assignment operator for Dress
    {
        if (this != &other)
        {
            garmentCode = std::move(other.garmentCode);
            garmentColor = std::move(other.garmentColor);
            other.garmentCode.clear();
            other.garmentColor.clear();
        }
        return *this;
    }
};

class Skirt : public Garment
{
public:
    Skirt(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
    //interface implementing
    void describe() const override
    {
        std::cout << "Skirt: " << garmentCode << ", color: " << garmentColor << std::endl;
    }
    void describeSkirt() const
    {
        std::cout << "A skirt: " << garmentCode << " " << garmentColor << std::endl;
    }
    void addedGarment() const override
    {
        std::cout << "Skirt added successfully!" << std::endl;
    }
    void removedGarment() const override
    {
        std::cout << "Skirt removed successfully!" << std::endl;
    }
    void setSkirt(const std::string& skirtName, const std::string& colorName) //setter
    {
        garmentCode = skirtName;
        garmentColor = colorName;
    }
    std::unique_ptr<Garment> clone() const override 
    {
        return std::make_unique<Skirt>(*this);
    }
    Skirt& operator=(const Skirt& other) //operator=
    {
        if (this != &other)
        {
            garmentCode = other.garmentCode;
            garmentColor = other.garmentColor;
        }
        return *this;
    }
    Skirt(const Skirt& other): Garment(other) {} //constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Skirt& s) //operator<<
    {
        os << "Skirt: " << s.garmentCode << ", color: " << s.garmentColor;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Skirt& s) //operator>>
    {
        std::cout << "Skirt_code: ";
        is >> s.garmentCode;
        std::cout << "color: ";
        is >> s.garmentColor;
        return is;
    }
    Skirt(Skirt&& other) noexcept: Garment(std::move(other)) //move constructor
    {
        other.garmentCode.clear();
        other.garmentColor.clear();
    }
    Skirt& operator=(Skirt&& other) noexcept //move assignment operator for Skirt
    {
        if (this != &other)
        {
            garmentCode = std::move(other.garmentCode);
            garmentColor = std::move(other.garmentColor);
            other.garmentCode.clear();
            other.garmentColor.clear();
        }
        return *this;
    }
};

class Pants : public Garment
{
public:
    Pants(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
    //interface implementing
    void describe() const override 
    {
        std::cout << "Pants: " << garmentCode << ", color: " << garmentColor << std::endl;
    }
    void describePants() const 
    {
        std::cout << "Pants: " << garmentCode << " " << garmentColor << std::endl;
    }
    void addedGarment() const override
    {
        std::cout << "Pants added successfully!" << std::endl;
    }
    void removedGarment() const override
    {
        std::cout << "Pants removed successfully!" << std::endl;
    }
    std::unique_ptr<Garment> clone() const override // Implementare metoda clone
    {
        return std::make_unique<Pants>(*this);
    }
    void setPants(const std::string& pantsName, const std::string colorName) //setter
    {
        garmentCode = pantsName;
        garmentColor = colorName;
    }
    Pants& operator=(const Pants& other) //operator=
    {
        if (this != &other)
        {
            garmentCode = other.garmentCode;
            garmentColor = other.garmentColor;
        }
        return *this;
    }
    Pants(const Pants& other): Garment(other) {} //constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Pants& p) //operator<<
    {
        os << "Pants: " << p.garmentCode << ", color: " << p.garmentColor;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Pants& p) //operator>>
    {
        std::cout << "Pants_code: ";
        is >> p.garmentCode;
        std::cout << "color: ";
        is >> p.garmentColor;
        return is;
    }
    Pants(Pants&& other) noexcept: Garment(std::move(other)) //move constructor
    {
        other.garmentCode.clear();
        other.garmentColor.clear();
    }
    Pants& operator=(Pants&& other) noexcept //move assignment operator for Pants
    {
        if (this != &other)
        {
            garmentCode = std::move(other.garmentCode);
            garmentColor = std::move(other.garmentColor);
            other.garmentCode.clear();
            other.garmentColor.clear();
        }
        return *this;
    }
};

class AlreadyAddedGarment: public std::runtime_error
{
public:
    AlreadyAddedGarment(const std::string& message): std::runtime_error(message) {}
};

class NonExistentGarment: public std::invalid_argument
{
public:
    NonExistentGarment(const std::string& message): std::invalid_argument(message) {}
};

class NothingToRemove: public std::logic_error
{
public:
    NothingToRemove(const std::string& message): std::logic_error(message) {}
};

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
    Barbie(): currentBlouse(nullptr), currentDress(nullptr), currentSkirt(nullptr), currentPants(nullptr) {}
    void addGarment(std::unique_ptr<Garment> g, const std::string& errorMessage) 
    {
        for (const auto& garment : garments) 
            if (garment->isSameType(*g)) 
                throw AlreadyAddedGarment(errorMessage);
        garments.push_back(std::move(g));
        garmentCount++;
        numberOfChanges++;
    }
    void addBlouse(std::unique_ptr<Blouse> blouse) 
    {
        addGarment(std::move(blouse), "blouse already added!");
        if (!garments.empty()) 
            garments.back()->addedGarment();
    }
    void addDress(std::unique_ptr<Dress> dress) 
    {
        addGarment(std::move(dress), "dress already added!");
        if (!garments.empty()) 
            garments.back()->addedGarment();
    }
    void addSkirt(std::unique_ptr<Skirt> skirt) 
    {
        addGarment(std::move(skirt), "skirt already added!");
        if (!garments.empty()) 
            garments.back()->addedGarment();
    }
    void addPants(std::unique_ptr<Pants> pants) 
    {
        addGarment(std::move(pants), "pants already added!");
        if (!garments.empty()) 
            garments.back()->addedGarment();
    }

    template <typename T>
    void removeGarment(const std::string& errorMessage) 
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
    void removeBlouse() 
    {
        removeGarment<Blouse>("There is no blouse to remove!");
    }
    void removeDress() 
    {
        removeGarment<Dress>("There is no dress to remove!");
    }
    void removeSkirt() 
    {
        removeGarment<Skirt>("There is no skirt to remove!");
    }
    void removePants()
    {
        removeGarment<Pants>("There are no pants to remove!");
    }
    static int GetGarmentCount(void)
    {
        return garmentCount;
    }
    static void ViewChanges()
    {
        if (numberOfChanges == 0)
            std::cout << "You haven't changed Barbie's look yet." << std::endl;
        else if (numberOfChanges == 1)  
            std::cout << "You've made " << numberOfChanges << " change at Barbie's look so far." << std::endl;
        else std::cout << "You've made " << numberOfChanges << " changes at Barbie's look so far." << std::endl;
    }
};

int Barbie::garmentCount = 0;
int Barbie::numberOfChanges = 0;

//using interface
void describe_garment(const Garment& clothing)
{
    clothing.describe();
}
void checkNumber(int x)
{
    if (x != 1 and x != 2 and x != 3 and x != 4)
        throw NonExistentGarment("Non-existent item!");
}

void Display(const Barbie& myBarbie)
{
    const int numberOfClothes = Barbie::GetGarmentCount();
    if (numberOfClothes == 0)
        std::cout << "Barbie isn' wearing anything at the moment." << std::endl;
    else if (numberOfClothes == 1)
        std::cout << "Barbie is wearing 1 piece of clothing at the moment." << std::endl;
    else std::cout << "Barbie is wearing " << numberOfClothes << " pieces of clothing at the moment." << std::endl;
    if (numberOfClothes != 0)
        std::cout << "Barbie is wearing:\n";
}

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