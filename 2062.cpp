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
#define endl "\n"
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000000001
#define inf INT64_MAX
#define FIXED(a) cout << fixed << setprecision(a);

set<char> glasnie = {'a', 'e', 'i', 'o', 'u', 'y'};

bool check(string s) {
    for (int i = 0; i < s.size() - 1; ++i) {
        if (glasnie.find(s[i]) != glasnie.end() and glasnie.find(s[i + 1]) != glasnie.end())
            return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    bool flag = false;
    if(check(s)){
        flag = true;
        cout<<s<<endl;
    }
    while (next_permutation(s.begin(), s.end())){
        if(check(s)){
            flag = true;
            cout<<s<<endl;
        }
    }
    if(!flag)
        cout<<-1<<endl;
}