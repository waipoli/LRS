
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define int long long
#define inf 1000000000000000000

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
            if (G[i][j] == -1) {
                G[i][j] = inf;
            }
        }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (G[i][k] != -1 && G[k][j] != -1)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }

    int max_ = -inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] != inf)
                max_ = max(G[i][j], max_);
//            cout << G[i][j] << " ";
        }
//        cout << endl;
    }
    if (max_ == inf)
        cout << -1 << endl;
    else
        cout << max_ << endl;
}
