#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;
#define int long long

vector<string> get(int n, int k) {
    if (n == 1) {
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(to_string(i));
        }
        return ans;
    }
    vector<string> ans;
    auto l = get(n - 1, k);
    for (int i = 0; i < k; i++) {
        for (auto f: l) {
            string s = to_string(i) + f;
            ans.push_back(s);
        }
        reverse(l.begin(), l.end());
    }
    return ans;
}

signed main() {
    int n, k;
    cin >> n >> k;
    auto f = get(n, k);
    for (auto g: f)
        cout << g << endl;
}
/*
 * 0
 * 1
 * 2
 *
 * 00
 * 01
 * 02
 * 12
 * 11
 * 10
 * 20
 * 21
 * 22
 *
 * 000
 * 001
 * 002
 * 012
 * 011
 * 010
 * 020
 * 021
 * 022
 * 122
 * 121
 * 120
 * 110
 * 111
 * 112
 * 102
 * 101
 *
 *
 * */