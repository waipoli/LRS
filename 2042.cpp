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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string current;
    for (int i = 0; i < n; i++)
        current.push_back('0');
    cout << current << endl;
    set<string> all;
    all.insert(current);
    while (true) {
        string pref(current.begin() + 1, current.end());
        pref += '1';
        if (all.find(pref) == all.end()) {
            cout << pref << endl;
            current = pref;
            all.insert(current);
            continue;
        }
        pref.pop_back();
        pref += '0';
        if (all.find(pref) == all.end()) {
            cout << pref << endl;
            current = pref;
            all.insert(current);
            continue;
        }
        break;
    }

}
