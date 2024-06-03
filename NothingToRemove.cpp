#include "NothingToRemove.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>
#include <variant>
#include <memory>
#include <algorithm>

NothingToRemove::NothingToRemove(const std::string& message) : std::logic_error(message) {}