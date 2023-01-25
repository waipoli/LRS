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

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")

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


#define int long long
#define elif else if
#define endl "\n"
#define mod 1000000007

vector<vector<int>> DP;

int N;

int part2num(vector<int> part) {
    int numOfPart = 0, last = 0, sum = 0;
    for (int i = 0; i < part.size(); i++) {
        for (int j = last; j <= part[i] - 1; j++)
            numOfPart += DP[N - sum - j][j];
        sum += part[i];
        last = part[i];
    }
    return numOfPart;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> part(1);
    cin >> part[0];
    int sum = part[0];
    int t;
    char c;
    while (cin >> c >> t) {
        if (c == 'X')
            break;
        part.push_back(t);
        sum += t;

    }
    N = sum;
    DP.resize(N+1, vector<int>(N+1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = N; j >= 1; --j) {
            if (i == j) {
                DP[i][j] = 1;
                continue;
            }
            if (i < j){
                DP[i][j] = 0;
                continue;
            }

            if (i > j and j != N - 1)
                DP[i][j] = DP[i][j + 1] + DP[i - j][j];
//            if (i > j and j == N - 1)
//                DP[i][j] = DP[i - j][j];
        }
    }
    cout << part2num(part) << endl;

}
