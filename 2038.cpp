#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <string>

using namespace std;

#define int long long
#define elif else if
#define endl "\n"
#define mod 46021

int binMult(int a, int b, int m) {
    if (a == 0 or b == 0)
        return 0;
    if (a == 1)
        return b;
    if (b == 1)
        return a;
    if (a < b)
        swap(a, b);
    if (b % 2 == 0) {
        int f = binMult(a, b / 2, m);
        f %= m;
        f += f;
        f %= m;
        return f;
    } else {
        return (binMult(a, (b - 1), m) % m + a) % m;
    }
}

int binPow(int a, int b, int m) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0) {
        int f = binPow(a, b / 2, m);
        f %= m;
        f = binMult(f, f, m);
        f %= m;
        return f;
    } else {
        return binMult(binPow(a, (b - 1), m) % m, a, m) % m;
    }
}

int gcdex(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

pair<int, int> gcdex(int a, int b) {
    int x;
    int y;
    gcdex(a, b, x, y);
    return {x, y};
}


int sum(int q, int n) {
    int b = 1;
    int pb = binPow(q, n + 1, mod) - 1 + mod;
    pb %= mod;
    int gcd = gcdex(q - 1, mod).first;
    gcd += 10 * mod;
    gcd %= mod;
    gcd = binMult(gcd, pb, mod);
    return gcd;
}

struct Factor {
    int p;
    int q;
};

vector<Factor> factorize(int n) {
    int d = 2;
    vector<Factor> ans;
    while (true) {
        if (n % d == 0) {
            ans.push_back({d, 0});
            while (n % d == 0) {
                ans[ans.size() - 1].q++;
                n /= d;
            }
        }
        if (d * d > n)
            break;
        d++;
    }
    if (n != 1) {
        ans.push_back({n, 1});
    }
    return ans;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int A, B;
    cin >> A >> B;
    int ans = 1;
    auto g = factorize(A);
    for (auto fact: g) {
        fact.q *= B;
        ans = binMult(ans, sum(fact.p, fact.q), mod);
    }
    cout<<ans<<endl;
}