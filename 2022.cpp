#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
#define mod 1000000000000000000

int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}
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
//        cout<<a<<" "<<b<<" "<<x<<endl;
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

int main() {
    int a,m;
    cin>>a>>m;
    int x, y;
    int g = gcd (a, m, x, y);
    if (g != 1)
	    cout << "No solution";
    else {
	    x = (x % m + m) % m;
	    cout << x;
    }
}
