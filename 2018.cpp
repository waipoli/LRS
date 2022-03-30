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
#define vi vector<int>
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

vi binRowMult(vi a,vi b)
{
    int n=a.size();
    vi ans;
    for(int i=0;i<n;i++)
    {
        ans.push_back(a[b[i]-1]);
    }
    return ans;
}

vi binRowPow(vi a,int n)
{
    if(n == 1)
        return a;
    if(n % 2 == 0)
    {
        vi x= binRowPow(a,n / 2);
        return binRowMult(x,x);
    }
    return binRowMult(binRowPow(a,n-1),a);

}
signed main()
{
    int N,K;
    cin>>N>>K;
    vi v(N,0);
    for(int i=0;i<N;i++)
    {
        scanf("%lld",&v[i]);
    }
    vi xx = binRowPow(v,K);
    for(int i=0;i<N;i++)
        cout<<xx[i]<<" ";
}
