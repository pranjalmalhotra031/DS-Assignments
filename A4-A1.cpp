//  Given a function n, write a function that generates and prints all binary numbers with decimal 
// values from 1 to n. 
// Input: n = 2 
// Output: 1, 10 
// https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/ 

#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    if (n <= 0) return;

    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string s = q.front();
        q.pop();

        cout << s << " ";

        // Append "0" and "1" to current string
        q.push(s + "0");
        q.push(s + "1");
    }
}

int main() {
    int n = 2;   // Example input
    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinary(n);
    cout << endl;

    return 0;
}
