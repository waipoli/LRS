
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define inf 1000000000
int n, s, f;
struct Road {
    int end; //vertex
    int weights;
    int k; // Company
};

vector<vector<Road>> G;
int K;

void dijkstra() {
    vector<vector<int>> d(K , vector<int>(n, inf));
    vector<vector<bool>> used(K , vector<bool>(n, false));
    d[0][s] = 0;
    for (int ghgh = 0; ghgh < K * n; ghgh++) {
        int id = 0;
        int comp = 0;
        int min=inf;
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][j] < min and !used[i][j]) {
                    comp = i;
                    id = j;
                    min=d[i][j];
                }
            }
        }
        used[comp][id] = true;
        for (auto x: G[id]) {
            if (x.k != comp or (id == s and comp == 0)) {
                if (d[x.k][x.end] > d[comp][id] + x.weights) {
                    d[x.k][x.end] = d[comp][id] + x.weights;
                }
            }
        }
    }
    int min = inf;
    for (int i = 0; i < K; i++) {
        if (min > d[i][f])
            min = d[i][f];
    }
    if (min == inf)
        cout << -1 << endl;
    else
        cout << min << endl;
}

int main() {
    cin >> n;
    G.resize(n);
    int m;
    cin >> K;cin >> m;
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        d--;
        G[a].push_back({b, c, d});
//        G[b].push_back({a, c, d});
    }
    cin >> s >> f;
    s--;
    f--;
    dijkstra();
}
