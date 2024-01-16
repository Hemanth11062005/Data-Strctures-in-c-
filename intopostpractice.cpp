#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
bool isOperator(char op){
    return (op=='+'||op=='-'||op=='*'||op=='/');
}
int getPrecedence(char op){
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    else 
        return 0;
}

string infixtopostfix(string infix)
{
    stack<char> s;
    string postfix;
    for(char c : infix){
    if(isalnum(c))
        postfix+=c;
    else if(c == '(')
        s.push('(');
    else if(c == ')'){
        while(!s.empty() && s.top()!='('){
            postfix+=s.top();
            s.pop();
        }
        s.pop();
    }
    else if(isOperator(c)){
        while(!s.empty() && getPrecedence(s.top())>=getPrecedence(c)){
            postfix+=s.top();
            s.pop();
        }
        s.push(c);
    }
}
while(!s.empty()){
    postfix+=s.top();
    s.pop();
}
return postfix;
}


int main(){
    string infix;
    cout<<"Infix xpression      :";
    cin>>infix;
    string postfix = infixtopostfix(infix);
    cout<<"Postfix Expression   :"<<postfix;
}

