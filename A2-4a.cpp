// (a) Write a program to concatenate one string to another string. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    
    // Concatenate str2 to str1
    str1 += str2;
    
    cout << "Concatenated string: " << str1 << endl;
    return 0;
}
