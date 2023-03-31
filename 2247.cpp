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
struct Square {
    bool x11;
    bool x12;
    bool x21;
    bool x22;
};
vector<Square> squares;

bool isVerboten(const Square &s) {
    for (auto &sq: squares) {
        if (sq.x11 == s.x11 and sq.x22 == s.x22 and sq.x21 == s.x21 and sq.x12 == s.x12) {
            return false;
        }
    }
    return true;
}

int N, M;

bool check(int x) {
    for (int i = 0; i < 2 * (M - 1); i += 2) {
        if (isVerboten({static_cast<bool>((x >> (i)) & 1), static_cast<bool>((x >> (i + 1)) & 1),
                        static_cast<bool>((x >> (i + 2)) & 1), static_cast<bool>((x >> (i + 3)) & 1)})) {
            return false;
        }
    }

    return true;
}

int dp[101][9][1 << (9)];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> M >> N;
    int q1;
    cin >> q1;
    Square s{};
    while (q1--) {
        cin >> s.x11 >> s.x12 >> s.x21 >> s.x22;
        squares.push_back(s);
    }
    memset(dp, 0, sizeof(dp));
    for (int p = 0; p < 1 << (2 * M); ++p) {
        if (check(p)) {
            int q = 0;
            for (int i = 0; i < 2 * M; i += 2) {
                q |= ((p >> (i + 1)) & 1) << (i / 2);
            }
            q |= ((p >> (2 * M - 2)) & 1) << (M);
            dp[2][M][q] += 1;
        }
    }
    for (int p = 0; p < (1 << (M + 1)); ++p) {
        for (int x = 0; x < 2; ++x) {
            for (int y = 0; y < 2; ++y) {
                if (!isVerboten({static_cast<bool>(p & 1), static_cast<bool>(x), static_cast<bool>((p >> 1) & 1),
                                 static_cast<bool>(y)})) {
                    int q = p & ~(1 << (M));
                    q >>= 1;
                    q <<= 2;
                    q |= (y << 1) | x;
                    dp[3][2][q] += dp[2][M][p];
                }
            }
        }
    }

    for (int i = 3; i <= N; ++i) {
        for (int j = 2; j < M; ++j) {
            for (int p = 0; p < (1 << (M + 1)); ++p) {
                for (int b = 0; b < 2; ++b) {
                    if (!isVerboten({static_cast<bool>((p >> (j)) & 1), static_cast<bool>((p >> (j - 1)) & 1),
                                     static_cast<bool>((p >> (j + 1)) & 1),
                                     static_cast<bool>(b)})) {
                        int q = p & ~(1 << j);
                        q |= (b << j);
                        dp[i][j + 1][q] += dp[i][j][p];
                    }
                }
            }
        }
        if (i == N) break;
        for (int p = 0; p < (1 << (M + 1)); ++p) {
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    if (!isVerboten({static_cast<bool>(p & 1), static_cast<bool>(x), static_cast<bool>((p >> 1) & 1),
                                     static_cast<bool>(y)})) {
                        int q = p & ~(1 << (M));
                        q >>= 1;
                        q <<= 2;
                        q |= (y << 1) | x;
                        dp[i + 1][2][q] += dp[i][M][p];
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << (M + 1)); ++i) {
        ans += dp[N][M][i];
    }
    cout << ans << endl;
}