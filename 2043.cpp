#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;
#define int long long

string tok(int n, int k, int s) {
    string ans = "";
    while (n) {
        ans = char((n % k) + (int) ('0')) + ans;
        n /= k;
    }
    while (ans.size() != s)
        ans = '0' + ans;
    return ans;
}
int k;

int g(int n) {
    return n ^ (n / 2);
}

signed main() {
    int n;
    cin >> n >> k;
    for (int i = 0; i < pow(k, n); i++) {
        cout << tok(g(i), k, n) << endl;
    }
}
