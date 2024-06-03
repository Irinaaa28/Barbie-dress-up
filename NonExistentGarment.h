#ifndef NON_EXISTENT_GARMENT_H
#define NON_EXISTENT_GARMENT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

class NonExistentGarment : public std::invalid_argument 
{
public:
    NonExistentGarment(const std::string& message);
};

#endif // NON_EXISTENT_GARMENT_H