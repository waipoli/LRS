#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
#define int long long
#define inf 1000000000000
int n, m;
vector<vector<int>> heavies;
vector<pair<int, int>> moves = {{-1, 0},
                                {-1, -1},
                                {-1, 1}};
vector<vector<pair<int, int>>> cheat;
int id = 0;

pair<int, int> get(pair<int, int> cord) {
    if (cord.first < 0 or cord.second < 0 or cord.first >= n or cord.second >= m)
        return {-inf - 3, 0};
    if (cord.first == 0 and cord.second != id)
        return {-inf - 3, 0};
    if (cheat[cord.first][cord.second].first != -inf) {
        return cheat[cord.first][cord.second];
    }
    int min = -inf;
    int count = 0;
    for (auto move: moves) {
        pair<int, int> next = {cord.first + move.first, cord.second + move.second};
        pair<int, int> dist = get(next);
        if (dist.first > min) {
            min = dist.first;
            count = dist.second;
        } else if (dist.first == min) {
            count += dist.second;
        }
    }
    cheat[cord.first][cord.second] = {min + heavies[cord.first][cord.second], count};
    return {min + heavies[cord.first][cord.second], count};
}


signed main() {
    cin >> n >> m;
    heavies.resize(n, vector<int>(m, 0));
    cheat.resize(n, vector<pair<int, int>>(m, {-inf, 0}));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%lld", &heavies[i][j]);
//            cin>>heavies[i][j];

    pair<int, int> max = {-inf, -1};
    for (int j = 0; j < m; j++) {
        std::fill(cheat.begin(), cheat.end(), vector<pair<int, int>>(m, {-inf, 0}));
//        cheat.resize(n, );
        for (int i = 0; i < m; i++)
            cheat[0][i] = {heavies[0][i], 1};
        id = j;
        for (int i = 0; i < m; i++) {
            pair<int, int> dfff = get({n - 1, i});
            if (max.first < dfff.first) {
                max = dfff;
            } else if (max.first == dfff.first) {
                max.second += dfff.second;
            }
        }
    }
    cout << max.first << " " << max.second << endl;
}
