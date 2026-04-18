#include <gtest/gtest.h>
#include <cmath>
#include <cctype>

#include <numbers/ComplexNumber.h>
#include <parsers/ComplexParser.h>
#include <Calculator.h>

namespace {

using namespace mw;
using namespace testing;

constexpr double PRECISSION = 0.001;

class ComplexCalculator_tests : public Test {
protected:
    void SetUp() {
        isNumber = [](int token) {
            return std::isdigit(token) ||
                   token == static_cast<int>('i') ||
                   token == static_cast<int>('.');
        };
    }

    using ComplexDouble = ComplexNumber<double>;
    Calculator<ComplexDouble, ComplexParser<double>> calculator;
    std::function<int(int)> isNumber;
};

TEST_F(ComplexCalculator_tests, complex_easy) {
    const std::string expression = "1 + i";
    ComplexDouble result = calculator(expression, isNumber);
    EXPECT_DOUBLE_EQ(result.real(), 1.0);
    EXPECT_DOUBLE_EQ(result.imag(), 1.0);
}

TEST_F(ComplexCalculator_tests, calc_two_complex_num_sum_sub) {
    const std::string expression = "1 + i - 2 - i";
    ComplexDouble result = calculator(expression, isNumber);
    EXPECT_DOUBLE_EQ(result.real(), -1.0);
    EXPECT_DOUBLE_EQ(result.imag(), 0.0);
}

TEST_F(ComplexCalculator_tests, calc_large_two_complex_num_sum_sub) {
    const std::string expression = "-123.123- 456.456i+789.789 +321.321i";
    ComplexDouble result = calculator(expression, isNumber);

    EXPECT_LT(std::fabs(result.real()) - 666.666, PRECISSION);
    EXPECT_GT(result.real(), 0.0);
    EXPECT_LT(std::fabs(result.imag()) - 135.135, PRECISSION);
    EXPECT_LT(result.imag(), 0.0);
}

TEST_F(ComplexCalculator_tests, calc_mult) {
    const std::string expression = "(-11.22 + 33.44i)*(-55.66 + 77.88i)";
    ComplexDouble result = calculator(expression, isNumber);

    EXPECT_LT(std::fabs(result.real()) - 1979.802, PRECISSION);
    EXPECT_LT(result.real(), 0.0);
    EXPECT_LT(std::fabs(result.imag()) - 2735.084, PRECISSION);
    EXPECT_LT(result.imag(), 0.0);
}

TEST_F(ComplexCalculator_tests, calc_div) {
    const std::string expression = "-1 * (11.22 + 33.44i) / (55.66 + 77.88i)";
    ComplexDouble result = calculator(expression, isNumber);

    EXPECT_LT(std::fabs(result.real()) - 0.352, PRECISSION);
    EXPECT_LT(result.real(), 0.0);
    EXPECT_LT(std::fabs(result.imag()) - 0.108, PRECISSION);
    EXPECT_LT(result.imag(), 0.0);
}

TEST_F(ComplexCalculator_tests, calc_hard) {
    const std::string expression = "((1.1+(2.2i - 3.3i))*4.4)/((-5.5i*6.6)+ 7.7i)+8.8- 9.9i";
    ComplexDouble result = calculator(expression, isNumber);

    EXPECT_LT(std::fabs(result.real()) - 8.969, PRECISSION);
    EXPECT_GT(result.real(), 0.0);
    EXPECT_LT(std::fabs(result.imag()) - 9.731, PRECISSION);
    EXPECT_LT(result.imag(), 0.0);
}

TEST_F(ComplexCalculator_tests, insufficient_operands) {
    const std::string expression = "1.1i+";
    EXPECT_THROW({
        calculator(expression, isNumber);
    }, std::runtime_error);
}

TEST_F(ComplexCalculator_tests, empty_expression) {
    const std::string expression = "";
    EXPECT_THROW({
        calculator(expression, isNumber);
    }, std::runtime_error);
}

TEST_F(ComplexCalculator_tests, unknown_operator) {
    const std::string expression = "1.1^1.1i";
    EXPECT_THROW({
        calculator(expression, isNumber);
    }, std::runtime_error);
}

} // anonymous