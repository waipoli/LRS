#include<iostream>
#include<vector>
#include<deque>
using namespace std;
const int Max=100005;
vector<vector<int>> G(Max);
vector<int> used;
deque<int> d; 
void dfs(int v){
if(used[v] ==2)
return;
  used[v]=1;
  for(auto a : G[v]){
    if(used[a] == 1){
cout<<-1<<endl;
      exit(0);
      continue;
    }
     dfs(a);
  }
  used[v]=2;
   d.push_front(v+1);
} 
 

int main(){
  int n,m;
  cin>>n>>m;
  while(m--){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G[a].push_back(b);
  }
  used.resize(n);
  for(int i=0;i<n;i++){
    if(used[i] == 2)
      continue;
    dfs(i);
  }
  for(auto a : d)
  cout<<a<<" ";
  cout<<endl;
}
