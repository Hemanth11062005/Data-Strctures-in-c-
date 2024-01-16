#include <iostream>
#include <cctype>
#include <string> // Include this header for using the string type
using namespace std;

int s[15];
int top = -1; // Rename the variable to avoid conflict with the function

void push(char c) {
    if (top == -1) {
        top = 0;
    } else {
        top++;
    }
    s[top] = c;
}

char getTop() { // Rename the function to avoid conflict with the variable
    return s[top];
}

void pop() {
    top = top - 1;
}

bool empty() {
    return (top == -1);
}

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

string infixToPostfix(string infix) {
    string postfix;
    char c = infix[0];
    int i=0;
    while(c!='\0'){
        c = infix[i];
        if (isalnum(c)) {
            postfix += c; // Append operand to the result
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!empty() && getTop() != '(') {
                postfix += getTop();
                pop();
            }
            pop(); // Remove the '(' from the stack
        } else if (isOperator(c)) {
            while (!empty() && getPrecedence(getTop()) >= getPrecedence(c)) {
                postfix += getTop();
                pop();
            }
            push(c);
        }
        c=infix[i++];
    }

    while (!empty()) {
        postfix += getTop();
        pop();
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
