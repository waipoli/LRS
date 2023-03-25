#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <type_traits>
#include <numeric>
#include <bitset>
#include <functional>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")

using namespace std;

#define int long long
#define float long double
#define elif else if
#define endl "\n
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000000001
#define inf INT64_MAX
#define FIXED(a) cout << fixed << setprecision(a);

#define int long long
#define elif else if
#define endl "\n"
#define mod 1000000007
vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

bool check() {
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            int Sa = 0;
            for (int k = 0; k < 5; ++k) {
                Sa += pow(v[k], i);
            }

            int Sb = 0;
            for (int k = 5; k < 10; ++k) {
                Sb += pow(v[k], j);
            }
            cout << i << " " << j << endl;
            cout << Sa << " " << Sb << endl;

            if (Sa == Sb)
                return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k = 0;
    for (int i = 100; i <= 999; i++) {
        k += __gcd(i, 6LL) == 1;
    }
    cout<<k<<endl;
    //    if(check()){
//        for (size_t i = 0; i < v.size(); i++) {
//            cout << v[i] << " ";
//        }
//        return 0
//    }
//
//
//    while (next_permutation(v.begin(), v.end()))
//        if(check()){
//            for (size_t i = 0; i < v.size(); i++) {
//                cout << v[i] << " ";
//            }
//            return 0;
//        }
}