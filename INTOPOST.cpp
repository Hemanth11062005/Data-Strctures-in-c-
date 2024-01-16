#include <iostream>
#include <stack>
#include <cctype> // For isalnum()
using namespace std;
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0; // Assuming '(' has the lowest precedence
}

string infixToPostfix(string& infix) {
    stack<char> s;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // Append operand to the result
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove the '(' from the stack
        } else if (isOperator(c)) {
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << std::endl;

    return 0;
}
