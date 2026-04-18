#pragma once

#include <string>

#include <ComplexNumber.h>

namespace mw {

class ComplexParser {
public:
    ComplexNumber operator () (const std::string& str);

private:
    std::string removeSpaces(const std::string& str);
    bool readSign(const std::string& str, char& sign);
    double readReal(const std::string& realStr, const char sign);
    double readImag(const std::string& imagStr, const char sign);
    bool isNumber(const char token);
};

} // mw