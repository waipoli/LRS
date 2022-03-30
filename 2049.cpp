#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define int long long

string to2(int n)
{
    string ans="";
    while(n)
    {
        ans=char((n % 2)+ (int)('0')) + ans;
        n/=2;
    }
    return ans;
}


int from2(string s)
{
    int ans=0;
    int m=1;
    for(int i=s.size()-1; i>=0; i--)
    {
        ans+=m*(s[i]-'0');
        m*=2;
    }
    return ans;
}

signed main()
{
    string s;
    cin>>s;
    if(s == "0")
    {
        cout<<"-"<<endl<<1<<endl;
        return 0;
    }
    int x=from2(s);
    cout<<to2(x-1)<<endl<<to2(x+1)<<endl;
}
