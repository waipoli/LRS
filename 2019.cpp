
#include <cstddef>
#include<iostream>
#include <sched.h>
#include <sys/types.h>
#include<vector>

using namespace std;
#define int long long
#define mod 1000000007
#define mtr vector<vector<int>>

int binMult(int a, int b) {
    if (b == 0)
        return 0;
    if (b % 2 == 0) {
        int x = binMult(a, b / 2);
        x %= mod;
        return (x + x) % mod;
    }
    return (binMult(a, b - 1) % mod + a) % mod;
}

int binPow(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 0) {
        int x = binPow(a, b / 2);
        x %= mod;
        //        cout<<a<<" "<<b<<" "<<x<<endl;
        return binMult(x, x);
    }
    return binMult(binPow(a, b - 1) % mod, a);
}

mtr binMatrixMult(mtr a, mtr b) {

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            a[i][j] %= mod;
            b[i][j] %= mod;
        }
    }
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            b[i][j] %= mod;
        }
    }
    mtr C;
    int m = a.size();
    int n = a[0].size();
    int q = b[0].size();
    C.resize(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += (a[i][k] * b[k][j]) % mod;
                C[i][j] %= mod;
            }
            C[i][j] %= mod;
        }
    return C;
}

mtr binMatrixPow(mtr a, int n) {
    if (n == 1) {
        return a;
    }

    if (n % 2 == 0) {
        mtr x = binMatrixPow(a, n / 2);
        return binMatrixMult(x, x);
    }
    return binMatrixMult(binMatrixPow(a, n - 1), a);
}


signed main() {

    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    mtr fib(1, vector<int>(2));
    fib[0][0] = 0;
    fib[0][1] = 1;
    mtr p(2, vector<int>(2));
    p[0][0] = 0;
    p[0][1] = 1;
    p[1][0] = 1;
    p[1][1] = 1;
    p = binMatrixPow(p, n);
    cout << binMatrixMult(fib, p)[0][0] << endl;
}
