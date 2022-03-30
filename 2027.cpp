#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define int long long

signed main(){
    int N,M;
    cin>>N>>M;
    vector<bool> v(M+1,true);
    v[0] = false;
    v[1] = false;
    for(int i=2;i<=M;i++)
        if(v[i])
            for(int j=i+i;j<=M;j+=i)
            {
                v[j]=false;
            }
    for(int i=N;i<=M;i++)
    {
        if(!v[i])
            continue;
        int P = i;
        for(int alpha=sqrt(N / P);alpha <= sqrt(M / P);alpha++)
        {
            int y=alpha*alpha*P;
            int x = y + 2*alpha*P + P;
            if(N<=y && M>= y && N <= x && M >= x)
            {
                printf("%lln%lln%lln",&x,&y,&P);
            }
        }
    }
}
