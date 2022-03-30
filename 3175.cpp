#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

#define int long long

#define mod 1000000000007

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


int C(int a,int b)
{
    vector<int> primes;
    int A=1;
    int B=a+5;
    vector<bool> v(B+1,true);
    v[0] = false;
    v[1] = false;
    for(int i=2;i<=B;i++)
        if(v[i])
            for(int j=i+i;j<=B;j+=i)
            {
                v[j]=false;
            }
    for(int i=1;i<B;i++)
    {
        if(v[i]){
            primes.push_back(i);
//            cout<<i<<endl;
        }
    }
    vector<pair<int,int>> n;
    vector<pair<int,int>> k;
    vector<pair<int,int>> kn;
    for(auto prime : primes)
    {
        int q=prime;
        n.push_back({prime,0});
        while(a / q >=1)
        {
            n[n.size()-1].second += a / q;
            q*=prime;
        }
        q=prime;
        k.push_back({prime,0});
        while(b / q >= 1)
        {
            k[k.size()-1].second += b / q; 
            q*=prime;
        }
        q=prime;
        kn.push_back({prime,0});
        while((a-b) / q >= 1)
        {
            kn[kn.size()-1].second += (a - b) / q;
            q*=prime;
        }

    }
    for(int i=0;i<n.size();i++)
    {
        n[i].second -= k[i].second + kn[i].second;
    }

    int ans=1;
    for(auto a : n)
    {
        ans=binMult(ans,binPow(a.first,a.second));
    }
    return ans;
}

signed main()
{
    int N,M;
    cin>>N>>M;
    if(N<M || (N - M) % 2 != 0)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<(double)C(N,(N-M)/2) / (double)pow(2,N)<<endl;
}
