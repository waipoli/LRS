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

typedef struct {
    int p;
    int q;
} Factor;

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


int factorizeOfFactorial(int n, int P) {
    int ans = 0;
    int p = P;
    while (n / p) {
        ans += n / p;
        p *= P;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, K, M;
    cin >> N >> K >> M;

    auto factorization = factorize(M);
    vector<int> ansForEachFact;
    for (auto fact: factorization) {
        int a = factorizeOfFactorial(N, fact.p) - factorizeOfFactorial(K, fact.p) - factorizeOfFactorial(N - K, fact.p);
        ansForEachFact.push_back(a / fact.q);
    }

    int min_ = INT32_MAX;

    for (int i = 0; i < ansForEachFact.size(); ++i) {
        min_ = min(min_, ansForEachFact[i]);
    }

    cout << min_ << endl;

}