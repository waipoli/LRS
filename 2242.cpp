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

//#define int long long
#define float long double
#define elif else if
#define endl "\n"
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000000001
#define inf INT64_MAX
#define FIXED(a) cout << fixed << setprecision(a);

struct Tuple {
    short a;
    short b;
    short c;
};
short dp[301][301][301];
Tuple path[301][301][301];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    short N, M, K;
    cin >> N >> M >> K;
    vector<int> a(N);
    vector<int> b(M);
    vector<int> c(K);
    for (int &el: a)
        cin >> el;

    for (int &el: b)
        cin >> el;

    for (int &el: c)
        cin >> el;

    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= M; ++j)
            for (int k = 0; k <= K; ++k)
                dp[i][j][k] = 0;

    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= M; ++j)
            for (int k = 0; k <= K; ++k)
                path[i][j][k] = {-1, -1, -1};

    for (short i = 1; i <= N; ++i) {
        for (short j = 1; j <= M; ++j) {
            for (short k = 1; k <= K; ++k) {

                if (a[i - 1] == b[j - 1] and b[j - 1] == c[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    path[i][j][k] = {static_cast<short>(i - 1), static_cast<short>(j - 1), static_cast<short>(k - 1)};
                    continue;
                }


                short u1 = dp[i - 1][j][k];
                short u2 = dp[i][j - 1][k];
                short u3 = dp[i][j][k - 1];
                short uMax = max({u1, u2, u3});
                dp[i][j][k] = uMax;
                if (uMax == u1)
                    path[i][j][k] = {static_cast<short>(i - 1), j, k};
                elif (uMax == u2)path[i][j][k] = {i, static_cast<short>(j - 1), k};
                else
                    path[i][j][k] = {i, j, static_cast<short>(k - 1)};
            }
        }
    }

    cout << dp[N][M][K] << endl;

    vector<int> ans;
    Tuple t = {N, M, K};
    Tuple next{};
    while (t.a != 0 and t.b != 0 and t.c != 0) {
        next = path[t.a][t.b][t.c];
        if (next.a == t.a - 1 and next.b == t.b - 1 and next.c == t.c - 1)
            ans.push_back(a[t.a - 1]);
        t = next;
    }
    reverse(ans.begin(), ans.end());
    for (long long an: ans) {
        cout << an << " ";
    }
//    cout << endl;
}