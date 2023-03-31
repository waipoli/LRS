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


int getBit(int x, int i) {
    return (x >> i) & 1;
}

int setBit(int x, int i) {
    return x | (1 << i);
}

int clearBit(int x, int i) {
    return x & (~(1 << i));
}

int N, M;

int dp[16 + 1][8 + 1][1 << (8 + 1)];

bool isValidQ(int q, int j) {
    return q != (((1 << (M - j + 1)) - 1)) << j;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> M >> N;
//    x(1);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int p = 0; p < (1 << (M + 1)); ++p) {
                if (getBit(p, j)) {
                    int q = clearBit(p, j);
                    if (isValidQ(q, j))
                        dp[i][j + 1][q] += dp[i][j][p];
                    else
                        dp[i][j + 1][q] = 0;

                } else {
                    {
                        int q = setBit(p, j);
                        if (isValidQ(q, j))
                            dp[i][j + 1][q] += dp[i][j][p];
                        else
                            dp[i][j + 1][q] = 0;
                    }
                    if (j < M - 1 and !getBit(p, j + 1)) {
                        int q = setBit(p, j + 1);
                        if (isValidQ(q, j))
                            dp[i][j + 1][q] += dp[i][j][p];
                        else
                            dp[i][j + 1][q] = 0;
                    }
                }
            }
        }
        for (int p = 0; p < (1 << (M + 1)); ++p) {
            dp[i + 1][0][p] = dp[i][M][p];
        }
    }
    cout << dp[N][0][0] << endl;
}