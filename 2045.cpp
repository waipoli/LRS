#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
void print(vector<int> v)
{
    for(auto a : v)
        cout<<a<<" ";
    cout<<"\n";
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        v[i]=i+1;
    print(v);
    while(next_permutation(v.begin(),v.end())){
        print(v);
    }
}
