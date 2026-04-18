#pragma once

#include <string>

namespace mw {

class RpnNotationConverter {
public:
    std::string operator() (const std::string& expression);

private:
    bool isNumber(const char token);
    unsigned precedence(const char token);
};

} // mw