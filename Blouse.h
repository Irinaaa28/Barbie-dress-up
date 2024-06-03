#ifndef BLOUSE_H
#define BLOUSE_H

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

class Blouse : public Garment
{
public:
    Blouse(const std::string& garmentCode, const std::string& garmentColor);
    //interface implementing 
    void describe() const override;
    void describeBlouse() const;
    void addedGarment() const override;
    void removedGarment() const override;
    void setBlouse(const std::string& blouseName, const std::string& colorName); //setter
    std::unique_ptr<Garment> clone() const override; 
    Blouse& operator=(const Blouse& other); //operator=
    Blouse(const Blouse& other); // Constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Blouse& b); //operator<<
    friend std::istream& operator>>(std::istream& is, Blouse& b); //operator>>
    Blouse(Blouse&& other) noexcept; //move constructor
    Blouse& operator=(Blouse&& other) noexcept; //move assignment operator for Blouse
};
#endif // BLOUSE_H