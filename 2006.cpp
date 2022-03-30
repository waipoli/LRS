#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>

using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    cout << abs(__gcd(a, b)) << endl;
}
