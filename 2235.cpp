#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<vector<int>> mtr;
vector<pair<int,int>> moves = {{-1,-2},{-2,-1}};

int get(int x,int y)
{
    if(mtr[x][y] != -1)
        return mtr[x][y];
    int ldd=0;
    for(auto move : moves)
    {
        pair<int,int> xd={x + move.first,y+move.second};
        if(xd.first < 0 or xd.second < 0 or xd.first >= n or xd.second >= m)
        {
            continue;
        }
        ldd+=get(xd.first,xd.second);
    }
    mtr[x][y]=ldd;
    return ldd;
}





signed main()
{
    cin>>n>>m;
    mtr.resize(n,vector<int>(m,-1));
    mtr[0][0]=1;
    int x,y;
    x=n-1;
    y=m-1;
    cout<<get(x,y)<<endl;
}
