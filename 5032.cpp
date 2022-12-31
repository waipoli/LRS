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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a;
    string b;
    cin >> a >> b;
    map<string, int> m;
    map<string, int> m1;
    for (int i = 1; i < a.size(); i++) {
        string t(1, a[i - 1]);
        t += a[i];
        m[t]++;
    }
    for (int i = 1; i < b.size(); i++) {
        string t(1, b[i - 1]);
        t += b[i];
        m1[t]++;
    }
    int g = 0;
    for (auto x: m) {
        if (m1[x.first] > 0)
            g += x.second;
    }
    cout << g << endl;
}