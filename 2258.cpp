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

int get(int N, int maxS) {
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    if (maxS <= 0)
        return 0;
    if (maxS * (maxS + 1) / 2 < N)
        return 0;
    int ans = 0;
    int x = 0;
    while (maxS > 0) {
        x = get(N - maxS, maxS - 1);
        ans += x;
        maxS--;
    }
    return ans;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    cout << get(x, x);
}