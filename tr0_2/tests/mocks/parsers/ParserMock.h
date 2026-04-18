#pragma once

#include <gmock/gmock.h>

#include <NumberParser.h>

#include <numbers/NumberMock.h>

namespace mocks {

class ParserMock : public mw::NumberParser<NumberMock, ParserMock> {
public:
    NumberMock parse(const std::string& str, std::function<int(int)> isNumber);
};

} // mocks