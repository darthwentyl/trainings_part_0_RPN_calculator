#pragma once

namespace mw {

class ComplexNumber {
public:
    ComplexNumber(const double& re, const double& im);

    double real() const;
    double imag() const;

    double abs() const;
    double arg() const;

    ComplexNumber operator + (const ComplexNumber& num) const;
    ComplexNumber operator - (const ComplexNumber& num) const;
    ComplexNumber operator * (const ComplexNumber& num) const;
    ComplexNumber operator / (const ComplexNumber& num) const;

private:
    double re;
    double im;
};

} // mw
