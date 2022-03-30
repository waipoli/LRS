
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
vector<vector<int>> v;
int main()
{
  cin>>n>>m;
  v.resize(m,vector<int>(n,0));
  for(int i =0;i<n;i++)
  	for(int j=0;j<m;j++)
  		cin>>v[j][i];
  int x1,y1;
  int x2,y2;
  cin>>x1>>y1>>x2>>y2;
  x1--;
  y1--;
  x2--;
  y2--;
  if(x1 == x2 and y1 == y2)
  {
    cout<<0<<endl;
    return 0;
  }
  queue<pair<int,int>> q;
  q.push({x1,y1});
  vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
  int wave=1;
  while(!q.empty())
  {
    int st=q.size();
    for(int hh=0;hh<st;hh++)
    {
      pair<int,int> pos=q.front();
      q.pop();
      for(auto move : moves)
      {
        pair<int,int> nextPos={pos.first+move.first,pos.second+move.second};
        if(nextPos.first < 0 || nextPos.first >= m || nextPos.second < 0 || nextPos.second >= n)
        {
          continue;
        }
        if(v[nextPos.first][nextPos.second] == 0)
        {
        if(nextPos.first == x2 and nextPos.second == y2)
        {
          cout<<wave<<endl;
          return 0;
        }
        v[nextPos.first][nextPos.second]=1;
          q.push(nextPos);
        }
      }
    }
    wave++;
  }
  cout<<-1<<endl;
  return 0;
}
