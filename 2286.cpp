#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string P,T;
    cin>>P>>T;
    int id=0;
    cin>>id;
    id--;
    int count=0;
    for(int i=0;i<P.size();i++)
    {
        count++;
        if(P[i] != T[id+i])
        {
            cout<<"NO"<<endl<<count<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl<<count<<endl;
}
