// Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a 
// b c Sample O/P: a -1 b b 

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

void firstNonRepeatingInStream(const string &line) {
    queue<char> q;
    vector<int> freq(256, 0); // frequency table for ASCII characters

    bool firstOutput = true;
    for (char ch : line) {
        if (isspace(static_cast<unsigned char>(ch))) continue; // skip spaces

        // update frequency and push the character into the queue
        freq[(unsigned char)ch]++;
        q.push(ch);

        // remove from queue all characters that are now repeating
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) {
            q.pop();
        }

        // output the current first non-repeating or -1
        if (!firstOutput) cout << " ";
        firstOutput = false;

        if (q.empty())
            cout << -1;
        else
            cout << q.front();
    }

    cout << "\n";
}

int main() {
    string line;
    cout << "Enter the character stream (single line). Example: a a b c  or  aabc\n";
    if (!getline(cin, line)) return 0;

    firstNonRepeatingInStream(line);

    return 0;
}
