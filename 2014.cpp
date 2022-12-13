#include<iostream>
using namespace std;
#define int long long

int K;
#define mod K
int binMult(int a,int b)
{
    if(b == 0)
        return 0;
    if(b % 2 == 0)
    {
        int x=binMult(a,b/2);
        x%=mod;
        return (x+x) % mod;
    }
    return (binMult(a,b-1) % mod + a)% mod;
}

int binPow(int a,int b)
{
    if(b == 0)
        return 1;
    if(b % 2 == 0)
    {
        int x=binPow(a,b/2);
        x%=mod;
//        cout<<a<<" "<<b<<" "<<x<<endl;
        return binMult(x,x);
    }
    return binMult(binPow(a,b-1) % mod,a);
}



signed main()
{
    int A,B,N,M;
    cin>>A>>B>>N>>M>>K;
    cout<<(binPow(A,N)+binPow(B,M)) % mod<<endl;
}
