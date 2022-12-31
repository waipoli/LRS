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
#define pi pair<int,int>

int opt(int n) {
    double f = (sqrt(9.0 + 8.0 * n) - 3) / 4.0;
    return (int) f;
}

pi f(int n) {
    pi a = {1, 1};
    int t = opt(n);
    n -= 3 * t + 2 * t * t;
    a.first += t * 2;
    if (n != 0) {
        a.first++;
        n--;
    }
    int r = 1 + 2 * t;
    if (n - r >= 0) {
        a.first -= r;
        a.second += r;
        n -= r;
    } else {
        a.first -= n;
        a.second += n;
        n = 0;
    }
    if (n != 0) {
        n--;
        a.second++;
    }
    a.first += n;
    a.second -= n;
    return a;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    n--;
    auto a = f(n);
    cout << a.first << "/" << a.second << endl;
}