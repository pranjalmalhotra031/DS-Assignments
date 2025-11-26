// String Anagrams  
// Given two strings str1 and str2, determine if they form an anagram pair.  
// Note: Two strings are considered anagrams if one string can be rearranged to form the other 
// string. 
// https://www.codechef.com/practice/course/nutanix-interview-questions/NUTANIXCON01/problems/NUTANIX01 

#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(const string &a, const string &b) {
    if (a.length() != b.length()) 
        return false;

    int freq[26] = {0};

    for (char c : a)
        freq[c - 'a']++;

    for (char c : b)
        freq[c - 'a']--;

    for (int x : freq)
        if (x != 0) return false;

    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (areAnagrams(s1, s2)) 
        cout << "YES\n";
    else 
        cout << "NO\n";

    return 0;
}
