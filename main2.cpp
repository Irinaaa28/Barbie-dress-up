#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
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
    //implementing some functions from interface
    std::string getCode() const override
    {
        return garmentCode;
    }
    std::string getColor() const override
    {
        return garmentColor;
    }
    bool isSameColor(const Garment& other) const
    {
        return garmentColor == other.garmentColor;
    }
    bool isSameType(const Garment& other) const
    {
        return typeid(*this) == typeid(other);
    }
    ~Garment() {}
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
    Blouse& operator=(const Blouse& other) //operator=
    {
        if(this != &other)
        {
            garmentCode = other.garmentCode;
            garmentColor = other.garmentColor;
        }
        return *this;
    } 
    Blouse(const Blouse& other): Garment(other) {} // Constructor de copiere
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
    ~Blouse() = default;
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
    ~Dress() = default;
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
    ~Skirt() = default;
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
    ~Pants() = default;
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
    static int garmentCount;
    static int numberOfChanges;
public:
    Barbie(): currentBlouse(nullptr), currentDress(nullptr), currentSkirt(nullptr), currentPants(nullptr) {}
    template<typename T>
    void addGarment(T*& currentGarment, const T& garment, const std::string& errorMessage)
    {
        if (currentGarment)
            throw AlreadyAddedGarment(errorMessage);
        currentGarment = new T(garment);
        garmentCount++;
        numberOfChanges++;
        currentGarment->addedGarment();
    }
    void addBlouse(const Blouse& blouse)
    {
        addGarment(currentBlouse, blouse, "blouse already added!");
    }
    void addDress(const Dress& dress)
    {
        addGarment(currentDress, dress, "dress already added!");
    }
    void addSkirt(const Skirt& skirt)
    {
        addGarment(currentSkirt, skirt, "skirt already added!");
    }
    void addPants(const Pants& pants)
    {
        addGarment(currentPants, pants, "pants already added!");
    }

    template<typename T>
    void removeGarment(T*& currentGarment, const std::string& errorMessage)
    {
        if (!currentGarment)
            throw NothingToRemove(errorMessage);
        else
        {
            currentGarment->removedGarment();
            delete currentGarment;
            currentGarment = nullptr;
            garmentCount--;
            numberOfChanges++;
        }
    }
    void removeBlouse()
    {
        removeGarment(currentBlouse, "There is no blouse to remove!");
    }
    void removeDress()
    {
        removeGarment(currentDress, "There is no dress to remove!");
    }
    void removeSkirt()
    {
        removeGarment(currentSkirt, "There is no skirt to remove!");
    }
    void removePants()
    {
        removeGarment(currentPants, "There are no pants to remove!");
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
    ~Barbie()
    {
        delete currentBlouse;
        delete currentDress;
        delete currentSkirt;
        delete currentPants;
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

template <typename T>
void removeFromOutfit(std::vector<Garment*>& outfit)
{
    for (auto it = outfit.begin(); it != outfit.end(); ++it)
    {
        if (dynamic_cast<T*>(*it) != nullptr)
        {
            delete *it; 
            outfit.erase(it);
            return; 
        }
    }
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
    Blouse blouse1("#BT1CR", "Red"), blouse2("#BT1CB", "Blue"), blouse3("#BT1CG", "Green"), blouse4("#BT1CY", "Yellow");
    Dress dress1("#DT1CR", "Red"), dress2("#DT1CB", "Blue"), dress3("#DT1CG", "Green"), dress4("#DT1CY", "Yellow");
    Skirt skirt1("#ST1CR", "Red"), skirt2("#ST1CB", "Blue"), skirt3("#ST1CG", "Green"), skirt4("#ST1CY", "Yellow");
    Pants pants1("#PT1CR", "Red"), pants2("#PT1CB", "Blue"), pants3("#PT1CG", "Green"), pants4("#PT1CY", "Yellow");

    std::vector<Garment*> outfit;
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
                        describe_garment(blouse1);
                        describe_garment(blouse2);
                        describe_garment(blouse3);
                        describe_garment(blouse4);
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
                        {
                            myBarbie.addBlouse(blouse1);
                            outfit.push_back(new Blouse(blouse1.getCode(), blouse1.getColor()));
                        }
                        else if (numberBlouse == 2)
                        {
                            myBarbie.addBlouse(blouse2);
                            outfit.push_back(new Blouse(blouse2.getCode(), blouse2.getColor()));
                        }
                        else if (numberBlouse == 3)
                        {
                            myBarbie.addBlouse(blouse3);
                            outfit.push_back(new Blouse(blouse3.getCode(), blouse3.getColor()));
                        }
                        else if (numberBlouse == 4)
                        {
                            myBarbie.addBlouse(blouse4);
                            outfit.push_back(new Blouse(blouse4.getCode(), blouse4.getColor()));
                        }  
                    }  
                    else if (toLower(addGarmentType) == "dress")
                    {
                        int numberDress;
                        std::cout << "Add a dress code and a dress color from the wardrobe:\n";
                        describe_garment(dress1);
                        describe_garment(dress2);
                        describe_garment(dress3);
                        describe_garment(dress4);
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
                        {
                            myBarbie.addDress(dress1);
                            outfit.push_back(new Dress(dress1.getCode(), dress1.getColor()));
                        }
                        else if (numberDress == 2)
                        {
                            myBarbie.addDress(dress2);
                            outfit.push_back(new Dress(dress2.getCode(), dress2.getColor()));
                        }
                        else if (numberDress == 3)
                        {
                            myBarbie.addDress(dress3);
                            outfit.push_back(new Dress(dress3.getCode(), dress3.getColor()));
                        }
                        else if (numberDress == 4)
                        {
                            myBarbie.addDress(dress4);
                            outfit.push_back(new Dress(dress4.getCode(), dress4.getColor()));
                        }
                    }
                    else if (toLower(addGarmentType) == "skirt")
                    {
                        int numberSkirt;
                        std::cout << "Add a skirt code and a skirt color from the wardrobe:\n";
                        describe_garment(skirt1);
                        describe_garment(skirt2);
                        describe_garment(skirt3);
                        describe_garment(skirt4);
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
                        {
                            myBarbie.addSkirt(skirt1);
                            outfit.push_back(new Skirt(skirt1.getCode(), skirt1.getColor()));
                        }
                        else if (numberSkirt == 2)
                        {
                            myBarbie.addSkirt(skirt2);
                            outfit.push_back(new Skirt(skirt2.getCode(), skirt2.getColor()));
                        }
                        else if (numberSkirt == 3)
                        {
                            myBarbie.addSkirt(skirt3);
                            outfit.push_back(new Skirt(skirt3.getCode(), skirt3.getColor()));
                        }
                        else if (numberSkirt == 4)
                        {
                            myBarbie.addSkirt(skirt4);
                            outfit.push_back(new Skirt(skirt4.getCode(), skirt4.getColor()));
                        }
                    }
                    else if (toLower(addGarmentType) == "pants")
                    {
                        int numberPants;
                        std::cout << "Add a pants code and a pants color from the wardrobe:\n";
                        describe_garment(pants1);
                        describe_garment(pants2);
                        describe_garment(pants3);
                        describe_garment(pants4);
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
                        {
                            myBarbie.addPants(pants1);
                            outfit.push_back(new Pants(pants1.getCode(), pants1.getColor()));
                        }
                        else if (numberPants == 2)
                        {
                            myBarbie.addPants(pants2);
                            outfit.push_back(new Pants(pants2.getCode(), pants2.getColor()));
                        }
                        else if (numberPants == 3)
                        {
                            myBarbie.addPants(pants3);
                            outfit.push_back(new Pants(pants3.getCode(), pants3.getColor()));
                        }
                        else if (numberPants == 4)
                        {
                            myBarbie.addPants(pants4);
                            outfit.push_back(new Pants(pants4.getCode(), pants4.getColor()));
                        }
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
                    {
                        myBarbie.removeBlouse();
                        removeFromOutfit<Blouse>(outfit);
                    }
                    else if (toLower(removeGarmentType) == "dress")
                    {
                        myBarbie.removeDress();
                        removeFromOutfit<Dress>(outfit);
                    }
                    else if (toLower(removeGarmentType) == "skirt")
                    {
                        myBarbie.removeSkirt();
                        removeFromOutfit<Skirt>(outfit);
                    }
                    else if (toLower(removeGarmentType) == "pants")
                    {
                        myBarbie.removePants();  
                        removeFromOutfit<Pants>(outfit);
                    }
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
    for (Garment *cloth : outfit)
    {
       if (Blouse* blouse = dynamic_cast<Blouse*>(cloth))
            blouse->describeBlouse();
        else if (Dress* dress = dynamic_cast<Dress*>(cloth))
            dress->describeDress();
        else if (Skirt* skirt = dynamic_cast<Skirt*>(cloth))
            skirt->describeSkirt();
        else if (Pants* pants = dynamic_cast<Pants*>(cloth))
            pants->describePants();
    }
    std::cout << "That's the end of the game!" << std::endl;
    return 0;
}