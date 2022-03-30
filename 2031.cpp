#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a=0;
    int b=0;
    cin>>a>>b;
    int count=0;
    int na=0;
    int nb=0;
    for(int i=1;i*i<a;i++)
    {
        na+=(a) / i-2;
    }
    for(int i=1;i*i<=b;i++)
    {
        nb+=(b) / i -2;
    }

    cout<<nb-na<<endl;
}
