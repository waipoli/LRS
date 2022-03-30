#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;

signed main()
{
    vector<int> fact(16);
    fact[0]=1;
    for(int i=1;i<=15;i++)
        fact[i]=fact[i-1]*i;

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        nums[i]=i+1;
    }
    int k=1;
    for(int i=0;i<n;i++)
    {
        int id=(n-i-1);
        int gf=find(nums.begin(),nums.end(),v[i]) - nums.begin();
        nums.erase(nums.begin()+gf);
        k+=fact[id]*gf;
    }
    cout<<k<<endl;
}
