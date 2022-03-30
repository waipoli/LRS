#include<iostream>
#include<vector>
#include<map>

using namespace std;
#define int long long

bool set(vector<vector<int>> &ff, vector<vector<int>>& xxx, int x, int y) {
    for (int i = 0; i < xxx.size(); i++)
        for (int j = 0; j < xxx[0].size(); j++) {
            if (x + i >= ff.size())
                return false;
            if (y + j >= ff.size())
                return false;
//            int ggf=ff[x+i][y+j];
            ff[x + i][y + j] += xxx[i][j];
            if(ff[x+i][y+j] >= 3)
                return false;
        }
    return true;
}

signed main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> house(a, vector<int>(b, 0));
    vector<vector<int>> lake(a, vector<int>(b, 0));
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++) {
            char c;
            cin >> c;
            if (c == '.')
                house[i][j] = 0;
            else
                house[i][j] = 1;
        }
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++) {
            char c;
            cin >> c;
            if (c == '.')
                lake[i][j] = 0;
            else
                lake[i][j] = 2;
        }
    int c = max(a, b) * 2 + 50;
    vector<vector<int>> world(c, vector<int>(c, 0));
    vector<vector<int>> worldT(c,vector<int>(c, 0));
    pair<int, int> x1;
    pair<int, int> x2;
    int md = 0;
    int i=25,j=25;
    set(worldT,house,i,j);
    for (int x = 0; x < c; x++) {
        for (int y = 0; y < c; y++) {
            world = worldT;
            bool fs = set(world, lake, x, y);
            if (fs) {
                int ls = 0;
                int id = 0;
                bool flag = true;
                if (flag) {
                    for (int d = 0; d < c; d++) {
                        for (int k = 0; k < c; k++) {
                            if (d != world.size() - 1 and world[d][k] == 1 and world[d + 1][k] == 2) {
                                ls++;
                            }
                            if (k != world[0].size() - 1 and world[d][k] == 1 and world[d][k + 1] == 2) {
                                ls++;
                            }
                            if (d != 0 and world[d][k] == 1 and world[d - 1][k] == 2) {
                                ls++;
                            }
                            if (k != 0 and world[d][k] == 1 and world[d][k - 1] == 2) {
                                ls++;
                            }
                        }
                    }
                }

                if (md < ls) {
                    md = ls;
                }
            }
        }

    }

    cout << md << endl;
}

