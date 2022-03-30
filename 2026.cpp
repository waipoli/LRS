
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>

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
    vector<char> prime(n * 2 + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n * 2; ++i)
        if (prime[i])
            if (i * 1ll * i <= 2*n)
                for (int j = i * i; j <= n * 2; j += i)
                    prime[j] = false;

    int count = 0;
    for (int i = n + 1; i < n * 2; i++) {

        count += prime[i];
    }
    cout << count << endl;
}
