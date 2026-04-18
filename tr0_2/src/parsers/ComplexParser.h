#pragma once

#include <string>
#include <functional>
#include <cctype>

#include <numbers/ComplexNumber.h>
#include <NumberParser.h>

namespace mw {


template<class NUM_T>
class ComplexParser : public NumberParser<
        ComplexNumber<NUM_T>,
        ComplexParser<NUM_T>
    > {
public:
    ComplexNumber<NUM_T> parse (const std::string& str, std::function<int(int)> isNumber = static_cast<int(*)(int)>(std::isdigit));

private:
    std::string removeSpaces(const std::string& str);
    bool readSign(const std::string& str, char& sign);
    NUM_T readReal(const std::string& realStr, const char sign);
    NUM_T readImag(const std::string& imagStr, const char sign);
};

} // mw

#include "ComplexParser.tpp"