#ifndef SKIRT_H
#define SKIRT_H

#include "Garment.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

class Skirt : public Garment
{
public:
    Skirt(const std::string& garmentCode, const std::string& garmentColor);
    //interface implementing
    void describe() const override;
    void describeSkirt() const;
    void addedGarment() const override;
    void removedGarment() const override;
    void setSkirt(const std::string& skirtName, const std::string& colorName);//setter
    std::unique_ptr<Garment> clone() const override; 
    Skirt& operator=(const Skirt& other); //operator=
    Skirt(const Skirt& other); //constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Skirt& s); //operator<<
    friend std::istream& operator>>(std::istream& is, Skirt& s); //operator>>
    Skirt(Skirt&& other) noexcept; //move constructor
    Skirt& operator=(Skirt&& other) noexcept; //move assignment operator for Skirt
};

#endif // SKIRT_H