#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
#include <deque>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;
#define int long long
#define endl "\n"
#define epd 0.0000001
#define inf 100000000000000000

template<typename T>
void print(vector<T> &v, char del) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << del;
    }
}

template<typename T>
void read(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
}

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}


int binMult(int a, int b, int mod) {
    if (b == 0)
        return 0;
    if (b % 2 == 0) {
        int x = binMult(a, b / 2, mod);
        x %= mod;
        return (x + x) % mod;
    }
    return (binMult(a, b - 1, mod) % mod + a) % mod;
}

int binPow(int a, int b, int mod) {
    if (b == 0)
        return 1;
    if (b % 2 == 0) {
        int x = binPow(a, b / 2, mod);
        x %= mod;
        return binMult(x, x, mod);
    }
    return binMult(binPow(a, b - 1, mod) % mod, a, mod);
}

int binMult(int a, int b) {
    if (b == 0)
        return 0;
    if (b % 2 == 0) {
        int x = binMult(a, b / 2);
        return (x + x);
    }
    return (binMult(a, b - 1) + a);
}

int binPow(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 0) {
        int x = binPow(a, b / 2);
        return binMult(x, x);
    }
    return binMult(binPow(a, b - 1), a);
}

vector<int> dijkstra(int s, vector<vector<pair<int, int>>> &G) {
    vector<int> d(G.size());
    vector<bool> used(G.size(), false);
    vector<int> prev(G.size(), -1);
    d[s] = 0;
    for (int i = 0; i < G.size(); i++) {
        int min = inf;
        int id = 0;
        for (int j = 0; j < G.size(); j++) {
            if (min > d[j] and !used[j]) {
                min = d[j];
                id = j;
            }
        }
        used[id] = true;
        for (auto x: G[id]) {
            if (d[x.first] > d[id] + x.second) {
                d[x.first] = d[id] + x.second;
                prev[x.first] = id;
            }
        }
    }
//    int f = 3;
//    vector<int> path;
//    while (f != -1) {
//        path.push_back(f);
//        f = prev[f];
//    }
//    reverse(path.begin(), path.end());
    return d;
}

vector<vector<int>> floyd(vector<vector<int>> G) {
    vector<vector<int>> d = std::move(G);
    for (int k = 0; k < d.size(); k++)
        for (int i = 0; i < d.size(); i++)
            for (int j = 0; j < d.size(); j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    return d;
}

vector<vector<int>> toAdjacencyMatrix(vector<vector<pair<int, int>>> &G, int block = inf) {
    vector<vector<int>> adj(G.size(), vector<int>(G.size(), block));
    for (int i = 0; i < G.size(); i++) {
        for (auto x: G[i])
            adj[i][x.first] = x.second;
    }
    return adj;
}

vector<vector<pair<int, int>>> toAdjacencyList(vector<vector<int>> &G, int block = inf) {
    vector<vector<pair<int, int>>> adj(G.size());
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < G.size(); j++) {
            if (i == j)
                continue;
            if (G[i][j] != block) {
                adj[i].push_back({j, G[i][j]});
            }
        }
    }
    return adj;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    read(v);
    map<int, int> m;
    set<int> s;
    s.insert(0);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    for (int i = 0; i < n; i++) {
        int g = v[i];
        int a = 1;
        while (g) {
            int l = g % 10;
            g /= 10;
            if (g == 0) {
                if (s.find(l) != s.end())
                   s.erase(s.find(l));
            }
            m[l] += a;
            a *= 10;
        }
    }
    vector<pair<int, int>> d;
    for (auto x: m) {
        d.push_back({x.second, x.first});
//        cout << x.first << "-->" << x.second << endl;
    }
    sort(d.rbegin(), d.rend());
    int f = 9;
    int ans = 0;
    if (d.size() == 10) {
        int id = d.size() - 1;
        while (s.find(d[id].second) == s.end())
            id--;
        d.push_back(d[id]);
        d.erase(d.begin() + id);

    }
    for (int i = 0; i < d.size(); i++) {
        ans += d[i].first * f;
        f--;
    }
    cout << ans << endl;
 
