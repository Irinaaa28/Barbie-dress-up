#ifndef WARDROBE_H
#define WARDROBE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

class Wardrobe //interface definition
{
public:
    //pure virtual functions
    virtual void describe() const = 0;
    virtual std::string getCode() const  = 0;//getter code
    virtual std::string getColor() const  = 0;//getter color
};

#endif // WARDROBE_H