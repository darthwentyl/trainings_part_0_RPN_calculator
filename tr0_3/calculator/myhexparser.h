#ifndef MYHEXPARSER_H
#define MYHEXPARSER_H

#include <functional>

#include <Calculator.h>
#include <myhex.h>

class MyHexParser : public mw::NumberParser<MyHex, MyHexParser>
{
public:
    MyHex parse(const std::string& str, std::function<int(int)> isNumber);
};

#endif // MYHEXPARSER_H
