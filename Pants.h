#ifndef PANTS_H
#define PANTS_H

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

class Pants : public Garment
{
public:
    Pants(const std::string& garmentCode, const std::string& garmentColor);
    //interface implementing
    void describe() const override; 
    void describePants() const; 
    void addedGarment() const override;
    void removedGarment() const override;
    std::unique_ptr<Garment> clone() const override; 
    void setPants(const std::string& pantsName, const std::string colorName); //setter
    Pants& operator=(const Pants& other); //operator=
    Pants(const Pants& other);//constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Pants& p); //operator<<
    friend std::istream& operator>>(std::istream& is, Pants& p); //operator>>
    Pants(Pants&& other) noexcept; //move constructor
    Pants& operator=(Pants&& other) noexcept; //move assignment operator for Pants
};

#endif // PANTS_H