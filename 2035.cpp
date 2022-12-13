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

struct Tuple {
    int a, b, c;
};
int n = 1000'000'0;
vector<char> prime(n + 1, true);
signed main() {
    int x;
    cin >> x;
    prime[0] = prime[1] = false;
    for (int i=2; i*i<=n; ++i)
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;

    vector<int> p;
    for (int i = 2; i < n; ++i) {
        if (prime[i])
            p.push_back(i);
    }
    vector<Tuple> ans;
    int count = 0;
    for (auto d1: p) {
        int d2 = d1;
        if (d2 < d1)
            continue;
        for (int a = 0; a < 5; a++) {
            int d3 = a * d1 + 1;
            int d3o = d3;
            if (((d3 + d2) * (d3 + d2) - 1) % d1 == 0 and ((d2 + d1) * (d2 + d1) - 1) % d3 == 0 and d3 > d2 and
                prime[d3])
                ans.push_back({d1, d2, d3}), count++;
            d3 = (a + 1) * d1 - 1;
            if (d3 == d3o)
                continue;
            if (((d3 + d2) * (d3 + d2) - 1) % d1 == 0 and ((d2 + d1) * (d2 + d1) - 1) % d3 == 0 and d3 > d2 and
                prime[d3])
                ans.push_back({d1, d2, d3}), count++;
        }
        if (count- 5 > x)
            break;
    }
    cout << ans[x - 1].a << " " << ans[x - 1].b << " " << ans[x - 1].c << endl;
}