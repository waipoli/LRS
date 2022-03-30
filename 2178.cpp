#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inf 1000000000
int main()
{
  int n;
  cin>>n;
  vector<vector<int>> G(n,vector<int>(n,inf));
  for(int i=0;i<n;i++)
  	for(int j=0;j<n;j++)
  	{
  	  cin>>G[i][j];
  	}
  	
  for(int k=0;k<n;k++)
  	for(int i=0;i<n;i++)
  		for(int j=0;j<n;j++)
  			G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
  
  for(int i=0;i<n;i++){
  	for(int j=0;j<n;j++)
  	{
  	  cout<<G[i][j]<<" ";
  	}  
  	cout<<endl;	
  }
}
