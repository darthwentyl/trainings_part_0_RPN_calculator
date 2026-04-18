#pragma once

#include <functional>

#include <numbers/MyInt.h>
#include <NumberParser.h>

namespace mw {

class MyIntParser : public NumberParser<MyInt, MyIntParser> {
public:
    MyInt parse(const std::string& str, std::function<int(int)> isNumber);
};

} // mw
