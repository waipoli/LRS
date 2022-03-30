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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2 * n - 1, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1 + i * 2; j++) {
            cin >> v[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        reverse(v[i].begin(), v[i].end());
        reverse(v[i].end() - (1 + 2 * i), v[i].end());
    }
    vector<vector<int>> vx(2 * n - 1, vector<int>(n, -1));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 2 * n - 1; j++) {
//            cout << v[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << "---------------------" << endl;
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j][i] == -1)
                continue;
            vx[i][j] = v[j][i];
        }
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (vx[i][j] == -1)
                continue;
            else {
                reverse(vx[i].end() - (n - j), vx[i].end());
                break;
            }
        }
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (vx[i][j] == -1)
                continue;
            v[j][i] = vx[i][j];
        }
    }
    for (int i = 0; i < n; i++)
        reverse(v[i].begin(), v[i].end());

    string s;
    cin >> s;
    if (s == "clockwise") {
        for (int i = 0; i < n; i++) {
            reverse(v[i].begin(), v[i].end());
            reverse(v[i].end() - (1 + 2 * i), v[i].end());
        }
        std::fill(vx.begin(), vx.end(), vector<int>(n, -1));
//        vector<vector<int>> vx(2 * n - 1, vector<int>(n, 0));

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (v[j][i] == -1)
                    continue;
                vx[i][j] = v[j][i];
            }
        }
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (vx[i][j] == -1)
                    continue;
                else {
                    reverse(vx[i].end() - (n - j), vx[i].end());
                    break;
                }
            }
        }
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (vx[i][j] == -1)
                    continue;
                v[j][i] = vx[i][j];
            }
        }
        for (int i = 0; i < n; i++)
            reverse(v[i].begin(), v[i].end());
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            if (v[i][j] != -1)
                cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
