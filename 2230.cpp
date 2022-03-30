#include <cstddef>
#include<iostream>
#include <sched.h>
#include <sys/types.h>
#include<vector>

using namespace std;
#define int long long
#define mod 1000000007
#define mtr vector<vector<int>>
vector<int> fib(45);

signed main() {

    int n;
    cin >> n;
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<fib.size();i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    int sum=0;
    for(int i=0;i<=n;i++)
        sum+=fib[i];
    cout<<sum<<endl;
}
