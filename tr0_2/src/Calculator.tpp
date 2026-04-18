#pragma once

#include <iostream>
#include <stack>

#include <NumberParser.h>
#include <RpnNotationConverter.h>

namespace mw {

template<class NUM_T, class PARSER_T>
NUM_T Calculator<NUM_T, PARSER_T>::operator () (const std::string& expression, std::function<int(int)> isNumber) {
    if (expression.empty()) {
        throw std::runtime_error("Expression cannot be empty");
    }
    std::istringstream rpn(toRpn(expression, isNumber));
    std::string token;
    std::stack<NUM_T> nums;
    NumberParser<NUM_T, PARSER_T> parser;
    while (rpn >> token) {
        if (token[0] == '-' && token.size() > 1) {
            nums.push(parser.parse(token, isNumber));
        } else if (isNumber(token[0])) {
            nums.push(parser.parse(token, isNumber));
        } else if (token.size() == 1) {
            if (nums.size() < 2) {
                throw std::runtime_error("Insufficient operands");
            }
            NUM_T num2 = nums.top();
            nums.pop();
            NUM_T num1 = nums.top();
            nums.pop();
            nums.push(performOperation(num1, num2, token[0]));
        }
    }
    return nums.top();
}

template<class NUM_T, class PARSER_T>
std::string Calculator<NUM_T, PARSER_T>::toRpn(const std::string& expression, std::function<int(int)> isNumber) {
    RpnNotationConverter converter;
    return converter(expression, isNumber);
}

template<class NUM_T, class PARSER_T>
NUM_T Calculator<NUM_T, PARSER_T>::performOperation(const NUM_T& num1, const NUM_T& num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        default: throw std::runtime_error("Unknown operator");
    };
}

} // mw