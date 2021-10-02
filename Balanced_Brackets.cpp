// Check for Balanced Brackets in an expression (well-formedness) using Stack

#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string exp)
{
    if (exp.length() & 1) {
        return false;
    }
 
    stack<char> stack;
 
    for (char ch: exp)
    {

        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }

        if (ch == ')' || ch == '}' || ch == ']')
        {
            if (stack.empty()) {
                return false;
            }
 
            char top = stack.top();
            stack.pop();
 
            if ((top == '(' && ch != ')') ||
                    (top == '{' && ch != '}') ||
                    (top == '[' && ch != ']')) {
                return false;
            }
        }
    }
 
    return stack.empty();
}
 
int main()
{
    string exp;
    cout<<"Please insert the expression like EX: {},{(}),{([])} ";
    getline(cin,exp);
 
    if (isBalanced(exp)) {
        cout << "The expression is balanced";
    }
    else {
        cout << "The expression is not balanced";
    }
 
    return 0;
}