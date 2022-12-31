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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mtr(n, vector<int>(m, 0));
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> mtr[i][j];
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + mtr[i][j];
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << pref[i + 1][j + 1] << " ";
        }
        cout << endl;
    }
}
