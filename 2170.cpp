#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Point {
    bool flag;
    int prevx;
    int prevy;
};

int main() {
    int x1, y1, x2, y2;
    string a;
    string b;
    cin >> a >> b;
    x1 = a[0] - 'a';
    x2 = b[0] - 'a';
    y1 = a[1] - '1';
    y2 = b[1] - '1';
    vector<vector<Point>> G;
    G.resize(8, vector<Point>(8));
    queue<pair<int, int>> q;
    q.push({x1, y1});
    G[x1][y1] = {true, -1, -1};
    if (x1 == x2 and y1 == y2) {
        cout << 0 << endl;
        return 0;
    }
    vector<pair<int, int>> moves = {{1, 2},
                                    {1,  -2},
                                    {-1,  2},
                                    {-1, -2},
                                    {2, 1},
                                    {2,  -1},
                                    {-2,  1},
                                    {-2, -1}};
    int wave = 0;
    while (!q.empty()) {
        int st = q.size();
        for (int h = 0; h < st; ++h) {
            pair<int, int> point = q.front();
            q.pop();
            for (auto move: moves) {

                pair<int, int> next = {point.first + move.first, point.second + move.second};
                if(next.first <= -1 or next.second <= -1 or next.first >= 8 or next.second >=8)
                {
                    continue;
                }
                if (!G[next.first][next.second].flag) {
                    G[next.first][next.second].prevx = point.first;
                    G[next.first][next.second].prevy = point.second;
                    q.push({next.first, next.second});
                }
            }
            G[point.first][point.second].flag=true;
        }
        wave++;
    }
    vector<string> vs;
    while (x2 != -1 and y2  != -1) {
        string ans(1,char(x2 + 'a'));
        ans+=char(y2 + '1');
        vs.push_back(ans);
//        cout<<char(x2 + 'a')<<""<<char(y2+'1')<<endl;
        int x3=x2;
        x2 = G[x2][y2].prevx;
        y2 = G[x3][y2].prevy;
    }
    reverse(vs.begin(), vs.end());
    for(auto ad : vs)
    {
        cout<<ad<<endl;
    }
}
