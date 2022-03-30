#include<iostream>
using namespace std;
#define mod 1000000007
#define int long long
signed main()
{
    int n;
    cin>>n;
    int a=n;
    int b=n+1;
    if(a % 2 == 0)
        a/=2;
    else
        b/=2;
    a*=a;
    b*=b;
    a%=mod;
    b%=mod;
    int ans=a*b;
    ans%=mod;
    cout<<ans<<endl;
}
