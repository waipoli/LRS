#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long




signed main()
{
    int a1=0;
    int a2=0;
    int a3=0;
    int n;
    cin>>n;
    for(int i=0; i*i<n; i++){
        a1++;
    }

    for(int i=0; i*i*i<n; i++)
    {
        a2++;
    }

    for(int i=0; i*i*i*i*i*i<n; i++)
    {
        a3++;
    }
    cout<<a1+a2-a3<<endl;
}
