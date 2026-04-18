#include <gtest/gtest.h>

#include <numbers/NumberStaticMock.h>
#include <numbers/NumberMock.h>
#include <parsers/ParserStaticMock.h>
#include <parsers/ParserMock.h>

#include <Calculator.h>

namespace {

using namespace testing;
using namespace mocks;
using namespace mw;

class Calculator_tests : public Test {
protected:
    void SetUp() {
        isNumber = [] (int token) {
            return std::isdigit(token);
        };
    }

    std::function<int(int)> isNumber;
    Calculator<NumberMock, ParserMock> calculator;
};

TEST_F(Calculator_tests, empty_expression_exception) {
    const std::string expression = "";
    EXPECT_THROW({
        calculator(expression, isNumber);
    }, std::runtime_error);
}

TEST_F(Calculator_tests, plus) {
    const std::string expression = "1 + 1";

    ParserStaticMock& parserMock = ParserStaticMock::getInstance();
    EXPECT_CALL(parserMock, parse(_, _))
        .Times(2)
        .WillOnce(Return(NumberMock{1}))
        .WillOnce(Return(NumberMock{1}));

    NumberStaticMock& numberMock = NumberStaticMock::getInstance();
    EXPECT_CALL(numberMock, plus(_, _)).WillOnce(Return(2));

    EXPECT_EQ(calculator(expression, isNumber), 2);
}

TEST_F(Calculator_tests, minus) {
    const std::string expression = "1 - 1";

    ParserStaticMock& parserMock = ParserStaticMock::getInstance();
    EXPECT_CALL(parserMock, parse(_, _))
        .Times(2)
        .WillOnce(Return(NumberMock{1}))
        .WillOnce(Return(NumberMock{1}));

    NumberStaticMock& numberMock = NumberStaticMock::getInstance();
    EXPECT_CALL(numberMock, minus(_, _)).WillOnce(Return(0));

    EXPECT_EQ(calculator(expression, isNumber), 0);
}

TEST_F(Calculator_tests, multi) {
    const std::string expression = "2 * 2";

    ParserStaticMock& parserMock = ParserStaticMock::getInstance();
    EXPECT_CALL(parserMock, parse(_, _))
        .Times(2)
        .WillOnce(Return(NumberMock{2}))
        .WillOnce(Return(NumberMock{2}));

    NumberStaticMock& numberMock = NumberStaticMock::getInstance();
    EXPECT_CALL(numberMock, multi(_, _)).WillOnce(Return(4));

    EXPECT_EQ(calculator(expression, isNumber), 4);
}

TEST_F(Calculator_tests, div) {
    const std::string expression = "6 / 3";

    ParserStaticMock& parserMock = ParserStaticMock::getInstance();
    EXPECT_CALL(parserMock, parse(_, _))
        .Times(2)
        .WillOnce(Return(NumberMock{6}))
        .WillOnce(Return(NumberMock{3}));

    NumberStaticMock& numberMock = NumberStaticMock::getInstance();
    EXPECT_CALL(numberMock, div(_, _)).WillOnce(Return(3));

    EXPECT_EQ(calculator(expression, isNumber), 3);
}

TEST_F(Calculator_tests, braces) {
    const std::string expression = "(1 + 2 + 3) * 4";

    ParserStaticMock& parserMock = ParserStaticMock::getInstance();
    EXPECT_CALL(parserMock, parse(_, _))
        .Times(4)
        .WillOnce(Return(NumberMock{1}))
        .WillOnce(Return(NumberMock{2}))
        .WillOnce(Return(NumberMock{3}))
        .WillOnce(Return(NumberMock{4}));

    NumberStaticMock& numberMock = NumberStaticMock::getInstance();
    EXPECT_CALL(numberMock, plus(_, _))
        .Times(2)
        .WillOnce(Return(3))
        .WillOnce(Return(6));
    EXPECT_CALL(numberMock, multi(_, _))
        .WillOnce(Return(24));

    EXPECT_EQ(calculator(expression, isNumber), 24);
}

TEST_F(Calculator_tests, unknown_operator) {
    const std::string expression = "1^2";

    ParserStaticMock& parserMock = ParserStaticMock::getInstance();
    EXPECT_CALL(parserMock, parse(_, _)).WillRepeatedly(Return(NumberMock{1}));

    EXPECT_THROW({
        calculator(expression, isNumber);
    }, std::runtime_error);
}

TEST_F(Calculator_tests, insufficient_operands) {
    const std::string expression = "1+";

    ParserStaticMock& parserMock = ParserStaticMock::getInstance();
    EXPECT_CALL(parserMock, parse(_, _)).WillRepeatedly(Return(NumberMock{1}));

    EXPECT_THROW({
        calculator(expression, isNumber);
    }, std::runtime_error);
}

} // anonymous