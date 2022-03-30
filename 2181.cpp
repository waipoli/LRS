
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define int long long
#define inf 100000

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
            if (G[i][j] == 0 and i != j)
                G[i][j] = inf;
        }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (G[i][k] < inf && G[k][j] < inf)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int t = 0; t < n; ++t) {
                if (G[i][t] < inf && G[t][t] < 0 && G[t][j] < inf) {
                    G[i][t] = -inf;
                    G[t][j] = -inf;
                    G[i][j] = -inf;
                }
            }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == -inf) {
                cout << 2 << " ";
            } else if (G[i][j] < inf) {
                cout << 1 << " ";
            } else
                cout << 0 << " ";
        }
        cout << endl;
    }
}
