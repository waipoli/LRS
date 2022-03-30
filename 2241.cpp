#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
vector<int> a;
vector<int> b;
int n,m;
vector<vector<int>> d;
int F(int i,int j)
{
    if(i == 0 || j == 0)
        return 0;
    if(d[i][j] != -1)
        return d[i][j];

    if(a[i-1] == b[j-1])
    {
        d[i][j]=F(i-1,j-1)+1;
        return d[i][j];
    }
    else
    {
        d[i][j] = max(F(i-1,j),F(i,j-1));
        return d[i][j];
    }
}

int main()
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    b.resize(m);
    for(int i=0;i<m;i++)
        cin>>b[i];
    d.resize(n+1,vector<int>(m+1,-1));
    cout<<F(n,m);
}

