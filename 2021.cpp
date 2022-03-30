#include<iostream>
using namespace std;
#define int long long

int GCD(int a,int b,int c,int d,bool &flag)
{
    if(flag)
        return 0;
    if(a == c && b == d)
    {
        flag=true;
        return 0;
    }
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a < b)
        swap(a,b);
    if(b == d && a % b == c % b && a> c)
    {
        flag=true;
        return 0;
    }
    a = a % b;
    if(a == c && b == d)
    {
        flag = true;
        return 0;
    }
    return GCD(a,b,c,d,flag);
}


void solve()
{
    int a,b;
    int c,d;
    bool flag=false;
    cin>>a>>b>>c>>d;
    GCD(a,b,c,d,flag);
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
}

signed main()
{
    int q;
    cin>>q;
    while(q--)
        solve();
}
