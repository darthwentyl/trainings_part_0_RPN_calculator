#pragma once

namespace mw {

template<typename T>
class ComplexNumber {
public:
    ComplexNumber(const T& re, const T& im);

    T real() const;
    T imag() const;

    T abs() const;
    T arg() const;

    ComplexNumber<T> operator + (const ComplexNumber<T>& num) const;
    ComplexNumber<T> operator - (const ComplexNumber<T>& num) const;
    ComplexNumber<T> operator * (const ComplexNumber<T>& num) const;
    ComplexNumber<T> operator / (const ComplexNumber<T>& num) const;

    friend std::ostream& operator << (std::ostream& os, const ComplexNumber<T>& num) {
        os << num.re
           << (num.im < 0 ? " - " : " + ")
           << (num.im < 0 ? -num.im : num.im)
           << "i";
        return os;

    }

private:
    T re;
    T im;
};

} // mw

#include "ComplexNumber.tpp"