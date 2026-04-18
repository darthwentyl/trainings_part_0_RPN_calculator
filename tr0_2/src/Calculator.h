#pragma once

#include <functional>
#include <cctype>
#include <string>

namespace mw {

template<class NUM_T, class PARSER_T>
class Calculator {
public:
    NUM_T operator() (const std::string& expression, std::function<int(int)> isNumber);

private:
    std::string toRpn(const std::string& expression, std::function<int(int)> isNumber);
    NUM_T performOperation(const NUM_T& num1, const NUM_T& num2, char op);
};

} // mw

#include "Calculator.tpp"