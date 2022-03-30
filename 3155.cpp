#include<iostream>
#include<vector>
#include<algorithm>
#include <map>

#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
//    map<int, vector<int>> l;
    map<int, vector<int>> r;
    for (int i = 0; i < n; i++) {
//        l[v[i].first].push_back(i);
        r[v[i].second].push_back(i);
    }

    vector<int> d(n + 5, 0);
    for (int i = 0; i < n; ++i) {
        d[i] = 1;
        for(auto j : r[v[i].first])
        {
            if (v[j].second == v[i].first and j < i)
                d[i] = max(d[i], 1 + d[j]);
        }
//        for (int j = 0; j < i; ++j)
    }
    int ans = d[0];
    for (int i = 0; i < n; ++i)
        ans = max(ans, d[i]);
    cout << ans << endl;
}
