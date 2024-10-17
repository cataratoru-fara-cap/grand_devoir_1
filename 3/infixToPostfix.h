#include <stack>
#include <string>
#include <iostream>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '%')
        return 3;
    return 0;
}

std::string infixToPostfix(std::string infix) {
    std::stack<char> expressionStack;
    std::string postfix;

    for (char c : infix) {
        if (isalpha(c)) {
            postfix += c;
        } else if (c == '(') {
            expressionStack.push(c);
        } else if (c == ')') {
            while (!expressionStack.empty() && expressionStack.top() != '(') {
                postfix += expressionStack.top();
                expressionStack.pop();
            }
            if (!expressionStack.empty()) 
                expressionStack.pop(); // pop '('
        } else { // operator
            while (!expressionStack.empty() && precedence(c) <= precedence(expressionStack.top())) {
                postfix += expressionStack.top();
                expressionStack.pop();
            }
            expressionStack.push(c);
        }
    }
    // in case we get input like "A+B"  and the ')' never hits
    while (!expressionStack.empty()) { 
        postfix += expressionStack.top();
        expressionStack.pop();
    }

    return postfix;
}

