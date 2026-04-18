#pragma once

#include <functional>
#include <cctype>
#include <string>

namespace mw {

class RpnNotationConverter {
public:
    std::string operator() (const std::string& expression, std::function<int(int)> isNumber = static_cast<int(*)(int)>(std::isdigit));

private:
    unsigned precedence(const char token);
};

} // mw