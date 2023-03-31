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
    if (contains(S, '*') || contains(S, '?'))
        swap(S, P);

    vector<vector<bool>> dp(S.size() + 1, vector<bool>(P.size() + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= S.size(); i++) {
        for (int j = 1; j <= P.size(); ++j) {
            if (P[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } elif (P[j - 1] == '*') {

                bool res = false;
                for(int k = 0; k <= i; ++k) {
                    res |= dp[k][j - 1];
                }
                dp[i][j] = res;
            } else {
                if (S[i - 1] == P[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = false;
            }
        }
    }
    cout << (dp[S.size()][P.size()] ? "YES" : "NO") << endl;
}