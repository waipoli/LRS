#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
#include <deque>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;
#define int long long
#define endl "\n"
#define epd 0.0000001
#define inf 100000000000000000


int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int x, y;
    x = (a / n) * n - 1;
    y = (b / n) * n - 1;
    int ans = 0;
    if (a == 0 and b == 0) {
        cout << 0 << endl;
        return;
    }
    if (a == 0) {
        if ((b + n) / n - 1 < 0)
            cout << 0 << endl;
        else
            cout << (b + n) / n - 1 << endl;
        return;
    }
    if (b == 0) {
        if ((a + n) / n - 1 < 0)
            cout << 0 << endl;
        else
            cout << (a + n) / n - 1 << endl;
        return;
    }

    ans += ((x + 1)) * ((y + 1) / n);
    ans += (a - x) * ((y + 1) / n);
    ans += (b - y) * ((x + 1) / n);
    if (b - y > (n - 0) % n)
        ans++;
    int k = b - y;
    int count = a - x - (n - k) - 1;
    if (count < 0)
        count = 0;
    ans += count;
//    for (int i = 1; i < a - x; i++) {
//        if (k > (n - i)) {
//            ans++;
//            cout<<i<<endl;
//        }
//    }
    ans--;

    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while (q--)
        solve();
}
