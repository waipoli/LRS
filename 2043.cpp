#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
string tok(int n, int h,int k)
{
  string ans="";
  while(n)
  {
    ans=char((n % k)+ int('0')) + ans;
    n/=k;
  }
  while(ans.size() != h)
 	ans='0'+ ans;
  return ans;
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<pow(k,n);i++)
	{
		cout<<tok(i,n,k)<<endl;
	}
}
