#pragma once

#include <cmath>
#include <stdexcept>

namespace mw {

template<typename T>
T ComplexNumber<T>::real() const {
    return this->re;
}

template<typename T>
T ComplexNumber<T>::imag() const {
    return this->im;
}

template<typename T>
T ComplexNumber<T>::abs() const {
    return std::sqrt(std::pow(this->re, 2) + std::pow(this->im, 2));
}

template<typename T>
T ComplexNumber<T>::arg() const {
    const T absVal = this->abs();
    if (absVal == 0) {
        throw std::invalid_argument("ERROR: argument for 0 + 0j is not defined");
    }
    const T sin = this->im / absVal;
    const T cos = this->re / absVal;

    if ((sin >= 0 && cos >= 0) || (sin < 0 && cos >= 0)) { // First & fourth quarter
        return asin(sin);
    } else if (sin >= 0 && cos < 0) { // Second quarter
        return acos(cos);
    } else if (sin < 0 && cos < 0) { // Third quarter
        return atan(this->im / this->re) - M_PI;
    }

    return T{};
}

template<typename T>
ComplexNumber<T>::ComplexNumber(const T& re, const T& im)
: re{re}
, im{im}
{}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::operator + (const ComplexNumber<T>& num) const {
    return ComplexNumber<T>{this->re + num.re, this->im + num.im};
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::operator - (const ComplexNumber<T>& num) const {
    return ComplexNumber<T>{this->re - num.re, this->im - num.im};
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::operator * (const ComplexNumber<T>& num) const {
    ComplexNumber<T> result{ T{}, T{} };
    result.re = this->re * num.re - this->im * num.im;
    result.im = this->re * num.im + this->im * num.re;
    return result;
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::operator / (const ComplexNumber<T>& num) const {
    T re = T{};
    T im = T{};

    const T thisAbs = this->abs();
    if (thisAbs != 0) {
        const T thisArg = this->arg();

        try {
            const T numAbs = num.abs();
            const T numArg = num.arg();

            re = thisAbs / numAbs * std::cos(thisArg - numArg);
            im = thisAbs / numAbs * std::sin(thisArg - numArg);
        } catch(const std::invalid_argument& e) {
            throw std::invalid_argument("ERROR: Division by 0 + 0j is not allowed");
        }
    }

    return ComplexNumber<T>{ re, im };
}

} // mw