
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> fact(int d) {
    vector<int> v;
    int k = 2;
    while (d != 1) {
        while (d % k == 0) {
            d /= k;
            v.push_back(k);
        }
        k++;
        if (k * k > d)
            break;
    }
    if (d != 1)
        v.push_back(d);
    return v;
}


int main() {
    int n;
    cin >> n;
    vector<int> vd = fact(n);
    cout << vd[0];
    for (int i = 1; i < vd.size(); i++)
        cout << "*" << vd[i];
}
