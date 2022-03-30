#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> dp(n,0);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        int tk=1;
        while(tk <= k and i-tk >=0)
        {
            dp[i]+=dp[i-tk];
            tk++;
        }
    }

    cout<<dp[n-1]<<endl;
}
