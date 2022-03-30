#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int l,r;
    cin>>l>>r;
    if(l > r)
        cout<<1<<endl;
    else
        cout<<r - l +2<<endl;
    string suf="";
    vector<string> v;
    for(int i=r-1;i >= l;i--)
    {
        suf+=s[i];
        v.push_back(suf);
    }
    reverse(v.begin(),v.end());
    for(auto x : v){
        reverse(x.begin(),x.end());
        cout<<x<<endl;
    }

}
