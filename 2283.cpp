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
        cout<<0<<endl;
    else
        cout<<r - l +1<<endl;
    for(int i=l-1;i<r;i++)
        cout<<s[i];
    cout<<endl;
}
