#include <RpnNotationConverter.h>

#include <iostream>
#include <stack>
#include <sstream>

namespace mw {

std::string RpnNotationConverter::operator () (const std::string& expression, std::function<int(int)> isNumber) {
    std::stack<char> operators;
    std::stringstream rpnStream;
    bool lastWasOperator = true;

    for (std::string::size_type pos = 0; pos < expression.length(); pos++) {
        char token = expression[pos];

        if (std::isspace(token)) {
            continue;
        } else if(isNumber(token) || (token == '-' && lastWasOperator)) {
            if (token == '-') {
                rpnStream << "-";
                pos++;
            }
            while (pos < expression.length() && isNumber(expression[pos])) {
                rpnStream << expression[pos++];
            }
            rpnStream << ' ';
            lastWasOperator = false;
            pos--;
        } else if (token == '(') {
            lastWasOperator = true;
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                rpnStream << operators.top() << ' ';
                operators.pop();
            }
            operators.pop();
            lastWasOperator = false;
        } else {

            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                rpnStream << operators.top() << ' ';
                operators.pop();
            }
            operators.push(token);
            lastWasOperator = true;
        }
    }

    while (!operators.empty()) {
        rpnStream << operators.top() << ' ';
        operators.pop();
    }

    std::string rpn = rpnStream.str();
    if (rpn.back() == ' ') {
        rpn.pop_back();
    }
    if (rpn.empty()) {
        throw std::runtime_error("Cannot convert expression to RPN notation");
    }
    return rpn;
}

unsigned RpnNotationConverter::precedence(const char token) {
    if (token == '+' || token == '-') return 1;
    if (token == '*' || token == '/') return 2;

    return 0;
}

} // mw