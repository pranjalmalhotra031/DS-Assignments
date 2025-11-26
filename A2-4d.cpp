// Write a program to sort the strings in alphabetical order. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore(); // ignores the newline character after the integer input

    vector<string> strings(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, strings[i]);
    }

    // Sort the strings in alphabetical order
    sort(strings.begin(), strings.end());

    cout << "Strings in alphabetical order:\n";
    for (const string &str : strings) {
        cout << str << endl;
    }
    return 0;
}
