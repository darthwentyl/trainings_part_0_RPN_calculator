#include <gtest/gtest.h>
#include <cmath>

#include <ComplexParser.h>

namespace {

using namespace mw;
using namespace testing;

constexpr double PRECISION = 0.001;

class ComplexParser_tests : public Test {
protected:
    ComplexParser parser;
};

TEST_F(ComplexParser_tests, empty_line) {
    ComplexNumber number = parser(std::string{});
    EXPECT_DOUBLE_EQ(number.imag(), 0.0);
    EXPECT_DOUBLE_EQ(number.real(), 0.0);
}

TEST_F(ComplexParser_tests, base_number_without_spaces) {
    const std::string strNum = "1+i";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.imag(), 1.0);
    EXPECT_DOUBLE_EQ(number.real(), 1.0);
}

TEST_F(ComplexParser_tests, base_number_with_spaces) {
    const std::string strNum = " 1 + i ";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.imag(), 1.0);
    EXPECT_DOUBLE_EQ(number.real(), 1.0);
}

TEST_F(ComplexParser_tests, real_minus_imag_plus) {
    const std::string strNum = "-1.2 + 3.4i";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.imag(), 3.4);
    EXPECT_DOUBLE_EQ(number.real(), -1.2);
}

TEST_F(ComplexParser_tests, real_plus_imag_minus) {
    const std::string strNum = "5.6 - 7.8i";
    ComplexNumber number = parser(strNum);
    EXPECT_LT(std::fabs(number.imag()) - 7.8, PRECISION);
    EXPECT_LT(number.imag(), 0.0);
    EXPECT_DOUBLE_EQ(number.real(), 5.6);
}

TEST_F(ComplexParser_tests, real_minus_imag_minus) {
    const std::string strNum = "-5.6 - 7.8i";
    ComplexNumber number = parser(strNum);
    EXPECT_LT(std::fabs(number.imag()) - 7.8, PRECISION);
    EXPECT_LT(number.imag(), 0.0);
    EXPECT_LT(std::fabs(number.real()) - 5.6, PRECISION);
    EXPECT_LT(number.real(), 0.0);
}

TEST_F(ComplexParser_tests, imag_plus_real_plus) {
    const std::string strNum = "i + 2.0";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.imag(), 1.0);
    EXPECT_DOUBLE_EQ(number.real(), 2.0);
}

TEST_F(ComplexParser_tests, imag_plus_real_minus) {
    const std::string strNum = "2.3i - 4.5";
    ComplexNumber number = parser(strNum);
    EXPECT_LT(std::fabs(number.imag()) - 2.3, PRECISION);
    EXPECT_GT(number.imag(), 0.0);
    EXPECT_LT(std::fabs(number.real()) - 4.5, PRECISION);
    EXPECT_LT(number.real(), 0.0);
}

TEST_F(ComplexParser_tests, imag_minus_real_plus) {
    const std::string strNum = "-6.7i + 8.9";
    ComplexNumber number = parser(strNum);
    EXPECT_LT(std::fabs(number.imag()) - 6.7, PRECISION);
    EXPECT_LT(number.imag(), 0.0);
    EXPECT_LT(std::fabs(number.real()) - 8.9, PRECISION);
    EXPECT_GT(number.real(), 0.0);
}

TEST_F(ComplexParser_tests, imag_minus_real_minus) {
    const std::string strNum = "-111.8i - 999.999";
    ComplexNumber number = parser(strNum);
    EXPECT_LT(std::fabs(number.imag()) - 111.8, PRECISION);
    EXPECT_LT(number.imag(), 0.0);
    EXPECT_LT(std::fabs(number.real()) - 999.999, PRECISION);
    EXPECT_LT(number.real(), 0.0);
}

TEST_F(ComplexParser_tests, only_real) {
    const std::string strNum = "1";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.real(), 1.0);
    EXPECT_DOUBLE_EQ(number.imag(), 0.0);
}

TEST_F(ComplexParser_tests, only_imag) {
    const std::string strNum = "i";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.real(), 0.0);
    EXPECT_DOUBLE_EQ(number.imag(), 1.0);
}

TEST_F(ComplexParser_tests, only_imag_with_digits) {
    const std::string strNum = "123.123i";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.real(), 0.0);
    EXPECT_DOUBLE_EQ(number.imag(), 123.123);
}

TEST_F(ComplexParser_tests, only_imag_with_digits_minus) {
    const std::string strNum = "-123.123i";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.real(), 0.0);
    EXPECT_DOUBLE_EQ(number.imag(), -123.123);
}

TEST_F(ComplexParser_tests, only_imag_minus) {
    const std::string strNum = "-i";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.real(), 0.0);
    EXPECT_DOUBLE_EQ(number.imag(), -1.0);
}

TEST_F(ComplexParser_tests, only_real_minus) {
    const std::string strNum = "-1";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.real(), -1.0);
    EXPECT_DOUBLE_EQ(number.imag(), 0.0);
}

TEST_F(ComplexParser_tests, only_real_minus_with_digits) {
    const std::string strNum = "-123.123";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.real(), -123.123);
    EXPECT_DOUBLE_EQ(number.imag(), 0.0);
}

TEST_F(ComplexParser_tests, only_real_with_digits) {
    const std::string strNum = "123.123";
    ComplexNumber number = parser(strNum);
    EXPECT_DOUBLE_EQ(number.real(), 123.123);
    EXPECT_DOUBLE_EQ(number.imag(), 0.0);
}


} // anonymous