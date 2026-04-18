#include <ComplexCalculator.h>
#include <ComplexParser.h>
#include <RpnNotationConverter.h>

#include <iostream>
#include <sstream>
#include <stack>

namespace mw {

ComplexNumber ComplexCalculator::operator() (const std::string& expression) {
    if (expression.empty()) {
        throw std::runtime_error("Expression cannot be empty");
    }
    std::istringstream rpn(toRpn(expression));
    std::string token;
    std::stack<ComplexNumber> nums;
    ComplexParser sToComplex;

    while (rpn >> token) {
        if (token[0] == '-' && token.size() > 1) {
            nums.push(sToComplex(token));
        } else if (isNumber(token)) {
            nums.push(sToComplex(token));
        } else if (token.size() == 1) {
            if (nums.size() < 2) {
                throw std::runtime_error("Insufficient operands");
            }
            ComplexNumber num2 = nums.top();
            nums.pop();
            ComplexNumber num1 = nums.top();
            nums.pop();

            nums.push(performOperation(num1, num2, token[0]));
        }
    }

    return nums.top();
}

std::string ComplexCalculator::toRpn(const std::string& expression) {
    RpnNotationConverter converter;
    return converter(expression);
}

bool ComplexCalculator::isNumber(const std::string& token) {
    return std::isdigit(token[0]) ||
                        token[0] == 'i';
}

ComplexNumber ComplexCalculator::performOperation(const ComplexNumber& num1, const ComplexNumber& num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        default: throw std::runtime_error("Unknown operator");
    };

}

} // mw