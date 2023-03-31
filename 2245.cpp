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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string S1;
    string S2;
    cin >> S1 >> S2;
    string ST1, ST2;
    for (char i: S1) {
        if (!ST1.empty() and ST1.back() == '*' and i == '*')
            continue;
        ST1 += i;
    }

    for (char i: S2) {
        if (!ST2.empty() and ST2.back() == '*' and i == '*')
            continue;
        ST2 += i;
    }
    S1 = ST1;
    S2 = ST2;
    vector<vector<bool>> dp(S1.size() + 1, vector<bool>(S2.size() + 1, false));
    vector<vector<pair<int, int>>> prev(S1.size() + 1, vector<pair<int, int>>(S2.size() + 1, {-1, -1}));
    dp[0][0] = true;
    for (int i = 1; i <= S1.size(); ++i) {
        for (int j = 1; j <= S2.size(); ++j) {
            if (S1[i - 1] == '*') {
                bool res = false;
                int k = 0;
                for (k = 0; k <= j; ++k) {
                    res |= dp[i - 1][k];
                    if (res)
                        break;
                }
                dp[i][j] = res;
                prev[i][j] = {i - 1, k};
            } elif (S2[j - 1] == '*') {
                bool res = false;
                int k = 0;
                for (k = 0; k <= i; ++k) {
                    res |= dp[k][j - 1];
                    if (res)
                        break;
                }
                dp[i][j] = res;
                prev[i][j] = {k, j - 1};
            } elif (S1[i - 1] == '?' || S2[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
                prev[i][j] = {i - 1, j - 1};
            } else {
                dp[i][j] = dp[i - 1][j - 1] && S1[i - 1] == S2[j - 1];
                prev[i][j] = {i - 1, j - 1};
            }
        }
    }
    if (!dp[S1.size()][S2.size()]) {
        cout << "-1";
        return 0;
    }
    string ans;
    int i = S1.size();
    int j = S2.size();
    while (i > 0 || j > 0) {
        if (S1[i - 1] == '*') {
            int k = prev[i][j].second;
            for (int l = k; l < j; ++l) {
                ans += S2[l];
            }
            i--;
            j = k;
        } elif (S2[j - 1] == '*') {
            int k = prev[i][j].first;
            for (int l = k; l < i; ++l) {
                ans += S1[l];
            }
            i = k;
            j--;
        } elif (S1[i - 1] == '?' || S2[j - 1] == '?') {
            ans += S1[i - 1] == '?' ? S2[j - 1] : S1[i - 1];
            i--;
            j--;
        } else {
            ans += S1[i - 1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (char &an: ans) {
        if (an == '?')
            an = 'A';
        if (an == '*')
            an = 'B';
    }
    cout << ans << endl;
}