#include <parsers/MyIntParser.h>

#include <sstream>

namespace mw {

MyInt MyIntParser::parse(const std::string& str, std::function<int(int)> isNumber __attribute__((unused))) {
    if (str.empty()) {
        throw std::runtime_error("str cannot be empty");
    }
    std::stringstream ss(str);
    int number = 0;
    ss >> number;
    return MyInt{number};
}

} // mw