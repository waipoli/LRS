
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool isPrime(int n) {
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    int delta = n;
    while (!isPrime(delta)) {
        delta++;
    }
    int dg = n;
    int st = delta - n;
    while (!isPrime(n)) {
        n--;
    }
    int xt = dg - n;
    if (st >= xt) {
        cout << n << endl;
    } else
        cout << delta << endl;
}
