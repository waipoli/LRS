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

vector<int> v;


int gC() {
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == i + 1)
            ans++;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }
    int ans = 0;
    ans += gC() == k;
    while (next_permutation(v.begin(), v.end())) {
        ans += gC() == k;
    }
    cout << ans << endl;
    return 0;
}