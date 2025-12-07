#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <sys/types.h>

#include <data-structure/segmnet-tree/segment-tree.hpp>
#include <fastio/base.hpp>
#include <fastio/char/write.hpp>
#include <fastio/pair/read.hpp>
#include <fastio/signed/read.hpp>
#include <fastio/unsigned/read.hpp>
#include <fastio/unsigned/write.hpp>
#include <fastio/vector/read.hpp>
#include <iterator>
#include <templates/macro/endl.hpp>
#include <templates/macro/mod.hpp>
#include <templates/macro/unsigned_long_long.hpp>
#include <templates/rep.hpp>
#include <utility>
#include <vector>

#include "templates/template.hpp"  // IWYU pragma: keep

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<ull, ull>> a(n);
    cin >> a;
    auto e = [] -> pair<ull, ull> { return {1, 0}; };
    struct M {
        using T = pair<ull, ull>;
        static T op(pair<ull, ull> a, pair<ull, ull> b) {
            return {a.first * b.first % MOD1, (a.second * b.first + b.second) % MOD1};
        };
        static T e() {
            return {1, 0};
        }
    };
    SegmentTree<M> seg(a);
    rep(_, q) {
        uint T;
        ull l, r, x;
        cin >> T >> l >> r >> x;
        if (T == 0) {
            seg.set(l, {r, x});
        } else {
            auto res = seg(l, r);
            auto ans = (res.first * x + res.second) % MOD1;
            cout << ans << endl;
        }
    }
}
