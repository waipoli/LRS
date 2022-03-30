#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <set>

using namespace std;
#define int long long
#define endl "\n"
#define inf 100000000000
int n;
vector<vector<pair<int, int>>> G;

vector<int> dijkstra(int s) {
    vector<int> d(n, inf);
    vector<bool> used(n, false);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int min = inf;
        int id = 0;
        for (int j = 0; j < n; j++) {
            if (min > d[j] and !used[j]) {
                min = d[j];
                id = j;
            }
        }

        used[id] = true;
        for (auto x: G[id]) {
            if (d[x.first] > d[id] + x.second)
                d[x.first] = d[id] + x.second;
        }
    }
    return d;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int m;
    cin >> m;
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    vector<int> l = dijkstra(0);
    vector<int> r = dijkstra(1);
    vector<pair<int, int>> delta;
    for (int i = 0; i < n; i++)
        delta.push_back({l[i] - r[i], i});
    sort(delta.begin(), delta.end());
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(i);
    for (int i = 0; i < n / 2; i++) {
        s.erase(s.find(delta[i].second));
        cout << delta[i].second + 1 << " ";
    }
    cout << endl;
    for (auto a: s)
        cout << a + 1 << " ";
    return 0;
}
