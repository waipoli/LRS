#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long


signed main() {
    int n;
    cin >> n;

    int f1 = 1, f2 = 1;
    int cur = 0;
    while (n) {
        if (f1 * f1 == f2 * f2 * f2) {
            n--;
            cur = f1 * f1;
            f1++;
            f2++;
        } else if (f1 * f1 < f2 * f2 * f2) {
            n--;
            cur = f1 * f1;
            f1++;
        } else if (f1 * f1 > f2 * f2 * f2) {
            n--;
            cur = f2 * f2 * f2;
            f2++;
        }
    }
    cout << cur << endl;
}
