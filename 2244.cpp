#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <type_traits>
#include <numeric>
#include <bitset>
#include <functional>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")

using namespace std;

#define int long long
#define float long double
#define elif else if
#define endl "\n"
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000000001
#define inf INT64_MAX
#define FIXED(a) cout << fixed << setprecision(a);


bool contains(const string &s, char symbol) {
    for (auto ch: s) {
        if (ch == symbol)
            return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string S;
    string P;
    cin >> S >> P;
//    cout << S.find('*') << endl;
    if (contains(S, '*') || contains(S, '?'))
        swap(S, P);

    vector<vector<int>> dp(S.length() + 1, vector<int>(P.length() + 1, 0));
    for (int i = 0; i < S.length(); ++i) {
        for (int j = 0; j < P.length(); ++j) {
            if (S[i] == P[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            elif (P[i] == '?')dp[i + 1][j + 1] = dp[i][j] + 1;
            elif (P[i] == '*') {
                int max_ = -1;
                for (int k = 0; k < dp[i].size(); ++k) {
                    max_ = max(max_, dp[i][k]);
                }
                if(max_ == )
            } else
                dp[i + 1][j + 1] = max({dp[i][j], dp[i + 1][j], dp[i][j + 1]});
        }
    }

    if (dp[S.length()][P.length()] != P.length())
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}