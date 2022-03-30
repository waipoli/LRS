#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int A,B;
    cin>>A>>B;
    vector<bool> v(B+1,true);
    v[0] = false;
    v[1] = false;
    for(int i=2;i<=B;i++)
        if(v[i])
            for(int j=i+i;j<=B;j+=i)
            {
                v[j]=false;
            }
    int count=0;
    for(int i=A;i<=B;i++)
    {
        count+=v[i];
    }
    cout<<count<<endl;
}
