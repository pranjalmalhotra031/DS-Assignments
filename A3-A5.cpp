// You have an array A of integers of size N, an array B (initially empty) and a stack S (initially 
// empty). You are allowed to do the following operations: 
// a) Take the first element of array A and push it into S and remove it from A. 
// b) Take the top element from stack S, append it to the end of array B and remove it from S. 
// You have to tell if it possible to move all the elements of array A to array B using the above 
// operations such that finally the array B is sorted in ascending order. 
// Stack Sort Practice Problem in Amazon Coding Interview Questions

#include <bits/stdc++.h>
using namespace std;

bool canBeSortedWithStack(vector<int>& A) {
    int n = A.size();

    vector<int> C = A;
    sort(C.begin(), C.end());   // Target sorted array B

    stack<int> S;
    int j = 0;                 // pointer in sorted array C

    for (int i = 0; i < n; i++) {
        // Push current A[i] into stack
        S.push(A[i]);

        // While top of stack matches next needed sorted value
        while (!S.empty() && S.top() == C[j]) {
            S.pop();
            j++;
        }
    }

    // stack must also allow remaining sorted values
    while (!S.empty() && S.top() == C[j]) {
        S.pop();
        j++;
    }

    // If we consumed all sorted values ->  possible
    return (j == n);
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    if (canBeSortedWithStack(A))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
