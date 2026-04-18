#pragma once

#include <ComplexNumber.h>

#include <string>

namespace mw {

class ComplexCalculator {
public:
    ComplexNumber operator() (const std::string& expression);

private:
    std::string toRpn(const std::string& expression);
    bool isNumber(const std::string& token);
    ComplexNumber performOperation(const ComplexNumber& num1, const ComplexNumber& num2, const char op);
};

} // mw