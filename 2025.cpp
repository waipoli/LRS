#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define int long long
int K=0;
#define mod K


int binMult(int a,int b)
{
    if(b == 0)
        return 0;
    if(b % 2 == 0)
    {
        int x=binMult(a,b/2);
        x%=mod;
        return (x+x) % mod;
    }
    return (binMult(a,b-1) % mod + a)% mod;
}

int binPow(int a,int b)
{
    if(b == 0)
        return 1;
    if(b % 2 == 0)
    {
        int x=binPow(a,b/2);
        x%=mod;
        return binMult(x,x);
    }
    return binMult(binPow(a,b-1) % mod,a);
}
int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int reverseElement(int a,int m)
{
    int x, y;
    int g = gcd (a, m, x, y);
    if (g != 1)
	    return -1;
    else {
	    x = (x % m + m) % m;
	    return x;
    }
}

signed main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> p(n);
    vector<int> x(n);
    K=1;
    for(int i=0;i<n;i++)
    {
        int a_,b;
        cin>>a_>>b;
        a[i]=b;
        p[i]=a_;
        K*=a_;
    }
//    cout<<K<<endl;
    vector<vector<int>> r(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            r[i][j]=reverseElement(p[i],p[j]);
        }
    for (int i=0; i<n; ++i) {
    	x[i] = a[i];
    	for (int j=0; j<i; ++j) {
    		x[i] = r[j][i] * (x[i] - x[j]);
		    x[i] = x[i] % p[i];
	    	if (x[i] < 0)  x[i] += p[i];
	    }
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int mult=1;
        for(int j=0;j<i;j++)
        {
    //        cout<<j+1<<" ";
            mult = binMult(mult,p[j]);
        }
  //      cout<<endl;
        ans+= binMult(mult,x[i]);
        ans%=mod;

    }
    cout<<ans<<endl;
}
