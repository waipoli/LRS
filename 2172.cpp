
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long 
#define inf 1000000000
int n,s,f;
vector<vector<int>> G;
void dijkstra()
{
  vector<int>d(n,inf);
  vector<bool>used(n,false);
  d[s]=0;
  for(int i=0;i<n;i++)
  {
    int id=0;
    int min=inf;
    for(int j=0;j<n;j++)
    {
      if(min > d[j] and used[j] == false)
      {
      	min=d[j];
      	id=j;	  
      }
    }
    used[id]=true;
    for(int j=0;j<n;j++)
    {
      if(G[id][j] == -1)
      	continue;
      if(d[j] > d[id] + G[id][j])
      {
        d[j]=d[id]+G[id][j];
      }
    }
  }
  if(d[f] == inf)
  cout<<-1<<endl;
  else
  cout<<d[f]<<endl;
}

signed main(){
  cin>>n>>s>>f;
  s--;
  f--;
G.resize(n,vector<int>(n,0));
  for(int i=0;i<n;i++)
  	for(int j=0;j<n;j++)
  		cin>>G[i][j];
  dijkstra();
  return 0;
}
