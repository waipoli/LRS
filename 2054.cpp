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
#define int long long
#define elif else if
#define endl "\n"
#define mod 1000000007
#define var auto

vector<int> nextPartition(vector<int> b) {
    if (b.size() == 1) {
        return {};
    }
    b[b.size() - 1]--;
    b[b.size() - 2]++;
    if (b[b.size() - 2] > b[b.size() - 1]) {
        b[b.size() - 2] += b[b.size() - 1];
        b.pop_back();
    } else {
        while (b[b.size() - 2] * 2 <= b[b.size() - 1]) {
            b.push_back(b[b.size() - 1] - b[b.size() - 2]);
            b[b.size() - 2] = b[b.size() - 3];
        }
    }
    return b;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int w;
    cin >> w;

    char c;
    cin >> c;
    int t;
    cin >> t;
    vector<int> a;
    a.push_back(t);
    while (cin >> c >> t)
        a.push_back(t);
    var b = nextPartition(a);

    if (b.size() == 0) {
        cout << "No solution" << endl;
        return 0;
    }
    cout << w << "=" << b[0];
    for (int i = 1; i < b.size(); ++i) {
        cout << "+" << b[i];
    }
    cout << endl;
}
