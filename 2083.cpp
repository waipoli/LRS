#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
#define int long long

int KOunt = 0;

void merge(vector<int> &ans, vector<int> L, vector<int> R) {
    int l = 0, r = 0;
    while (l <= L.size() - 1 and r <= R.size() - 1) {
        if (L[l] > R[r]) {
            ans.push_back(R[r]);
            KOunt += L.size() - l;
            r++;
        } else {
            ans.push_back(L[l]);
            l++;
        }
    }
    while (l <= L.size() - 1) {
        ans.push_back(L[l]);
        l++;
    }
    while (r <= R.size() - 1) {
        ans.push_back(R[r]);
        r++;
    }
    ans = ans;
}

vector<int> v;

void mergeSort(vector<int> &_ans, int l, int r) {
    if (l == r) {
        _ans = vector<int>(1, v[l]);
        return;
    }
    vector<int> L;
    int m = (l + r) / 2;
    mergeSort(L, l, m);
    vector<int> R;
    mergeSort(R, m + 1, r);
    merge(_ans, L, R);
}


signed main() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
//    reverse(v.begin(), v.end());
    vector<int> ans = v;
    mergeSort(ans, 0, v.size() - 1);
    cout << KOunt << endl;
}
