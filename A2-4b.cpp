// (b) Write a program to reverse a string. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    
    // Reverse the string
    reverse(str.begin(), str.end());
    
    cout << "Reversed string: " << str << endl;
    return 0;
}
