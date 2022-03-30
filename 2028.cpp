#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}
int min(int a,int b)
{
    if(a < b)
        return a;
    return b;
}
signed main()
{
    int a,b,k;
    cin>>a>>b>>k;
    int delt=0;
    for(int y=0;y*y*y<=b;y++)
    {
        if(y*y*y < a)
            continue;
//        cout<<y<<endl;
        int maxXk=y*y*y+k;
        int minXk=y*y*y-k;
        minXk = max(1,minXk);
        int xU = trunc(sqrt(maxXk));
        int xD = ceil(sqrt(minXk));
        //xD = max(1,xD);
//        cout<<"------"<<endl;
  //      cout<<xU<<" "<<xD<<" "<<maxXk<<" "<<minXk<<endl;
        xU=min(trunc(sqrt(b)),xU);
      //  while(xU*xU > b)
        //    xU--;
        xD=max(ceil(sqrt(a)),xD);
        if(xU >= xD)
            delt+=xU - xD +1;
    }
    cout<<delt<<endl;
}
