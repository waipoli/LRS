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

#define int __int128_t
#define float long double
#define elif else if
#define endl "\n"
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000000001
#define inf INT64_MAX
#define FIXED(a) cout << fixed << setprecision(a);

string to_string(int n) {
    string s;
    while (n) {
        s += (n % 10) + '0';
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    cin >> n;
    vector<vector<int>> dp(10, vector<int>(n + 1, 0));
    for (int i = 0; i < 10; ++i) {
        if (i == 8 || i == 0)
            continue;
        dp[i][1] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = dp[4][i - 1] + dp[6][i - 1];
        dp[1][i] = dp[8][i - 1] + dp[6][i - 1];
        dp[2][i] = dp[7][i - 1] + dp[9][i - 1];
        dp[3][i] = dp[4][i - 1] + dp[8][i - 1];
        dp[4][i] = dp[3][i - 1] + dp[9][i - 1] + dp[0][i - 1];
        dp[6][i] = dp[1][i - 1] + dp[7][i - 1] + dp[0][i - 1];
        dp[7][i] = dp[2][i - 1] + dp[6][i - 1];
        dp[8][i] = dp[1][i - 1] + dp[3][i - 1];
        dp[9][i] = dp[4][i - 1] + dp[2][i - 1];
    }

    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        ans += dp[i][n];
    }
    cout << to_string(ans) << endl;
}