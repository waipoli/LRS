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
struct sol {
    int a, b, c;
    int id = 0;
};
vector<sol> v;
int n;

bool cmp1(sol A, sol B) {
    return A.b > B.b;
}

bool cmp2(sol A, sol B) {
    return A.c > B.c;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    v.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c;
        v[i].b -= v[i].a;
        v[i].c -= v[i].a;
        v[i].id = i;
        sum += v[i].a;
    }
    vector<sol> A = v;
    vector<sol> B = v;
    sort(A.begin(), A.end(), cmp1);
    sort(B.begin(), B.end(), cmp2);
    if (A[0].id != B[0].id) {
        sum += A[0].b;
        sum += B[0].c;
        cout << sum << endl;
        cout << A[0].id + 1 << " " << B[0].id + 1 << endl;
    } else {
        int kx = A[0].b + B[1].c;
        int ky = A[1].b + B[0].c;
        if (kx > ky) {
            sum += A[0].b;
            sum += B[1].c;
            cout << sum << endl;
            cout << A[0].id + 1 << " " << B[1].id + 1 << endl;
        } else {
            sum += A[1].b;
            sum += B[0].c;
            cout << sum << endl;
            cout << A[1].id + 1 << " " << B[0].id + 1 << endl;
        }
    }
    return 0;
}
