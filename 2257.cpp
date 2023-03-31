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
#include <chrono>

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
#define inf 1000000000000000000LL
#define FIXED(a) cout << fixed << setprecision(a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " = " << x << endl
#define time_init auto start = std::chrono::high_resolution_clock::now()
#define time_report auto end = std::chrono::high_resolution_clock::now(); std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << endl


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int dp[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = inf;
        }
    }
    for (int i = 0; i < n - 1; ++i)
        dp[i][i + 1] = 0;

    for (int sz = 3; sz <= n; ++sz) {
        for (int l = 0; l + sz - 1 < n; ++l) {
            int r = l + sz - 1;
            for (int k = l + 1; k <= r - 1; ++k) {
                int s = dp[l][k] + dp[k][r] + (v[l] + v[r]) * v[k];
                dp[l][r] = min(dp[l][r], s);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}