#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <type_traits>
#include <numeric>
#include <bitset>
#include <functional>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")

using namespace std;

#define int long long
#define float long double
#define elif else if
#define endl "\n"
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000000001
#define inf INT64_MAX
#define FIXED(a) cout << fixed << setprecision(a);

#define int long long
#define elif else if
#define endl "\n"
#define mod 1000000007


namespace Algorithms {

    template<typename T>
    class vertex {
    public:
        vertex<T> *left;
        vertex<T> *right;
        T val;

        explicit vertex(const T &_val = T()) : val(_val), left(NULL), right(NULL) {}

        vertex(vertex<T> *_left, vertex<T> *_right, std::function<T(T, T)> &merge) : left(_left), right(_right),
                                                                                     val(T()) {
            if (_left == NULL)
                val = right->val;
            else if (_right == NULL)val = left->val;
            else
                val = merge(right->val, left->val);
        }
    };

    template<typename T>
    class segment_tree {
    private:
        std::function<T(T, T)> merge;
        T defaultValue = T();
        std::vector<T> data;
        std::vector<vertex<T> *> versions;
        std::vector<vertex<T> *> vertexes;

        vertex<T> *_build(int tl, int tr) {
            if (tl == tr)
                return new vertex<T>(data[tl]);
            int tm = (tl + tr) / 2;
            auto vertex = new Algorithms::vertex<T>(_build(tl, tm), _build(tm + 1, tr), merge);
            vertexes.push_back(vertex);
            return vertex;
        }

        T _get(vertex<T> *v, int tl, int tr, int l, int r) {
            if (l > r)
                return defaultValue;
            if (l == tl && r == tr)
                return v->val;
            int tm = (tl + tr) / 2;
            return merge(_get(v->left, tl, tm, l, std::min(r, tm)), _get(v->right, tm + 1, tr, std::max(l, tm + 1), r));
        }

        vertex<T> *_update(vertex<T> *t, int tl, int tr, int pos, T newVal) {
            if (tl == tr) {
                auto vertex = new Algorithms::vertex<T>(newVal);
                vertexes.push_back(vertex);
                return vertex;
            }
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                auto vertex = new Algorithms::vertex<T>(_update(t->left, tl, tm, pos, newVal), t->right, merge);
                vertexes.push_back(vertex);
                return vertex;
            } else {
                auto vertex = new Algorithms::vertex<T>(t->left, _update(t->right, tm + 1, tr, pos, newVal), merge);
                vertexes.push_back(vertex);
                return vertex;
            }
        }

        template<class F>
        static F sum(F a, F b) {
            return a + b;
        }

    public:
        segment_tree() = default;

        explicit segment_tree(std::vector<T> _data, std::function<T(T, T)> merge = sum<T>) : data(_data), merge(merge) {
            versions.push_back(_build(0, data.size() - 1));
        }

        void update(size_t pos, T val) {
            if (pos >= data.size())
                throw std::out_of_range("Error: index is out of range");
            data[pos] = val;
            versions.push_back(_update(versions[versions.size() - 1], 0, data.size() - 1, pos, val));
        }

        T get(int x, int y, int version = -1) {
            if (x > y)
                std::swap(x, y);
            if (x >= data.size() || y >= data.size())
                throw std::out_of_range("Error: at least one of the bounds is out of range");
            if (version < -1 || version >= (int) versions.size())
                throw std::out_of_range("Error: bad version of tree");
            if (version == -1)
                version += versions.size();
            vertex<T> *t = versions[version];
            return _get(t, 0, data.size() - 1, x, y);
        }
    };
}

int merge_(int a, int b) {
    return a + b;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a;
    int b;
    cin >> a >> b;
    cout << a + b << endl;

}