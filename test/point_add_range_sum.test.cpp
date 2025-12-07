#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <data-structure/segmnet-tree/segment-tree.hpp>
#include <fastio/base.hpp>
#include <fastio/char/write.hpp>
#include <fastio/signed/read.hpp>
#include <fastio/signed/write.hpp>
#include <fastio/vector/read.hpp>
#include <templates/macro/endl.hpp>
#include <templates/macro/long_long.hpp>
#include <vector>

#include "templates/template.hpp"  // IWYU pragma: keep

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    cin >> a;
    struct M {
        using T = ll;
        static T op(T a, T b) {
            return a + b;
        }
        static T e() {
            return 0;
        }
    };
    SegmentTree<M> seg(a);
    while (q--) {
        int T;
        cin >> T;
        if (T == 0) {
            int p, x;
            cin >> p >> x;
            seg.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg(l, r) << endl;
        }
    }
}
