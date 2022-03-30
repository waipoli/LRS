#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int main() {
    int n, m, w;
    cin >> n;
    cin >> m;
    cin >> w;
    vector<vector<vector<int>>> d;
    vector<vector<vector<tuple<int, int, int>>>> P;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    a.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    b.resize(m);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    c.resize(w);
    for (int i = 0; i < w; i++)
        scanf("%d", &c[i]);

    d.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(w + 1, -1)));
    P.resize(n + 1, vector<vector<tuple<int, int, int>>>(m + 1, vector<tuple<int, int, int>>(w + 1, {-1, -1, -1})));
    
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int h = 0; h <= w; ++h) {
                if (i == 0 or j == 0 or h == 0) {
                    d[i][j][h] = 0;
                    continue;
                }
                if (a[i - 1] == b[j - 1] and b[j - 1] == c[h - 1]) {
                    P[i][j][h] = {i - 1, j - 1, h - 1};
                    d[i][j][h] = d[i - 1][j - 1][h - 1] + 1;
                } else {
                    int u1, u2, u3;
                    u1 = d[i - 1][j][h];
                    u2 = d[i][j - 1][h];
                    u3 = d[i][j][h - 1];
                    if (u1 >= u2 and u1 >= u3) {
                        d[i][j][h] = u1;
                        P[i][j][h] = {i - 1, j, h};
                        continue;
                    }
                    if (u2 >= u1 and u2 >= u3) {
                        d[i][j][h] = u2;
                        P[i][j][h] = {i, j - 1, h};
                        continue;

                    }
                    if (u3 >= u1 and u3 >= u2) {
                        d[i][j][h] = u3;
                        P[i][j][h] = {i, j, h - 1};
                        continue;

                    }
                }
            }

    cout << d[n][m][w] << endl;

    tuple<int, int, int> f = {n, m, w};
    vector<int> g;
    while (get<0>(f) >= 0 and get<1>(f) >= 0 and get<2>(f) >= 0) {
        if (P[get<0>(f)][get<1>(f)][get<2>(f)] == tuple<int, int, int>(get<0>(f) - 1, get<1>(f) - 1, get<2>(f) - 1)) {
            g.push_back(a[get<0>(f) - 1]);
        }
        f = P[get<0>(f)][get<1>(f)][get<2>(f)];
    }
    reverse(g.begin(), g.end());
    for (auto x: g)
        cout << x << " ";
    cout << endl;
}
