// Write a program to convert a character from uppercase to lowercase. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    
    // Convert to lowercase
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + ('a' - 'A');
        cout << "Lowercase character: " << ch << endl;
    } else {
        cout << "The entered character is not an uppercase letter." << endl;
    }
    
    return 0;
}
