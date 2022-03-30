#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;
#define int long long
vector<vector<int>> v;
vector<int> used;

void dfs(int id, int color) {
    used[id] = color;
    for (int i = 0; i < v.size(); i++) {
        if (v[id][i] != 0 and used[i] == -1) {
            dfs(i, color);
        }
    }
}

signed main() {
    int n;
    cin >> n;
    used.resize(n, -1);
    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }

    int count = 1;
    for (int i = 0; i < used.size(); i++) {
        if (used[i] == -1) {
            dfs(i, count);
            count++;
        }
    }
    cout<<count-1<<endl;
}
