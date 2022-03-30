#include <iostream>
#include<vector>
#include <algorithm>
#include <map>

using namespace std;

#define INF 1000000000

int main() {
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int ks;
            cin >> ks;
            if (ks == -1) {
                d[i][j] = INF;
                d[j][i] = INF;
            } else {
                d[i][j] = ks;
                d[j][i] = ks;
            }
        }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int max = -1, min = 1000000000;
    for (int i = 0; i < n; i++) {
        int max_ = -1;
        for (int j = 0; j < n; j++) {
            if (max < d[i][j])
                max = d[i][j];
            if(max_ < d[i][j])
            {
                max_= d[i][j];
            }
        }
        if (min > max_)
            min = max_;
    }
    cout << max << " " << min << endl;
}
