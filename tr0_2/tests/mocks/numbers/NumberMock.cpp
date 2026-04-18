#include <numbers/NumberMock.h>
#include <numbers/NumberStaticMock.h>

namespace mocks {

NumberMock::NumberMock(const int val) :
    val(val)
{}

NumberMock NumberMock::operator + (const NumberMock& other) const {
    return NumberMock{
        NumberStaticMock::getInstance().plus(this->val, other.val)
    };
}

NumberMock NumberMock::operator - (const NumberMock& other) const {
    return NumberMock {
        NumberStaticMock::getInstance().minus(this->val, other.val)
    };
}

NumberMock NumberMock::operator * (const NumberMock& other) const {
    return NumberMock{
        NumberStaticMock::getInstance().multi(this->val, other.val)
    };
}

NumberMock NumberMock::operator / (const NumberMock& other) const {
    return NumberMock{
        NumberStaticMock::getInstance().div(this->val, other.val)
    };
}

bool NumberMock::operator == (int compNum) const {
    return this->val == compNum;
}

} // mocks