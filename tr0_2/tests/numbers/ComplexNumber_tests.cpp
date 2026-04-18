#include <gtest/gtest.h>

#include <numbers/ComplexNumber.h>

namespace {

using namespace mw;
using namespace testing;

constexpr double PRECISION = 0.001;

class ComplexNumber_tests : public Test {
protected:
    using Complex = ComplexNumber<double>;
};

TEST_F(ComplexNumber_tests, constructor) {
    const Complex complex{123.123, 456.456};

    EXPECT_EQ(complex.real(), 123.123);
    EXPECT_EQ(complex.imag(), 456.456);
}

TEST_F(ComplexNumber_tests, abs) {
    const Complex complex{123.123, 456.456};
    EXPECT_LT(std::fabs(complex.abs()) - 472.770, PRECISION);
}

TEST_F(ComplexNumber_tests, arg_1_quarter) {
    const Complex complex{1.0, 1.0};
    EXPECT_LT(std::fabs(complex.arg()) - 0.785, PRECISION);
}

TEST_F(ComplexNumber_tests, arg_2_quarter) {
    const Complex complex{-1.0, 1.0};
    EXPECT_LT(std::fabs(complex.arg()) - 2.356, PRECISION);
}

TEST_F(ComplexNumber_tests, arg_3_quarter) {
    const Complex complex{-1.0, -1.0};
    EXPECT_LT(std::fabs(complex.arg()) - 2.356, PRECISION);
}

TEST_F(ComplexNumber_tests, arg_4_quarter) {
    const Complex complex{1.0, -1.0};
    EXPECT_LT(std::fabs(complex.arg()) - 0.785, PRECISION);
}

TEST_F(ComplexNumber_tests, arg_throw_exception) {
    const Complex complex{0.0, 0.0};
    EXPECT_THROW({
        complex.arg();
    }, std::invalid_argument);
}

TEST_F(ComplexNumber_tests, operator_sum) {
    const Complex complex_1{1.1, 2.2};
    const Complex complex_2{3.3, 4.4};
    const Complex sum = complex_1 + complex_2;

    EXPECT_DOUBLE_EQ(sum.real(), 4.4);
    EXPECT_DOUBLE_EQ(sum.imag(), 6.6);
}

TEST_F(ComplexNumber_tests, operator_sub) {
    const Complex complex_1{4.4, 6.6};
    const Complex complex_2{3.3, 4.4};
    const Complex sub = complex_1 - complex_2;

    EXPECT_DOUBLE_EQ(sub.real(), 1.1);
    EXPECT_DOUBLE_EQ(sub.imag(), 2.2);
}

TEST_F(ComplexNumber_tests, operator_mult) {
    const Complex complex_1{1.1, 2.2};
    const Complex complex_2{3.3, 4.4};
    const Complex mult = complex_1 * complex_2;

    EXPECT_DOUBLE_EQ(mult.real(), -6.05);
    EXPECT_DOUBLE_EQ(mult.imag(), 12.1);
}

TEST_F(ComplexNumber_tests, operator_div) {
    const Complex complex_1{1.1, 2.2};
    const Complex complex_2{3.3, 4.4};
    const Complex div = complex_1 / complex_2;

    EXPECT_LT(std::fabs(div.real()) - 0.440, PRECISION);
    EXPECT_LT(std::fabs(div.imag()) - 0.080, PRECISION);
}

TEST_F(ComplexNumber_tests, operator_div_0_by_some) {
    const Complex complex_1{0.0, 0.0};
    const Complex complex_2{1.1, 2.2};
    const Complex div = complex_1 / complex_2;

    EXPECT_LT(std::fabs(div.real()) - 0.000, PRECISION);
    EXPECT_LT(std::fabs(div.real()) - 0.000, PRECISION);
}

TEST_F(ComplexNumber_tests, operator_div_by_0) {
    const Complex complex_1{1.1, 2.2};
    const Complex complex_2{0.0, 0.0};
    EXPECT_THROW({
        complex_1 / complex_2;
    }, std::invalid_argument);
}

TEST_F(ComplexNumber_tests, plus_re_plus_im) {
    const Complex complex{1.2, 3.4};
    std::stringstream ss;
    ss << complex;
    const std::string out = "1.2 + 3.4i";
    EXPECT_STREQ(out.c_str(), ss.str().c_str());
}

TEST_F(ComplexNumber_tests, plus_re_minus_im) {
    const Complex complex{1.2, -3.4};
    std::stringstream ss;
    ss << complex;
    const std::string out = "1.2 - 3.4i";
    EXPECT_STREQ(out.c_str(), ss.str().c_str());
}

TEST_F(ComplexNumber_tests, minus_re_plus_im) {
    const Complex complex{-1.2, 3.4};
    std::stringstream ss;
    ss << complex;
    const std::string out = "-1.2 + 3.4i";
    EXPECT_STREQ(out.c_str(), ss.str().c_str());
}

TEST_F(ComplexNumber_tests, minus_re_minus_im) {
    const Complex complex{-1.2, -3.4};
    std::stringstream ss;
    ss << complex;
    const std::string out = "-1.2 - 3.4i";
    EXPECT_STREQ(out.c_str(), ss.str().c_str());
}

} // anonymous