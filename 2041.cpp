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
int n;

string to3(int x) {
    string ans = "";
    while (x) {
        ans += to_string(x % 3);
        x /= 3;
    }
    while (ans.size() != n) {
        ans.push_back('0');
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < pow(3, n - 1); i++) {
        string ans = to3(i);
        cout << ans << endl;
        for (int j = 0; j < ans.size(); j++) {
            ans[j]++;
            if (ans[j] == '3')
                ans[j] = '0';
        }
        cout << ans << endl;
        for (int j = 0; j < ans.size(); j++) {
            ans[j]++;
            if (ans[j] == '3')
                ans[j] = '0';
        }
        cout << ans << endl;
    }
}