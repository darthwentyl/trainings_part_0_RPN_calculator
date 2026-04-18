#pragma once

#include <gmock/gmock.h>

#include <numbers/NumberMock.h>

namespace mocks {

class ParserStaticMock {
public:
    virtual ~ParserStaticMock() = default;

    ParserStaticMock(const ParserStaticMock&) = delete;
    ParserStaticMock(ParserStaticMock&&) = delete;
    ParserStaticMock& operator = (const ParserStaticMock&) = delete;
    ParserStaticMock& operator = (ParserStaticMock&&) = delete;

    static ParserStaticMock& getInstance() {
        static ParserStaticMock instance;
        return instance;
    }

    MOCK_METHOD2(parse, NumberMock(const std::string&, std::function<int(int)>));

private:
    ParserStaticMock() = default;
};

} // mocks

