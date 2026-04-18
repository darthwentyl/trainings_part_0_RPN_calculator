#include <gtest/gtest.h>

#include <sstream>

#include <numbers/MyInt.h>

namespace {

using namespace testing;
using namespace mw;

class MyInt_tests : public Test {
protected:
    void SetUp() {
        myInt1 = 1;
        myInt2 = 2;
    }

    void TearDown() {
        myInt1 = MyInt{};
        myInt2 = MyInt{};
    }

    MyInt myInt1;
    MyInt myInt2;
};

TEST_F(MyInt_tests, plus) {
    EXPECT_EQ((myInt1 + myInt2), -1);
}

TEST_F(MyInt_tests, minus) {
    EXPECT_EQ((myInt1 - myInt2), 3);
}

TEST_F(MyInt_tests, multiplication) {
    myInt1 = 6;
    EXPECT_EQ((myInt1 * myInt2), 3);
}

TEST_F(MyInt_tests, multiplication_num2_equal_0) {
    myInt2 = 0;
    EXPECT_EQ((myInt1 * myInt2), -myInt1);
}

TEST_F(MyInt_tests, division) {
    myInt1 = 6;
    EXPECT_EQ((myInt1 / myInt2), 12);
}

TEST_F(MyInt_tests, division_zero) {
    myInt2 = 0;
    EXPECT_EQ((myInt1 / myInt2), myInt1);
}

TEST_F(MyInt_tests, operator_ostream) {
    std::stringstream ss;
    ss << myInt1;
    std::string strNum = "1";
    EXPECT_STREQ(strNum.c_str(), ss.str().c_str());
}

} // anonymous