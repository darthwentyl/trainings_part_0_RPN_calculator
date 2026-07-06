#ifndef MYHEXPARSER_H
#define MYHEXPARSER_H

#include <functional>

#include <myhex.h>

class MyHexParser
{
public:
    MyHex parse(const std::string& str, std::function<int(int)> isNumber);
};

#endif // MYHEXPARSER_H
