// String Split Challenge 
// You are given a string consisting of lowercase English alphabets. Your task is to determine 
// if it's possible to split this string into three non-empty parts (substrings) where one of 
// these parts is a substring of both remaining parts 
// https://www.codechef.com/practice/course/nutanix-interview-questions/NUTANIXCON01/problems/NUTANIX11?tab=statement 

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) return 0;
    int n = (int)s.size();
    if (n < 3) { cout << "NO\n"; return 0; }

    // check: any character appearing at least 3 times -> YES
    {
        array<int,26> cnt{}; cnt.fill(0);
        for (char c : s) cnt[c-'a']++;
        for (int x : cnt) if (x >= 3) { cout << "YES\n"; return 0; }
    }

    // Rolling hash base and mod 
    const ull B = 1315423911ULL; // some big odd base (using ull arithmetic)
    vector<ull> pref(n+1, 0), powB(n+1, 1);
    for (int i = 0; i < n; ++i) {
        pref[i+1] = pref[i] * B + (unsigned char)(s[i]);
        powB[i+1] = powB[i] * B;
    }
    auto get_hash = [&](int l, int r)->ull { // [l..r] inclusive
        return pref[r+1] - pref[l] * powB[r-l+1];
    };

    // lengths L from 1..n/3
    for (int L = 1; L * 3 <= n; ++L) {
        unordered_map<ull, pair<int,int>> mp;
        mp.reserve(n / L + 10);

        bool found = false;
        for (int i = 0; i + L - 1 < n; ++i) {
            ull h = get_hash(i, i + L - 1);
            auto it = mp.find(h);
            if (it == mp.end()) {
                // store first occurrence start
                mp[h] = {i, -1};
            } else {
                int first = it->second.first;
                int second = it->second.second;
                if (second == -1) {
                    // try to set second as earliest start that does not overlap first
                    if (i > first + L - 1) {
                        it->second.second = i;
                    }
                    // otherwise keep waiting for further positions
                } else {
                    // first and second (non-overlapping); check if current i is non-overlapping with second
                    if (i > second + L - 1) {
                        found = true;
                        break;
                    }
                    // if current i doesn't satisfy, keep earlier second as it is the best chance for a later third
                }
            }
        }
        if (found) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
