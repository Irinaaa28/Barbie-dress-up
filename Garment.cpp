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

Garment::Garment(const std::string& garmentCode, const std::string& garmentColor) : garmentCode(garmentCode), garmentColor(garmentColor) {}

std::string Garment::getCode() const 
{
    return garmentCode;
}

std::string Garment::getColor() const 
{
    return garmentColor;
}

bool Garment::isSameType(const Garment& other) const 
{
    return typeid(*this) == typeid(other);
}

