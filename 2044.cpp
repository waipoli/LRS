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
        if(ans.size() > 1 and ans[0] == ans[1] and ans[0] == '1')
        {
            return "-";
        }
        n/=2;
    }
    while((int)ans.size() != k)
        ans='0'+ ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<string> vf;
    for(int i=0; i<(1<<n); i++)
    {
        string ggg=to2(i,n);
        if(ggg != "-")
            vf.push_back(ggg);
        //cout<<to2(i,n)<<endl;
    }
    cout<<vf.size()<<endl;
    for(auto g : vf)
        cout<<g<<endl;
}
