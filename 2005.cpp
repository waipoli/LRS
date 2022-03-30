
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int fact(int d) {
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
    return v.size();
}

bool check(int d) {
    if (fact(d) == 2)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    int d = 0;
    while (n) {
        d++;
        n -= check(d);
    }
    cout<<d<<endl;
}
