#include <gtest/gtest.h>

#include <parsers/MyIntParser.h>

namespace {

using namespace testing;
using namespace mw;

class MyIntParser_tests : public Test {
protected:
    MyIntParser parser;
    std::function<int(int)> isNumber;
};

TEST_F(MyIntParser_tests, plus_integer) {
    EXPECT_EQ(parser.parse("123", isNumber), 123);
}

TEST_F(MyIntParser_tests, minus_integer) {
    EXPECT_EQ(parser.parse("-123", isNumber), -123);
}

TEST_F(MyIntParser_tests, empty_string) {
    EXPECT_THROW({
        parser.parse("", isNumber);
    }, std::runtime_error);
}

} // anonymous