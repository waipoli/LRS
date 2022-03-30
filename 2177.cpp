#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define inf 1000000000
int n, s, f;
vector<vector<pair<int,int>>> G;

void dijkstra() {
    vector<long double> d(n, -1);
    vector<bool> used(n, false);
    d[s] = 1;
    for (int i = 0; i < n; i++) {
        int id = 0;
        long double min = -1;
        for (int j = 0; j < n; j++) {
            if (min < d[j] and !used[j]) {
                min = d[j];
                id = j;
            }
        }
        used[id] = true;
        for (auto a: G[id]) {
            if (d[a.first] < d[id]*((100-a.second) / 100.0))
                d[a.first] = d[id] *((100-a.second) / 100.0);
        }
    }

        cout << 1.0-d[f] << endl;
}

int main() {
    int m;
    cin>>n>>m;
    cin>>s>>f;
    s--;
    f--;
    G.resize(n);
//    int m;
    while (m--)
    {
        int a,b,z;
        cin>>a>>b>>z;
        a--;
        b--;
        G[a].push_back({b,z});
        G[b].push_back({a,z});
    }
    dijkstra();
}
