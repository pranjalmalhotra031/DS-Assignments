// (c) Write a program to delete all the vowels from the string. 

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    
    // Remove vowels from the string
    str.erase(remove_if(str.begin(), str.end(), isVowel), str.end());
    
    cout << "String after removing vowels: " << str << endl;
    return 0;
}
