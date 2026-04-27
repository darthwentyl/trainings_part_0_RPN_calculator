#include "calculatordevice.h"

#include <lib/Calculator.h>
#include <myhex.h>
#include <myhexparser.h>

using namespace mw;

QString CalculatorDevice::calculate(const QString& formula) {
    Calculator<MyHex, MyHexParser> calculator;
    auto isNumber = [](int token)
    {
        return std::isxdigit(token);
    };
    return calculator(formula.toStdString(), isNumber).get();
}
