
#pragma once

namespace mocks {

class NumberMock {
public:
    NumberMock(const int val);

    NumberMock operator + (const NumberMock& other) const;
    NumberMock operator - (const NumberMock& other) const;

    NumberMock operator * (const NumberMock& other) const;

    NumberMock operator / (const NumberMock& other) const;

    bool operator == (int compNum) const;

private:
    int val;
};

} // mocks