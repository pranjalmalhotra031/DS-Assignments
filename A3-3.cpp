// Write a program that checks if an expression has balanced parentheses. 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expr) {
    stack<char> st;

    for (char c : expr) {
        // Push opening brackets
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // Check closing brackets
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }

    // If stack is empty → balanced
    return st.empty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
