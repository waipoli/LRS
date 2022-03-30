
#include<iostream>
#include<vector>
using namespace std;
struct data_{
  int start;
  int finish;
};
#define inf 1000000000
int n;
int s,f;
vector<vector<pair<int,data_>>> G;

void dijkstra()
{
  vector<int> d(n,inf);
  vector<bool> used(n,false);
  d[s]=0;
  for(int i=0;i<n;i++)
  {
    int min=inf;
    int id=0;
    for(int j=0;j<n;j++)
    {
      if(!used[j] and d[j] < min)
      {
        min=d[j];
        id=j;
      }
    }
    used[id] = true;
    for(auto a : G[id])
    {
      if(a.second.start < d[id])
      	continue;
      if(d[a.first] > a.second.finish)
      	d[a.first] = a.second.finish;
    }
  }
  if(d[f] == inf)
  cout<<-1<<endl;
  else
  cout<<d[f]<<endl;
}


int main()
{
 
  cin>>n;
  cin>>s>>f;
  s--;
  f--;
  G.resize(n);
  int m;
  cin>>m;
  while(m--)
  {
    int a,b,c,d;
    cin>>a>>c>>b>>d;
    a--;
    b--;
    data_ df;
    df.start=c;
    df.finish=d;
    G[a].push_back({b,df});
  }
  
  dijkstra();
}
