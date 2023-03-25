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
#define inf 1000'000'000'000LL
#define FIXED(a) cout << fixed << setprecision(a);


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int v[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> v[i][j];

    int dp[n][m][2][2];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    dp[i][j][k][l] = -inf;
                }
            }

    for (int i = 1; i < m - 1; ++i) {
        dp[0][i][0][0] = v[0][i];
    }
    dp[0][0][1][0] = v[0][0];
    dp[0][m-1][0][1] = v[0][m - 1];

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j == 0) {
                dp[i][j][1][0] = max({dp[i - 1][j][1][0],
                                      dp[i - 1][j + 1][1][0],
                                      dp[i - 1][j + 1][0][0]}) + v[i][j];

                dp[i][j][1][1] = max({dp[i - 1][j][1][1],
                                      dp[i - 1][j + 1][1][1],
                                      dp[i - 1][j + 1][0][1]}) + v[i][j];

                continue;
            }

            if (j == m - 1) {
                dp[i][j][0][1] = max({dp[i - 1][j][0][1],
                                      dp[i - 1][j - 1][0][1],
                                      dp[i - 1][j - 1][0][0]}) + v[i][j];

                dp[i][j][1][1] = max({dp[i - 1][j][1][1],
                                      dp[i - 1][j - 1][1][1],
                                      dp[i - 1][j - 1][1][0]}) + v[i][j];

                continue;
            }

            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    dp[i][j][k][l] = max({dp[i - 1][j][k][l],
                                          dp[i - 1][j - 1][k][l],
                                          dp[i - 1][j + 1][k][l]}) + v[i][j];
                }
            }
        }
    }

    int max_ = -inf;
    for (int i = 0; i < m; ++i) {
        max_ = max(max_, dp[n - 1][i][1][1]);
    }
    cout << max_ << endl;
}
