#include<iostream>
#include<vector>

using namespace std;
#define int long long

int K;
#define mod K
#define vi vector<int>

vi binRowMult(const vi &a, const vi &b) {
    int n = a.size();
    vi ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(a[b[i] - 1]);
    }
    return ans;
}

vi binRowPow(const vi& a, int n) {
    if (n == 1)
        return a;
    if (n % 2 == 0) {
        vi x = binRowPow(a, n / 2);
        return binRowMult(x, x);
    }
    return binRowMult(binRowPow(a, n - 1), a);

}

signed main() {
    int N, K;
    cin >> N >> K;
    vi v(N, 0);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &v[i]);
    }
    vi xx = binRowPow(v, K);
    for (int i = 0; i < N; i++)
        cout << xx[i] << " ";
}
