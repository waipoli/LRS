#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define int long long

signed main()
{
    int S,a,b,c;
    cin>>a>>b>>c;
    cin>>S;
    S*=1000;
    int d=a*1000+b*10+c;
    cout<<(S+d-1) / d<<endl;
}
