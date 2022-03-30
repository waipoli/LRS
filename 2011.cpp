#include<iostream>
#include<vector>
#include<cmath>
#include<map>
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
    map<int,int> m;
    for(auto a : vd)
        m[a]++;
    int delta=1;
    for(auto a : m)
    {
        delta*=a.second+1;
    }
    cout<<delta<<endl;
}
