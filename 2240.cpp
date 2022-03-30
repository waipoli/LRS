#include<iostream>
#include<vector>
#include <cmath>

using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(10, vector<int>(n + 1, 0));
    dp[0][1]=1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[3][1] = 1;
    dp[4][1] = 1;
    dp[5][1] = 1;
    dp[6][1] = 1;
    dp[7][1] = 1;
    dp[8][1] = 1;
    dp[9][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[0][i] = dp[1][i - 1] + dp[0][i-1];
        dp[9][i] = dp[8][i - 1] + dp[9][i-1];
        for (int j   = 1; j <= 8; j++) {
            dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1] + dp[j][i-1];
        }
    }
    cout << dp[1][n] + dp[2][n] + dp [3][n] + dp[4][n] + dp[5][n] + dp[6][n] + dp[7][n] + dp[8][n] + dp[9][n]
         << endl;
//    int n;
//    cin >> n;

}
