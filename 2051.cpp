#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> vn;
    vn = v;
    bool b1 = prev_permutation(vn.begin(), vn.end());

    if (!b1) {
        for (int i = 0; i < n; i++)
            vn[i] = 0;
    }
    vector<int> vp;
    vp = v;
    bool b2 = next_permutation(vp.begin(), vp.end());
    if (!b2) {
        for (int i = 0; i < n; i++)
            vp[i] = 0;
    }
    for (int i = 0; i < n; i++)
        cout << vn[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << vp[i] << " ";
    cout << endl;
}
