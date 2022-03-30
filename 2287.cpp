#include <cstddef>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
string P,T;

void sr(int id)
{
    int count=0;
    for(int i=0;i<P.size();i++)
    {
        if(id + i >= T.size())
        {
            cout<<endl<<0<<endl;
            exit(0);
        }
        cout<<P[i]<<"";
        if(P[i] != T[id+i])
        {
            return;
        }
    }
    cout<<endl<<id+1<<endl;
    exit(0);
}

int main()
{
    cin>>P>>T;
    int id=0;
    for(int i=0;i<T.size();i++)
    {
        sr(i);
    }
    cout<<endl<<0<<endl;
}
