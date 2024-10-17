#include <stack>
#include <iostream>
#include <vector>
using namespace std;
 
// The main function that returns value 
// of a given postfix expression
int evaluatePostfix(string exp, vector<CharIntPair> pairs)
{
    // Create a stack of capacity equal to expression size
    stack<int> expressionStack;
 
    // Scan all characters one by one
    for (int i = 0; i < exp.size(); ++i) {
         
        // If the scanned character is an operand 
        // (number here), push it to the stack.
        if (isalpha(exp[i]) )
            expressionStack.push(getValueByChar(pairs, exp[i])); //type casting using ASCII subtraction
 
        // If the scanned character is an operator, 
        // pop two elements from stack apply the operator
        else {
            int val1 = expressionStack.top();
            expressionStack.pop();
            int val2 = expressionStack.top();
            expressionStack.pop();
            switch (exp[i]) {
            case '+':
                expressionStack.push(val2 + val1);
                break;
            case '-':
                expressionStack.push(val2 - val1);
                break;
            case '*':
                expressionStack.push(val2 * val1);
                break;
            case '/':
                expressionStack.push(val2 / val1);
                break;
            case '%':
                expressionStack.push(val2 % val1);
                break;
            }
        }
    }
    return expressionStack.top();
}
