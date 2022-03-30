#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
#define int long long
#define inf 1000000000000
int n,m;
vector<vector<int>> heavies;
int s,f;
vector<pair<int,int>> moves = {{0,-1},{-1,0}};
vector<vector<pair<int,int>>> pp;
vector<vector<int>> cheat;
int get(pair<int,int> cord)
{
    if(cord.first < 0 or cord.second < 0 or cord.first >=n or cord.second >=m)
        return inf;
    if(cheat[cord.first][cord.second] != -1)
    {
        return cheat[cord.first][cord.second];
    }
    int min=inf;
    pair<int,int> id;
    for(auto move : moves)
    {
        pair<int,int> next={cord.first + move.first,cord.second+move.second};
        int dist=get(next);
        if(dist < min)
        {
            min=dist;
            id=next;
        }
    }
    pp[cord.first][cord.second] = id;
    cheat[cord.first][cord.second] = min + heavies[cord.first][cord.second];
    return min + heavies[cord.first][cord.second];
}



signed main()
{
    cin>>n>>m;
    heavies.resize(n,vector<int>(m,0));
    cheat.resize(n,vector<int>(m,-1));
    pp.resize(n,vector<pair<int,int>>(m, {-1,-1}));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%lld",&heavies[i][j]);
//            cin>>heavies[i][j];
    cheat[0][0]=heavies[0][0];

    cout<<get({n-1,m-1})<<endl;
    pair<int, int> df = {n-1,m-1};
    vector <pair<int, int>> kk;
    while (df.first != -1 and df.second != -1) {
        kk.push_back({df.first + 1, df.second + 1});
//        cout << df.first + 1 << " " << df.second + 1 << endl;
        df = pp[df.first][df.second];
    }
    reverse(kk.begin(), kk.end());
    cout << kk.size() << endl;
    for (auto x: kk)
        printf("%lld %lld\n", x.first, x.second);
//        cout << x.first << " " << x.second << endl;
}
