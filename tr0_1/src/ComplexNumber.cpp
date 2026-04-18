#include <ComplexNumber.h>

#include <cmath>
#include <stdexcept>

namespace mw {

double ComplexNumber::real() const {
    return this->re;
}

double ComplexNumber::imag() const {
    return this->im;
}

double ComplexNumber::abs() const {
    return std::sqrt(std::pow(this->re, 2) + std::pow(this->im, 2));
}

double ComplexNumber::arg() const {
    const double absVal = this->abs();
    if (absVal == 0) {
        throw std::invalid_argument("ERROR: argument for 0 + 0i is not defined");
    }
    const double sin = this->im / absVal;
    const double cos = this->re / absVal;

    if ((sin >= 0 && cos >= 0) || (sin < 0 && cos >= 0)) { // First & fourth quarter
        return asin(sin);
    } else if (sin >= 0 && cos < 0) { // Second quarter
        return acos(cos);
    } else if (sin < 0 && cos < 0) { // Third quarter
        return atan(this->im / this->re) - M_PI;
    }

    return 0.0;
}

ComplexNumber::ComplexNumber(const double& re, const double& im)
: re{re}
, im{im}
{}

ComplexNumber ComplexNumber::operator + (const ComplexNumber& num) const {
    return ComplexNumber{this->re + num.re, this->im + num.im};
}

ComplexNumber ComplexNumber::operator - (const ComplexNumber& num) const {
    return ComplexNumber{this->re - num.re, this->im - num.im};
}

ComplexNumber ComplexNumber::operator * (const ComplexNumber& num) const {
    ComplexNumber result{ 0.0, 0.0 };
    result.re = this->re * num.re - this->im * num.im;
    result.im = this->re * num.im + this->im * num.re;
    return result;
}

ComplexNumber ComplexNumber::operator / (const ComplexNumber& num) const {
    double re = 0.0;
    double im = 0.0;

    const double thisAbs = this->abs();
    if (thisAbs != 0) {
        const double thisArg = this->arg();

        try {
            const double numAbs = num.abs();
            const double numArg = num.arg();

            re = thisAbs / numAbs * std::cos(thisArg - numArg);
            im = thisAbs / numAbs * std::sin(thisArg - numArg);
        } catch(const std::invalid_argument& e) {
            throw std::invalid_argument("ERROR: Division by 0 + 0j is not allowed");
        }
    }

    return ComplexNumber{ re, im };
}

} // mw