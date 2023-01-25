#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <type_traits>
#include <numeric>
#include <bitset>
#include <functional>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")

using namespace std;

#define int long long
#define float long double
#define elif else if
#define endl "\n"
#define mod 1000'000'000'000'000LL
#define pi acos(-1)
#define eps 0.000000001
#define inf INT64_MAX
#define FIXED(a) cout << fixed << setprecision(a);


class EratosthenesSieve {
public:
    vector<bool> sieve;
    vector<int> primes;

    EratosthenesSieve(int N = 1000000) {
        sieve.resize((int) N, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i < (int) N; i++) {
            if (sieve[i]) {
                primes.push_back((int) i);
                for (int j = i + i; j < (int) N; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }

    bool isPrime(int n) {
        if (n >= sieve.size()) {
            throw exception();
        }
        return sieve[n];
    }

};

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

struct Factorization {
    int p;
    int q;
};//representing p^q
EratosthenesSieve s(100000);

int Cnk(int N, int K) {
    int KH = N - K;
    vector<Factorization> NF;
    vector<Factorization> KF;
    vector<Factorization> KHF;
    for (auto prime: s.primes) {
        if (prime > N) {
            break;
        }
        NF.push_back({prime, 0});
        int t = N;
        int p = prime;

        while (t / p != 0) {
            NF.back().q += t / p;
            p *= prime;
        }

        p = prime;
        KF.push_back({prime, 0});
        t = K;
        while (t / p != 0) {
            KF.back().q += t / p;
            p *= prime;
        }
        p = prime;
        KHF.push_back({prime, 0});
        t = KH;
        while (t / p != 0) {
            KHF.back().q += t / p;
            p *= prime;
        }
    }
    for (int i = 0; i < NF.size(); i++) {
        NF[i].q -= KF[i].q + KHF[i].q;
    }
    int ans = 1;
    for (int i = 0; i < NF.size(); i++) {
        ans = binMult(ans, binPow(NF[i].p, NF[i].q, mod), mod);
    }
    return ans;
}

vector<int> ans;

void num2choose(int n, int k, int m) {
    int next = 1;
    while (k > 0) {
        if (m < Cnk(n - 1, k - 1)) {
            ans.push_back(next);
            k = k - 1;
        } else
            m -= Cnk(n - 1, k - 1);
        n = n - 1;
        next = next + 1;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    num2choose(n, k, m);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}