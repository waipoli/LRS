#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;

signed main()
{
    int n,k;
    cin>>n>>k;
    k--;
    vector<int> fact(16);
    fact[0]=1;
    for(int i=1;i<=15;i++)
        fact[i]=fact[i-1]*i;
    vector<int> nums;
    for(int i=1;i<=n;i++)
    {
        nums.push_back(i);
    }

    vector<int> ans;
    for(int i=n-1;i>=0;i--)
    {
        int delta=(k) / fact[i];
        ans.push_back(nums[delta]);
        nums.erase(nums.begin()+delta);
        k-=fact[i]*delta;
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
