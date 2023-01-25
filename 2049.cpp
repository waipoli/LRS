#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define int long long

string to2(int n) {
    string ans = "";
    while (n) {
        ans = char((n % 2) + (int) ('0')) + ans;
        n /= 2;
    }
    return ans;
}


int from2(string s) {
    int ans = 0;
    int m = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        ans += m * (s[i] - '0');
        m *= 2;
    }
    return ans;
}

string nextVector(string a) {
    int n = a.size();
    while ((n >= 0) and (a[n] != '0')) {
        a[n] = '0';
        n--;
    }
    if (n == -1)
        return {'-'};
    a[n] = '1';
    return a;
}

string prevVector(string a) {
    int n = a.size();
    while ((n >= 0) and (a[n] != '1')) {
        a[n] = '1';
        n--;
    }
    if (n == -1)
        return {'-'};
    a[n] = '0';
    return a;
}

signed main() {
    string s;
    cin >> s;
    cout << prevVector(s) << "\n" << nextVector(s) << endl;
}
