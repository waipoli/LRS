#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <set>

using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int x = 1;
    int c = n;
    int i = 2;
    int delta = 0;
    int ld = 2;
    while (n != 1) {
        if (i * i > n + 2 * i)
            break;
        if (n % i == 0) {
            int k = 0;
            while (n % i == 0) {
                n /= i;
                k++;
            }
            if (k > delta) {
                delta = k;
                ld = i;
            }
            x *= i;
        }
        i++;
    }
    x *= n;
    for (int h = 1; h <= c; h++) {
        int kd = 0;
        int hd = h;
        while (hd % ld == 0) {
            hd /= ld;
            kd++;
        }
        if (h * x * (kd + 1) >= delta) {
            x *= h;
            break;
        }
    }
    cout << x << endl;
    return 0;
}
