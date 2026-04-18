#include <ComplexParser.h>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

namespace {

constexpr char PLUS = '+';
constexpr char MINUS = '-';
constexpr char IMAG = 'i';

} // anonymous

namespace mw {

ComplexNumber ComplexParser::operator () (const std::string& str) {
    double re = 0.0;
    double im = 0.0;
    std::vector<std::string> elems;

    for (std::string::size_type pos = 0; pos < str.length(); pos++) {
        char token = str[pos];
        if (std::isspace(token)) {
            continue;
        } else if(isNumber(token)) {
            std::stringstream ss;
            while (pos < str.length() && isNumber(str[pos])) {
                ss << str[pos++];
            }
            elems.push_back(ss.str());
        } else if (str[pos] == PLUS || str[pos] == MINUS) {
            elems.push_back(std::string(1, str[pos]));
        }
    }

    char sign = '\0';
    for (const auto& iter : elems) {
        if (readSign(iter, sign)) {
            continue;
        }
        if (iter.find(IMAG) != std::string::npos) {
            im = readImag(iter, sign);
        } else {
            re = readReal(iter, sign);
        }
    }

    return ComplexNumber{re, im};
}

bool ComplexParser::readSign(const std::string& str, char& sign) {
    bool success = false;
    if (str.compare(std::string(1, PLUS)) == 0) {
        sign = PLUS;
        success = true;
    } else if (str.compare(std::string(1, MINUS)) == 0) {
        sign = MINUS;
        success = true;
    }
    return success;
}

double ComplexParser::readReal(const std::string& realStr, const char sign) {
    std::istringstream iss{realStr};
    double real = 0.0;
    iss >> real;
    return sign == MINUS ? -real : real;
}

double ComplexParser::readImag(const std::string& imagStr, const char sign) {
    if (imagStr.length() == 1) {
        return sign == MINUS ? -1.0 : 1.0;
    }
    std::istringstream iss{imagStr};
    double imag = 0.0;
    char i = '\0';
    iss >> imag >> i;
    return sign == MINUS ? -imag : imag;
}

bool ComplexParser::isNumber(const char token) {
    return std::isdigit(token) || token == 'i' || token == '.';
}

} // mw