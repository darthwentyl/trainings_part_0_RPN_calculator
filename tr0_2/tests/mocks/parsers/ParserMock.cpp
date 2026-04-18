#include <parsers/ParserMock.h>
#include <parsers/ParserStaticMock.h>

namespace mocks {

NumberMock ParserMock::parse(const std::string& str, std::function<int(int)> isNumber) {
    return ParserStaticMock::getInstance().parse(str, isNumber);
};

}