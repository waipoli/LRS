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

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")

using namespace std;

#define int long long
#define float long double
#define elif else if
#define endl "\n"
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000000001
#define inf 1000000000000000000
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

    int N;
    cin >> N;
    vector<int> dp(N + 1, inf);
    vector<int> pref(N + 1, -1);
    dp[1] = 0;
    for (int i = 1; i < N; ++i) {
        int x1 = i * 2;
        int x2 = i * 3;
        int x3 = i + 1;
        if (x1 > N)
            x1 = 0;
        if (x2 > N)
            x2 = 0;
        if (x3 > N)
            x3 = 0;
        if (dp[x1] > dp[i] + 1)
            pref[x1] = i;
        if (dp[x2] > dp[i] + 1)
            pref[x2] = i;
        if (dp[x3] > dp[i] + 1)
            pref[x3] = i;
        dp[x1] = min(dp[x1], dp[i] + 1);
        dp[x2] = min(dp[x2], dp[i] + 1);
        dp[x3] = min(dp[x3], dp[i] + 1);
    }
    vector<int> path;
    int cur = N;
    while (cur != -1) {
        path.push_back(cur);
        cur = pref[cur];
    }
    reverse(path.begin(), path.end());
    cout << dp[N] << endl;
    for (long long i : path) {
        cout << i << " ";
    }
}