#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

string to2(int n, int k)
{
    string ans="";
    while(n)
    {
        ans=char((n % 2)+ (int)('0')) + ans;
        n/=2;
    }
    while(ans.size() != k)
        ans='0'+ ans;
    return ans;
}
int g (int n) {
	return n ^ (n >> 1);
}
signed main()
{
    int n;
    cin>>n;
    for(int i=0; i<(1<<n); i++)
    {
        cout<<to2(g(i),n)<<endl;
    }
}
