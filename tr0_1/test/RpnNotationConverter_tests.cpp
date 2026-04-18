#include <gtest/gtest.h>

#include <RpnNotationConverter.h>

namespace {

using namespace mw;
using namespace testing;

class RpnNotationConverter_tests : public Test {
protected:
    RpnNotationConverter converter;
};

TEST_F(RpnNotationConverter_tests, rpn_one_complex_num) {
    const std::string expression = "1 + i";
    const std::string rpn = "1 i +";

    EXPECT_STREQ(rpn.c_str(), converter(expression).c_str());
}

TEST_F(RpnNotationConverter_tests, rpn_two_complex_num_sum_sub) {
    const std::string expression = "1 + i - 2 - i";
    const std::string rpn = "1 i + 2 - i -";

    EXPECT_STREQ(rpn.c_str(), converter(expression).c_str());
}

TEST_F(RpnNotationConverter_tests, rpn_large_two_complex_num_sum_sub) {
    const std::string expression = "-123.123-456.456i+789.789+321.321i";
    const std::string rpn = "-123.123 456.456i - 789.789 + 321.321i +";

    EXPECT_STREQ(rpn.c_str(), converter(expression).c_str());
}

TEST_F(RpnNotationConverter_tests, rpn_mult) {
    const std::string expression = "(-11.22 + 33.44i)*(-55.66 + 77.88i)";
    const std::string rpn = "-11.22 33.44i + -55.66 77.88i + *";

    EXPECT_STREQ(rpn.c_str(), converter(expression).c_str());
}

TEST_F(RpnNotationConverter_tests, rpn_dist) {
    const std::string expression = "(11.22 + 33.44i) / (55.66 + 77.88i)";
    const std::string rpn = "11.22 33.44i + 55.66 77.88i + /";

    EXPECT_STREQ(rpn.c_str(), converter(expression).c_str());
}

TEST_F(RpnNotationConverter_tests, rpn_hard) {
    const std::string expression = "((1.1+(2.2i - 3.3i))*4.4)/((-5.5i*6.6)+ 7.7i)+8.8- 9.9i";
    const std::string rpn = "1.1 2.2i 3.3i - + 4.4 * -5.5i 6.6 * 7.7i + / 8.8 + 9.9i -";

    EXPECT_STREQ(rpn.c_str(), converter(expression).c_str());
}

} // anonymous