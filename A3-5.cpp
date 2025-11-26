//  Write a program for the evaluation of a Postfix expression.

#include <bits/stdc++.h>
using namespace std;

bool isOperator(const string &t) {
    return t == "+" || t == "-" || t == "*" || t == "/" || t == "^";
}

int main() {
    cout << "Enter a postfix expression (tokens separated by spaces):\n";
    string line;
    if (!std::getline(cin, line)) return 0;

    stringstream ss(line);
    string token;
    stack<double> st;
    bool error = false;

    while (ss >> token) {
        // If token is an operator
        if (isOperator(token)) {
            if ((int)st.size() < 2) {
                cerr << "ERROR: insufficient operands for operator '" << token << "'\n";
                error = true;
                break;
            }
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            double res = 0.0;

            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") {
                if (b == 0.0) {
                    cerr << "ERROR: division by zero\n";
                    error = true;
                    break;
                }
                res = a / b;
            }
            else if (token == "^") res = pow(a, b);

            st.push(res);
        }
        else {
            try {
                size_t idx = 0;
                double val = stod(token, &idx);
                if (idx != token.size()) {
                    // leftover characters → invalid token
                    cerr << "ERROR: invalid token '" << token << "'\n";
                    error = true;
                    break;
                }
                st.push(val);
            } catch (...) {
                cerr << "ERROR: invalid number token '" << token << "'\n";
                error = true;
                break;
            }
        }
    }

    if (!error) {
        if (st.size() == 1) {
            double result = st.top();
            if (fabs(result - round(result)) < 1e-9) {
                cout << "Result: " << (long long)llround(result) << "\n";
            } else {
                cout.setf(std::ios::fixed); cout << setprecision(9);
                // trimming trailing zeros
                stringstream out;
                out << fixed << setprecision(9) << result;
                string s = out.str();
                // remove trailing zeros
                while (!s.empty() && s.back() == '0') s.pop_back();
                if (!s.empty() && s.back() == '.') s.pop_back();
                cout << "Result: " << s << "\n";
            }
        } else if (st.empty()) {
            cerr << "ERROR: no result (empty expression)\n";
        } else {
            cerr << "ERROR: too many operands (stack has " << st.size() << " items)\n";
        }
    }

    return 0;
}
