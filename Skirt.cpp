#include "Skirt.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

Skirt::Skirt(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
//interface implementing
void Skirt::describe() const 
{
    std::cout << "Skirt: " << garmentCode << ", color: " << garmentColor << std::endl;
}
void Skirt::describeSkirt() const
{
    std::cout << "A skirt: " << garmentCode << " " << garmentColor << std::endl;
}
void Skirt::addedGarment() const 
{
    std::cout << "Skirt added successfully!" << std::endl;
}
void Skirt::removedGarment() const 
{
    std::cout << "Skirt removed successfully!" << std::endl;
}
void Skirt::setSkirt(const std::string& skirtName, const std::string& colorName) //setter
{
    garmentCode = skirtName;
    garmentColor = colorName;
}
std::unique_ptr<Garment> Skirt::clone() const 
{
    return std::make_unique<Skirt>(*this);
}
Skirt& Skirt::operator=(const Skirt& other) //operator=
{
    if (this != &other)
    {
        garmentCode = other.garmentCode;
        garmentColor = other.garmentColor;
    }
    return *this;
}
Skirt::Skirt(const Skirt& other): Garment(other) {} //constructor de copiere
std::ostream& operator<<(std::ostream& os, const Skirt& s) //operator<<
{
    os << "Skirt: " << s.garmentCode << ", color: " << s.garmentColor;
    return os;
}
std::istream& operator>>(std::istream& is, Skirt& s) //operator>>
{
    std::cout << "Skirt_code: ";
    is >> s.garmentCode;
    std::cout << "color: ";
    is >> s.garmentColor;
    return is;
}
Skirt::Skirt(Skirt&& other) noexcept: Garment(std::move(other)) //move constructor
{
    other.garmentCode.clear();
    other.garmentColor.clear();
}
Skirt& Skirt::operator=(Skirt&& other) noexcept //move assignment operator for Skirt
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