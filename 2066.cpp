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

#define int long long
#define float long double
#define elif else if
#define endl "\n"
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000000001
#define inf INT64_MAX
#define FIXED(a) cout << fixed << setprecision(a);


using namespace std;

vector<int> a;
vector<bool> used;
int n, t;

void gen(int p) {
    if (p == n) {
        for (int x: a) {
            cout << x << " ";
        }
        cout << "\n";
        t--;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i] && i != p) {
            used[i] = true;
            a[p] = i + 1;
            gen(p + 1);
            used[i] = false;
            if (t == 0) {
                break;
                continue;

            }
        }
    }
}

signed main() {
    cin >> n >> t;
    a.resize(n);
    used.resize(n);
    gen(0);
    return 0;
}