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
    vector<vector<int>> d(3,vector<int>(n, inf));
    vector<vector<bool>> used(3,vector<bool>(n, false));
    d[0][0]=0;
    for (int w = 0; w < 3; w++) {
        for (int h = 0; h < n; h++) {
            int min = inf;
            pair<int, int> p;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < n; j++) {
                    if (!used[i][j] and d[i][j] < min) {
                        p.first = i;
                        p.second = j;
                        min = d[i][j];
                    }
                }
            used[p.first][p.second] = true;
            if(p.first !=2)
            {
                if(d[p.first+1][p.second] > d[p.first][p.second] +weights[p.second])
                {
                    d[p.first+1][p.second] = d[p.first][p.second] + weights[p.second];
                }
            }
            if(p.first)
            {
                for(auto a :G[p.second])
                {
                    if(d[p.first-1][a] > d[p.first][p.second] )
                        d[p.first-1][a]=d[p.first][p.second];
                }
            }
        }
    }
    int ans = min(d[0][n - 1], min(d[1][n - 1], d[2][n-1]));
    cout << (ans != inf ? ans : -1);
}

int main() {
    cin >> n;
    s = 0;
    f = n - 1;
    weights.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    G.resize(n);
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dijkstra();
}
