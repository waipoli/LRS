#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
bool cmp(pair<int,int> A,pair<int,int> B)
{
    if(A.first < B.first)
        return true;
    else
        return false;
}

signed main()
{
    int N;
    cin>>N;
    vector<pair<int,int>> v;
    for(int z=1;z*z<=2*N;z++)
    {
        if((2*N-z*z - z) % (2*(z+1)) == 0)
        {
        
            int l=(2*N-z*z-z) / (2*(z+1));
            int r=l+z;
            if(l == 0)
                continue;
            v.push_back({l,r});
        }
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v.size()<<endl;
    for(auto a : v)
    {
        cout<<"["<<a.first<<", "<<a.second<<"]\n";
    }

}
