

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

class Number {
public:
    bool isZero;
    bool isPositive;
    int tX;

    Number(int x = 0) {
        if (x == 0) {
            isZero = true;
            isPositive = true;
            tX = 0;
        }
        if (x == 1) {
            isPositive = true;
            isZero = false;
            tX = 0;
        }
        if (x == -1) {
            isPositive = false;
            isZero = false;
            tX = 0;
        }
        if (x == 2) {
            isPositive = true;
            isZero = false;
            tX = 1;
        }
        if (x == -2) {
            isPositive = false;
            isZero = false;
            tX = 1;
        }
    }

    friend bool operator<(Number a, Number b) {
        if (a.isZero and b.isZero)
            return false;
        if (a.isZero)
            return b.isPositive;

        if (b.isZero)
            return !a.isPositive;

        if (a.isPositive and !b.isPositive)
            return false;

        if (!a.isPositive and b.isPositive)
            return true;

        if (!a.isPositive and !b.isPositive)
            return a.tX > b.tX;

        if (a.isPositive and b.isPositive)
            return a.tX < b.tX;
    }

    friend bool operator>(Number a, Number b) {
        return !(a < b);
    }

    friend bool operator==(Number a, Number b) {
        if (a.isZero and b.isZero)
            return true;
        if (a.isZero)
            return false;
        if (b.isZero)
            return false;
        return (a.isPositive == b.isPositive and a.tX == b.tX);
    }

    Number operator*(Number x) {
        if (isZero)
            return *this;
        if (x.isZero) {
            isPositive = true;
            isZero = true;
            tX = 0;
            return *this;
        }
        isPositive = isPositive == x.isPositive;
        tX += x.tX;
        return *this;
    }


    Number operator/(Number x) {
        if (isZero)
            return *this;
        if (x.isZero) {
            return *this;
        }
        isPositive = isPositive == x.isPositive;
        tX -= x.tX;
        return *this;
    }


};


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int p1 = 0;
    int p2 = 0;
    Number max_(v[0]);
    Number q(v[0]);
    n++;
    v.push_back(0);
    while (p1 != n) {
        if (p2 == p1 and v[p2] == 0) {
            p2++;
            p1++;
            q = Number(v[p2]);
            if (max_ < q) {
                max_ = q;
            }
            continue;
        }
        if (v[p2] != 0)
            p2++;
        if (v[p2] == 0) {
            q = q / v[p1];
            p1++;
        } else
            q = q * v[p2];

        if (p1 == p2)
            q = Number(v[p1]);

        if (max_ < q) {
            max_ = q;
        }
    }
    if (max_ == 0) {
        for (int i = 0; i < n - 1; i++) {
            if (v[i] == 0) {
                cout << i + 1 << " " << i + 1 << endl;
                return 0;
            }
        }
    }
    p1 = 0;
    p2 = 0;
    q = v[0];
    while (p1 != n) {
        if (p2 == p1 and v[p2] == 0) {
            p2++;
            p1++;
            q = v[p2];
            if (q == max_) {
                if (v[p2] == 0)
                    p2--;
                if (v[p1] == 0)
                    p1--;
                cout << p1 + 1 << " " << p2 + 1 << endl;
                return 0;
            }
            continue;
        }
        if (v[p2] != 0)
            p2++;
        if (v[p2] == 0) {
            q = q / v[p1];
            p1++;
        } else
            q = q * v[p2];

        if (p1 == p2)
            q = Number(v[p1]);
        if (q == max_) {
            if (v[p2] == 0)
                p2--;
            if (v[p1] == 0)
                p1--;
            cout << p1 + 1 << " " << p2 + 1 << endl;
            return 0;
        }
    }
    cout << 1 << " " << 1 << endl;
}

