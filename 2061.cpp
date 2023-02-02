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

void get(int x, int s, int f) {
    if (x == 1) {
        cout << s << " " << f << endl;
        return;
    }
    get(x - 1, s, 6 - f - s);
    cout << s << " " << f << endl;
    get(x - 1, 6 - f - s, f);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    get(n, 1, 2);
}