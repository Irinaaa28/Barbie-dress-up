#ifndef ALREADY_ADDED_GARMENT_H
#define ALREADY_ADDED_GARMENT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

class AlreadyAddedGarment : public std::runtime_error 
{
public:
    AlreadyAddedGarment(const std::string& message);
};

#endif // ALREADY_ADDED_GARMENT_H
