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
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b - 2; i++) {
        if (isPrime(i) and isPrime(i + 2))
            cout << i << " " << i + 2 << endl;
    }
}
