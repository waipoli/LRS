#include<iostream>
#include<vector>
using namespace std;
#define int long long


signed main()
{
    int n;
    cin>>n;
    //0 - 00
    //1 - 10
    //2 - 01
    //3 - 11
    vector<vector<int>>dp(4,vector<int>(n+1,0));
    dp[2][1]=1;
    dp[0][1]=1;
//    dp[1][1]=1;
//    dp[3][1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[0][i]=dp[1][i-1] + dp[0][i-1];
        dp[1][i]=dp[2][i-1]+dp[3][i-1];
        dp[2][i]=dp[0][i-1]+dp[1][i-1];
        dp[3][i]=dp[2][i-1];
    }

    cout<<dp[0][n]+dp[1][n]+dp[2][n]+dp[3][n]<<endl;
}
