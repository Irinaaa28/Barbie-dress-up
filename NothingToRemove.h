#ifndef NOTHING_TO_REMOVE_H
#define NOTHING_TO_REMOVE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

class NothingToRemove : public std::logic_error 
{
public:
    NothingToRemove(const std::string& message);
};

#endif // NOTHING_TO_REMOVE_H