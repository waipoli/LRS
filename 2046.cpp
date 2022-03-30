#include <iostream>
#include <vector>

using namespace std;
int n,k;

void rec(int lt,int id,string prev)
{
    if(id == k)
    {
        for(int i=lt+1;i<=n;i++)
        {
            cout<<prev<<" "<<i<<"\n";
        }
        return;
    }
    string ct=prev;
    for(int i=lt+1;i<=n-(k-id);i++)
    {
        ct+=" ";
        ct+= to_string(i);
        rec(i,id+1,ct);
        ct=prev;
    }
}
int main()
{
    cin>>n>>k;
    string g="";

    rec(0,1,g);
}
