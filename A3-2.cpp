//  Given a string, reverse it using STACK. For example “DataStructure” should be output as 
// “erutcurtSataD.” 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;  

    stack<char> st;

    // Push all characters into stack
    for (char c : s)
        st.push(c);

    // Pop from stack and build reversed string
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
