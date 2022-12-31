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

const int SUM_OF_CHARACTERS = 45;

//calculate sum of character from 1 to 99..999
int sum_9(int count9) {
    int t = count9;
    for (int i = 1; i < count9; i++)
        t *= 10;
    return t * SUM_OF_CHARACTERS;
}

//calculate sum of character from 1 to x99..999
int sum(int x, int count_9) {
    int st = sum_9(count_9) * (x + 1);
    int p10 = 1;
    for (int i = 0; i < count_9; i++)
        p10 *= 10;
    for (int i = 0; i <= x; i++) {
        st += i * p10;
    }
    return st;
}


int f(int x) {
    if (x < 10) {
        int ans = 0;
        for (int i = 0; i <= x; i++) {
            ans += i;
        }
        return ans;
    }
    string s = to_string(x);
    int g = s[0] - '0';
    int ff = sum(g - 1, s.size() - 1);
    reverse(s.begin(), s.end());
    s.pop_back();
    reverse(s.begin(), s.end());
    int r = atoll(s.c_str());
    return ff + g * (r + 1) + f(r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << f(b) - f(a-1) << endl;
}