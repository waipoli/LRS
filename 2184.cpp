
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define int long long
#define inf 10000000000
struct edge {
    int a, b, w;
};
vector<edge> edges;

signed main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back({a, b, c});
    }
    vector<int> d(n, inf);
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto edge: edges) {
            d[edge.b] = min(d[edge.b], d[edge.a] + edge.w);
        }
    }
    for (long long i : d) {
        if (i >= 30000)
            cout << 30000 << " ";
        else
            cout << i << " ";
    }
}
