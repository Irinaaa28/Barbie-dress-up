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
    virtual void garment_type() const = 0;
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
    virtual void garment_type() const = 0;
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
    void garment_type() const override
    {
        std::cout << "A blouse: " << std::endl;
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
    Blouse& operator=(const Blouse&) = delete; //operator=
    Blouse(const Blouse&) = delete;// Constructor de copiere
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
    void garment_type() const override
    {
        std::cout << "A dress" << std::endl;
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
    Dress& operator=(const Dress&) = delete;//operator=
    Dress(const Dress&) = delete; //constructor de copiere
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
    void garment_type() const override
    {
        std::cout << "A skirt" << std::endl;
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
    Skirt& operator=(const Skirt&) = delete;//operator=
    Skirt(const Skirt&) = delete;//constructor de copiere
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
    void garment_type() const override
    {
        std::cout << "Pants" << std::endl;
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
    Pants& operator=(const Pants&) = delete;//operator=
    Pants(const Pants&) = delete; //constructor de copiere
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
    std::unique_ptr<Blouse> currentBlouse;
    std::unique_ptr<Dress> currentDress;
    std::unique_ptr<Skirt> currentSkirt;
    std::unique_ptr<Pants> currentPants;
    static int garmentCount;
    static int numberOfChanges;
public:
    Barbie(): currentBlouse(nullptr), currentDress(nullptr), currentSkirt(nullptr), currentPants(nullptr) {}
    template <typename T>
    void addGarment(std::unique_ptr<T> garment) 
    {
        if (typeid(T) == typeid(Blouse)) 
        {
            if (currentBlouse)
                throw AlreadyAddedGarment("Blouse already added!");
            currentBlouse = std::move(garment);
        } else if (typeid(T) == typeid(Dress)) 
        {
            if (currentDress)
                throw AlreadyAddedGarment("Dress already added!");
            currentDress = std::move(garment);
        } else if (typeid(T) == typeid(Skirt)) 
        {
            if (currentSkirt)
                throw AlreadyAddedGarment("Skirt already added!");
            currentSkirt = std::move(garment);
        } else if (typeid(T) == typeid(Pants)) 
        {
            if (currentPants)
                throw AlreadyAddedGarment("Pants already added!");
            currentPants = std::move(garment);
        }
        garmentCount++;
        numberOfChanges++;
        garment->addedGarment();
    }
    template<typename T>
    void removeGarment() 
    {
        if (typeid(T) == typeid(Blouse)) 
        {
            if (!currentBlouse)
                throw NothingToRemove("There is no blouse to remove!");
            currentBlouse->removedGarment();
            currentBlouse.reset();
        } else if (typeid(T) == typeid(Dress)) 
        {
            if (!currentDress)
                throw NothingToRemove("There is no dress to remove!");
            currentDress->removedGarment();
            currentDress.reset();
        } else if (typeid(T) == typeid(Skirt)) 
        {
            if (!currentSkirt)
                throw NothingToRemove("There is no skirt to remove!");
            currentSkirt->removedGarment();
            currentSkirt.reset();
        } else if (typeid(T) == typeid(Pants)) 
        {
            if (!currentPants)
                throw NothingToRemove("There are no pants to remove!");
            currentPants->removedGarment();
            currentPants.reset();
        }
        garmentCount--;
        numberOfChanges++;
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

void checkNumber(int x)
{
    if (x != 1 and x != 2 and x != 3 and x != 4)
        throw NonExistentGarment("Non-existent item!");
}

template <typename T> 
void RemoveFromOutfit(std::vector<Garment*>& outfit) 
{
    for (auto it = outfit.begin(); it != outfit.end(); ++it)
        if (dynamic_cast<T*>(*it) != nullptr)
        {
            outfit.erase(it);
            return;
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
    return 0;
}