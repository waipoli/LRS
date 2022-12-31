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
#define mod 1000000007
const int BYTE_COUNT = 62;

string to2(int n) {
    string ans;
    while (n) {
        ans += char(n % 2 + '0');
        n /= 2;
    }
    while (ans.size() < BYTE_COUNT) {
        ans += '0';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int count0(const string &s) {
    int ans = 0;
    for (auto x: s)
        ans += x == '0';
    return ans;
}

int count1(const string &s) {
    int ans = 0;
    for (auto x: s)
        ans += x == '1';
    return ans;
}

string minNearCn(string s, int count_zero) {
    int cz = count0(s);
    if (cz < count_zero) {
//        110011 -> 110000
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                s[i] = '0';
                cz++;
            }
            if (cz == count_zero) {
                break;
            }
        }
        return s;
    }
    if (cz > count_zero) {
        bool isEnd = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isEnd) {
                if (s[i] == '1') {
                    s[i] = '0';
                    break;
                }
                continue;
            }

            if (s[i] == '0') {
                s[i] = '1';
                cz--;
            }
            if (cz == count_zero - 1) {
                isEnd = true;
            }
        }
        return s;
    }

    return s;

}

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

struct Factorization {
    int p;
    int q;
};//representing p^q
EratosthenesSieve s(100000);

int Cnk(int N, int K) {
    if (N < K)
        return 0;
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

int number(string s) {
    int a = count0(s);
    int b = count1(s);
    int size = s.size() - 1;
    int cz = a;
    int id = 0;
    for (auto x: s) {
        if (x == '0') {
            id += Cnk(size, cz);
            cz--;
        }
        size--;
    }
    return id;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    for (int i = 0; i <= BYTE_COUNT; i++) {
        string a = minNearCn(to2(A), i);
        string b = minNearCn(to2(B), i);
        cout << number(b) - number(a) << endl;
    }
}