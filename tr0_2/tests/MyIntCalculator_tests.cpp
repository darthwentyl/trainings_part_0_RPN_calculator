#include <gtest/gtest.h>

#include <numbers/MyInt.h>
#include <parsers/MyIntParser.h>
#include <Calculator.h>

namespace {

using namespace mw;
using namespace testing;


class MyIntCalculator_tests : public Test {
protected:
    void SetUp() {
        isNumber = [](int token) {
            return std::isdigit(token);
        };
    }

    std::function<int(int)> isNumber;
    Calculator<MyInt, MyIntParser> calculator;
};

TEST_F(MyIntCalculator_tests, plus) {
    const std::string expression = "1 + 2";
    const MyInt result = calculator(expression, isNumber);
    EXPECT_EQ(result, -1);
}

TEST_F(MyIntCalculator_tests, minus) {
    const std::string expression = "1 - 2";
    const MyInt result = calculator(expression, isNumber);
    EXPECT_EQ(result, 3);
}

TEST_F(MyIntCalculator_tests, multiplication) {
    const std::string expression = "400 * 200";
    const MyInt result = calculator(expression, isNumber);
    EXPECT_EQ(result, 2);
}

TEST_F(MyIntCalculator_tests, division) {
    const std::string expression = "400 / 200";
    const MyInt result = calculator(expression, isNumber);
    EXPECT_EQ(result, 80000);
}

TEST_F(MyIntCalculator_tests, mix_expression) {
    const std::string expression = "2+4-16*8/10";
    const MyInt result = calculator(expression, isNumber);
    EXPECT_EQ(result, 18);
}

TEST_F(MyIntCalculator_tests, braces_mix_expression) {
    const std::string expression = "((2+4)-16*8/10)+12";
    const MyInt result = calculator(expression, isNumber);
    EXPECT_EQ(result, 6);
}

TEST_F(MyIntCalculator_tests, divide_zero_multiplication_zero_plus) {
    const std::string expression = "2/(1+1) + 32*(4-4)";
    const MyInt result = calculator(expression, isNumber);
    EXPECT_EQ(result, -2);
}

TEST_F(MyIntCalculator_tests, multiplication_zero_divide_zero_minus) {
    const std::string expression = "32*(4-4) - 2/(1+1)";
    const MyInt result = calculator(expression, isNumber);
    EXPECT_EQ(result, 6);
}

TEST_F(MyIntCalculator_tests, insufficient_operands) {
    const std::string expression = "1*";
    EXPECT_THROW({
        calculator(expression, isNumber);
    }, std::runtime_error);
}

TEST_F(MyIntCalculator_tests, empty_expression) {
    const std::string expression = "";
    EXPECT_THROW({
        calculator(expression, isNumber);
    }, std::runtime_error);
}

TEST_F(MyIntCalculator_tests, unknown_operator) {
    const std::string expression = "2^4";
    EXPECT_THROW({
        calculator(expression, isNumber);
    }, std::runtime_error);
}

} // anonymous