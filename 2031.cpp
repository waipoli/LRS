#include <iostream>
#include <set>
#include <vector>
#include <functional>
#include <queue>
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
using namespace std;
#define int long long
#define inf 1000'000'000'000'000'000LL
#define elif else if
#define endl "\n"
#define mod 1000000007

int getCount(int l, int r, int d) {
    if (l > r) {
        return 0;
    }

    if (l % d != 0) {
        l -= l % d;
        l += d;
    }
    r = (r / d) * d;
    l /= d;
    r /= d;
    return r - l + 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i*i < b; i++) {
        int start = max(a, i * (i + 2));
        ans += getCount(start, b, i);
    }
    cout << ans << endl;
}

