#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
string to2(int n, int k)
{
  string ans="";
  while(n)
  {
    ans=char((n % 2)+ int('0')) + ans;
    n/=2;
  }
  while(ans.size() != k)
 	ans='0'+ ans;
  return ans;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<(1<<n);i++)
	{

        int count=0;
        string s=to2(i,n);
		for(int x=0;x<n;x++)
        {
            count+=s[x] - 48;
        }
        cout<<count<<" ";
        for(int x=0;x<n;x++)
        {
            if(s[x] - 48 != 0)
                cout<<x+1<<" ";
        }
        cout<<endl;
	}
}
