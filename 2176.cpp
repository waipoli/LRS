
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define x first
#define y second
#define inf 1000000000
int n;
int s=0;
int f=1;


vector<pair<int,int>> G;

long double dist(int a,int b){
  return sqrt(pow(G[a].x-G[b].x,2) + pow(G[a].y-G[b].y,2));
}

void dijkstra(){
  vector<long double> d(n,inf);
  vector<bool> used(n);
  d[s]=0;
  for(int i=0;i<n;i++)
  {
    long double min =inf;
  	int id=0;
  	for(int j=0;j<n;j++)
  	{
  	  if(d[j] <min && used[j] == false){
  	    min=d[j];
  	    id=j;
  	  }
  	}
  	used[id]=true;
  	for(int j=0;j<n;j++)
  	{
  	  if(d[j] > max(d[id] , dist(id,j)))
  	  	d[j]=max(d[id] , dist(id,j));
  	}
  }
  cout<<d[f]<<endl;
}

int main()
{
  cin>>n;
  G.resize(n);
  for(int i=0;i<n;i++)
  cin>>G[i].x>>G[i].y;
  dijkstra();
}
