
#include<iostream>
#include<vector>
#include<map>

using namespace std;
#define int long long
int A, B, C, M;

vector<int> gg(vector<int> aa) {
    int a, b, c;
    a = aa[0];
    b = aa[1];
    c = aa[2];
    int x1 = (a * A + b * B + c * C) % M;
    int x2 = b * A + c * B + x1 * C;
    int x3 = c * A + x1 * B + x2 * C;
    x2%=M;
    x3%=M;
    return {x1, x2, x3};
}

signed main() {
    cin >> M >> A >> B >> C;
    vector<int> F(4);
    F[1] = 1;
    F[2] = 1;
    F[3] = 1;
    int n = 4;
    map<vector<int>, bool> mm;
    mm[gg({F[n - 3], F[n - 2], F[n - 1]})] = true;
//    cout << 1 << endl;
//    cout << 1 << endl;
//    cout << 1 << endl;
    while (true) {

        F.push_back((A * F[n - 3] + B * F[n - 2] + C * F[n - 1]) % M);
        n++;
//        cout << F.b/ack() << endl;
        if (mm[gg({F[n - 3], F[n - 2], F[n - 1]})]) {
            cout << n-4 << endl;
            return 0;
        } else
            mm[gg({F[n - 3], F[n - 2], F[n - 1]})] = true;
    }
}
