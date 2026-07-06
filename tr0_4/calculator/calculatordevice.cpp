#include "calculatordevice.h"

#include <lib/Calculator.h>
#include <myhex.h>
#include <myhexparser.h>

using namespace mw;

class HexParserProxy : public mw::NumberParser<MyHex, HexParserProxy> {
public:
    MyHex parse(const std::string& str, std::function<int(int)> isNumber) {
        MyHexParser parser;
        return parser.parse(str, isNumber);
    }
};

QString CalculatorDevice::calculate(const QString& formula) {
    Calculator<MyHex, HexParserProxy> calculator;
    auto isNumber = [](int token)
    {
        return std::isxdigit(token);
    };
    return calculator(formula.toStdString(), isNumber).get();
}
