#include<iostream>
#include<vector>
#include<string>
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
    string pref="";
    for(int i=l-1;i<r-1;i++){
        pref+=s[i];
        cout<<pref<<endl;
    }
}
