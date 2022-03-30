#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<vector<int>> vv;

void rec(int lt, int sum, vector<int> prev) {
    if (sum < 0)
        return;
    if (sum == 0) {
        vv.push_back(prev);
        return;
    }
    vector<int> ct = prev;
    for (int i = lt; i >= 1; i--) {
        ct.push_back(i);
        rec(i, sum - i, ct);
        ct = prev;
    }

}

int main() {
    cin >> n;
    vector<int> g;
    rec(n, n, g);
    sort(vv.begin(), vv.end());
    for (auto gg: vv) {
        for (int i: gg)
            cout << i << " ";
        cout << endl;
    }
}
