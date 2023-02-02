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
#define inf INT64_MAX
#define FIXED(a) cout << fixed << setprecision(a);
int a, b;
int xt, y;

int getCount(int x) {
    int ta = a;
    int tb = b;
    if (ta % x != 0)
        ta = (ta / x + 1) * x;
    ta /= x;
    tb = (tb / x);
    return tb - ta + 1;
}

vector<int> v;
int T = 0;
vector<vector<int>> qt(10);

void forceLoop(int n, int id, int ans) {
    if (n == 0) {
        qt[T].push_back(ans);
        return;
    }
    for (int i = id + 1; i < v.size(); i++) {
        forceLoop(n - 1, i, ans * v[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    xt = a;
    y = b;
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (T = 1; T <= 9; T++) {
        if (T > v.size())
            break;
        forceLoop(T, -1, 1);
    }
    int ans = 0;
    int kof = 1;
    for (int i = 1; i <= 9; i++) {
        for (auto g: qt[i])
            ans += getCount(g) * kof;
        kof *= -1;
    }
    cout << (y - xt + 1) - ans << endl;
    return 0;
}