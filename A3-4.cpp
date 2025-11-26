// Write a program to convert an Infix expression into a Postfix expression. 

#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3; // right-associative
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^';
}

// Convert infix string to postfix (tokens separated by spaces)
string infixToPostfix(const string &infix) {
    stack<char> ops;
    string output;
    int n = (int)infix.size();
    for (int i = 0; i < n; ) {
        char c = infix[i];

        // Skip spaces
        if (isspace((unsigned char)c)) { ++i; continue; }

        // If operand (letter or digit), read full identifier/number
        if (isalnum((unsigned char)c)) {
            string token;
            while (i < n && isalnum((unsigned char)infix[i])) {
                token.push_back(infix[i]);
                ++i;
            }
            if (!output.empty()) output.push_back(' ');
            output += token;
            continue;
        }

        // If '(', push to ops
        if (c == '(') {
            ops.push(c);
            ++i;
            continue;
        }

        // If ')', pop until '('
        if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                if (!output.empty()) output.push_back(' ');
                output.push_back(ops.top()); ops.pop();
            }
            if (!ops.empty() && ops.top() == '(') ops.pop(); // pop '('
            else {
                // mismatched parenthesis
                return "ERROR: mismatched parentheses";
            }
            ++i;
            continue;
        }

        // If operator
        if (isOperator(c)) {
            while (!ops.empty() && ops.top() != '(') {
                char topOp = ops.top();
                int pTop = precedence(topOp), pCur = precedence(c);
                if ( ( !isRightAssociative(c) && pTop >= pCur ) || 
                     ( isRightAssociative(c) && pTop > pCur ) ) {
                    // pop topOp to output
                    if (!output.empty()) output.push_back(' ');
                    output.push_back(topOp);
                    ops.pop();
                } else break;
            }
            ops.push(c);
            ++i;
            continue;
        }

        // Unknown character
        return string("ERROR: unexpected character '") + c + "'";
    }

    // Pop remaining operators
    while (!ops.empty()) {
        if (ops.top() == '(' || ops.top() == ')') return "ERROR: mismatched parentheses";
        if (!output.empty()) output.push_back(' ');
        output.push_back(ops.top());
        ops.pop();
    }

    return output;
}

int main() {
    string line;
    cout << "Enter infix expression (use spaces or not):\n";
    getline(cin, line);

    string postfix = infixToPostfix(line);
    cout << "Postfix: " << postfix << "\n";
    return 0;
}
