#pragma GCC optimize("O3")
#pragma GCC target("avx2")

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


signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }

    int p1 = 0, p2 = 0;
    int a = v[p1], b = -1;
    int maxS = 0;
    int lastA = 0;
    int lastB = 0;
    while (p2 != n) {
        if (a != -1 and b != -1 and a != b) {
            maxS = max(maxS, p2 - p1 + 1);
        }
        p2++;
        if (v[p2] == a) {
            lastA = p2;
        } elif (v[p2] == b) {
            lastB = p2;
        } elif (b == -1) {
            b = v[p2];
            lastB = p2;
            continue;
        } else {
            if (v[p2 - 1] == a) {
                swap(lastB, lastA);
                swap(a, b);
            }

            p1 = lastA + 1;
            lastA = lastB;
            lastB = p2;
            a = b;
            b = v[p2];
            continue;
        }
    }
    cout << maxS << endl;
}
