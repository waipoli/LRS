#include<iostream>
using namespace std;
#define int long long
#define mod 1000000007
signed main(){
    int n;
    cin>>n;
    int a=n;
    int b=n+1;
    int c=2*n+1;
    if(a % 3 == 0)
        a/=3;
    else if(b % 3 == 0)
        b/=3;
    else
        c/=3;
    if(a % 2 == 0)
        a/=2;
    else if(b % 2 == 0)
        b/=2;
    else
        c/=2;
   
    a %= mod;
    b %= mod;
    c %= mod;
    cout<<(((a*b) % mod)*c) % mod<<endl;
}
