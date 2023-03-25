#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define int long long

signed main(){
    int a,b;
    cin>>a>>b;
    if(a < b)
    {
        cout<<0<<endl;
        return 0;
    }
    if(a == b)
    {
        cout<<"infinity"<<endl;
        return 0;
    }


    a-=b;
    int count=0;
    for(int i=1;i*i<=a;i++)
    {
        if(a % i != 0)
            continue;
        if(i > b)
            count++;
        if(a / i > b and a / i != i)
            count++;
    }

    cout<<count<<endl;
}
