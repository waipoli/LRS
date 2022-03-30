#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> G;
vector<bool> used;

void dfs(int v,int p)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int a;
        if(G[v][i] == 1)
        {
            a=i;
        }
        else
            continue;
        if(used[a]  and a != p)
        {
            cout<<"NO"<<endl;
            exit(0);
        }
        if(a == p)
            continue;
        dfs(a,v);
    }
}

int main() {
    int n;
    cin >> n;
    used.resize(n);
    G.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> G[i][j];
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(used[i])
            continue;
        count++;
        dfs(i,-1);
    }
    if(count > 1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
}
