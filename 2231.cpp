#include <cstddef>
#include<iostream>
#include <sched.h>
#include <sys/types.h>
#include<vector>

using namespace std;
#define int long long
#define mod 1000000007
#define mtr vector<vector<int>>
vector<int> fib(50);


char rec(int n,int k)
{
    if(n == 1)
    {
        return 'a';
    }
    if(n == 2)
    {
        return 'b';
    }

    if(k > fib[n-2])
    {
        return rec(n-1,k-fib[n-2]);
    }
    else
        return rec(n-2,k);
}
signed main() {
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<fib.size();i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        n++;
        cout<<rec(n,k)<<endl;
    }
}
