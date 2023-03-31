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
#define inf 1000000000000000000
#define FIXED(a) cout << fixed << setprecision(a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " = " << x << endl
#define time_init auto start = std::chrono::high_resolution_clock::now()
#define time_report auto end = std::chrono::high_resolution_clock::now(); std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << endl

struct People {
    int A;
    int B;
    int C;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    People p{};
    vector<People> peoples;
    for (int i = 0; i < n; ++i) {
        cin >> p.A >> p.B >> p.C;
        peoples.push_back(p);
    }
    vector<int> dp[3];
    dp[0].resize(n, inf);
    dp[1].resize(n, inf);
    dp[2].resize(n, inf);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[0][0] = peoples[0].A;
        } elif (i == 1) {
            dp[0][1] = dp[0][0] + peoples[1].A;
            dp[1][1] = peoples[0].B;
        } elif (i == 2) {
            dp[0][2] = min({dp[0][1], dp[1][1]}) + peoples[2].A;
            dp[1][2] = dp[0][0] + peoples[1].B;
            dp[2][2] = peoples[0].C;
        } else {
            dp[0][i] = min({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]}) + peoples[i].A;
            dp[1][i] = min({dp[0][i - 2], dp[1][i - 2], dp[2][i - 2]}) + peoples[i - 1].B;
            dp[2][i] = min({dp[0][i - 3], dp[1][i - 3], dp[2][i - 3]}) + peoples[i - 2].C;
        }
    }
    cout << min({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << endl;
}