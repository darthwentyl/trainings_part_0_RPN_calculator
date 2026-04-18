#pragma once

#include <gmock/gmock.h>

namespace mocks {

class NumberStaticMock {
public:
    virtual ~NumberStaticMock() = default;

    NumberStaticMock(const NumberStaticMock&) = delete;
    NumberStaticMock(NumberStaticMock&&) = delete;
    NumberStaticMock& operator = (const NumberStaticMock&) = delete;
    NumberStaticMock& operator = (NumberStaticMock&&) = delete;

    static NumberStaticMock& getInstance() {
        static NumberStaticMock instance;
        return instance;
    }

    MOCK_CONST_METHOD2(plus, int(const int, const int));
    MOCK_CONST_METHOD2(minus, int(const int, const int));
    MOCK_CONST_METHOD2(multi, int(const int, const int));
    MOCK_CONST_METHOD2(div, int(const int, const int));

private:
    NumberStaticMock() = default;
};

} // mocks