#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
string to2(int n, int k)
{
    string ans="";
    while(n)
    {
        ans=char((n % 2)+ int('0')) + ans;
        n/=2;
    }
    while(ans.size() != k)
        ans='0'+ ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<(1<<n); i++)
    {
        cout<<to2(i,n)<<endl;
    }
}
