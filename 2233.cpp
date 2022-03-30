#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;


signed main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=100000000000;
    dp[2]=v[1]-v[0];
    for(int i=2;i<=n;i++)
    {
        dp[i]=min(dp[i-1]+v[i-1]-v[i-2],dp[i-2]+v[i-1]-v[i-2]);
    }
    cout<<dp[n]<<endl;
}
