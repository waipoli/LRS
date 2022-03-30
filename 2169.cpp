
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;


int main() {
    int n;
    int s;
    int f;
    cin >> n >> s >> f;
    s--;
    f--;
    vector<vector<int>> G;
    G.resize(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>G[i][j];
        }
    }
    vector<bool> used(n);
    queue<int> q;
    if(s == f) {
        cout <<0<<endl;
        return 0;
    }
    int wave=0;
    q.push(s);
    while (!q.empty())
    {
        int st=q.size();
        for(int i=0;i<st;i++)
        {
            int id=q.front();
            q.pop();
            for(int j=0;j<n;j++)
            {
                if(G[id][j] == 0)
                    continue;

                if(j == f)
                {
                    cout<<wave+1;
                    return 0;
                }
                if(!used[j])
                    q.push(j);
            }
        }
        wave++;
    }
    cout<<0<<endl;

