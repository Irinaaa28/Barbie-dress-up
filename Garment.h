#ifndef GARMENT_H
#define GARMENT_H

#include "Wardrobe.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

class Garment : public Wardrobe //abstract class
{
protected:
    std::string garmentCode;
    std::string garmentColor;
public:
    Garment(const std::string& garmentCode, const std::string& garmentColor); //constructor
    //pure virtual functions
    virtual void describe() const = 0;
    virtual void addedGarment() const = 0;
    virtual void removedGarment() const = 0;
    virtual std::unique_ptr<Garment> clone() const = 0;
    //implementing some functions from interface
    std::string getCode() const override;
    std::string getColor() const override;
    bool isSameType(const Garment& other) const;
    virtual ~Garment() = default;
};

#endif // GARMENT_H