#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

#include "Barbie.h"
#include "AlreadyAddedGarment.h"
#include "NonExistentGarment.h"
#include "NothingToRemove.h"

std::string toLower(const std::string& str);
void describe_garment(const Garment& clothing);
void checkNumber(int x);
void Display(const Barbie& myBarbie);

#endif //OTHER_FUNCTIONS_H