#include <iostream>

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
    {
        if (this != &other)
        {
            garmentCode = other.garmentCode;
            garmentColor = other.garmentColor;
        }
        return *this;
    }
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

int main()
{
    return 0;
}