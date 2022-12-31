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

#define int long long
#define elif else if
#define endl "\n"
#define mod 1000000007


signed main() {

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i]), pref[i + 1] = pref[i] + v[i];

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        cout << pref[b] - pref[a - 1] << endl;
    }
}
