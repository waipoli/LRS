#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <string>

using namespace std;

#define int __int128_t
#define elif else if
#define endl "\n"
#define mod 1000000007
#define inf 1000'000'000'000'000'000


int int_sqrt(int x) {
    long long ans = 0;
    for (int k = 1LL << 63; k != 0; k /= 2) {
        if ((ans + k) * (ans + k) <= x) {
            ans += k;
        }
    }
    return ans;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long L, R;
    cin >> L >> R;
    long long ans = 0;
    for (int i = 0; i * i * i <= 10LL * (int) inf; ++i) {
        int x = i * i * i;
        if (x % 6 != 0)
            continue;

        x /= 6;
        if (x < L or x > R)
            continue;
        if(x % 10 != 0)
            continue;
        x *= 10;
        int s = int_sqrt(x);
        if (s * s == x)
            ans++;
    }

    cout << ans << endl;
}