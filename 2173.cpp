
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define inf 1000000000
int n, s, f;
vector<int> weights;
vector<vector<int>> G;

void dijkstra() {
    vector<int> d(n, inf);
    vector<bool> used(n, false);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int id = 0;
        int min = inf;
        for (int j = 0; j < n; j++) {
            if (min > d[j] and !used[j]) {
                min = d[j];
                id = j;
            }
        }
        used[id] = true;
        for (auto a: G[id]) {
            if (d[a] > d[id] + weights[id])
                d[a] = d[id] + weights[id];
        }
    }
    if (d[f] == inf)
        cout << -1 << endl;
    else
        cout << d[f] << endl;
}

int main() {
    cin>>n;
    s=0;
    f=n-1;
    weights.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>weights[i];
    }
    G.resize(n);
    int m;
    cin>>m;
    while (m--)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dijkstra();
}
