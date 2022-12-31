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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<int>>> mtr(n, vector<vector<int>>(m, vector<int>(k, 0)));
    vector<vector<vector<int>>> pref(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int h = 0; h < k; h++) {
                cin >> mtr[i][j][h];
                pref[i + 1][j + 1][h + 1] = pref[i][j][h + 1] + pref[i][j + 1][h] + pref[i + 1][j][h] -
                                            pref[i + 1][j + 1][h] - pref[i + 1][j][h + 1] - pref[i][j + 1][h + 1] -
                                            pref[i][j][h] + mtr[i][j][h];
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        cout << pref[x2][y2][z2] - pref[x2][y1 - 1][z2] - pref[x1 - 1][y2][z2] - pref[x2][y2][z1 - 1] +
                pref[x2][y1 - 1][z1 - 1] + pref[x1 - 1][y2][z1 - 1] + pref[x1 - 1][y1 - 1][z2]
             <<
             endl;
    }
}
