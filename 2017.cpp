#include <cstddef>
#include<iostream>
#include <sched.h>
#include <sys/types.h>
#include<vector>

using namespace std;
#define int long long

int K;
#define mod K
#define mtr vector<vector<int>>
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
mtr binMatrixMult(mtr a, mtr b)
{

    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            a[i][j] %= mod;
            b[i][j] %= mod;
        }
    }
    mtr C;
    C.resize(a.size(),vector<int>(a.size(),0));
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < a.size(); j++)
        {
            for(int k = 0; k < a.size(); k++){
                C[i][j] += (a[i][k]*b[k][j]) % mod;
                C[i][j] %= mod;
            }
            C[i][j]%=mod;
        }
    return C;
}

mtr binMatrixPow(mtr a,int n)
{
    if(n == 1)
    {
        return a;
    }

    if(n % 2 == 0)
    {
        mtr x = binMatrixPow(a,n / 2);
        return binMatrixMult(x,x);
    }
    return binMatrixMult(binMatrixPow(a,n-1),a);
}


signed main()
{
    int S,N;
    cin>>S;
    mtr v(S,vector<int>(S));
    for(int i=0;i<S;i++)
    {
        for(int j=0;j<S;j++)
        {
            cin>>v[i][j];
        }
    }
    cin>>N>>K;
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v.size();j++)
            v[i][j] %= mod;
    mtr sd = binMatrixPow(v,N);
    for(int i=0;i<S;i++)
    {
        for(int j=0;j<S;j++)
        {
            cout<<sd[i][j]<<" ";
        }
        cout<<"\n";
    }
}
