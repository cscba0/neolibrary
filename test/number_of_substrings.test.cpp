#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include <fastio/base.hpp>
#include <fastio/char/write.hpp>
#include <fastio/signed/write.hpp>
#include <fastio/string/read.hpp>
#include <string/lcp_array.hpp>
#include <string/suffix_array.hpp>
#include <string>
#include <templates/macro/endl.hpp>
#include <templates/macro/long_long.hpp>
#include <vector>

#include "templates/template.hpp"  // IWYU pragma: keep

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = n * (n + 1) / 2;
    auto lcp = lcp_array(s, suffix_array(s));
    for (int i : lcp) {
        ans -= i;
    }
    cout << ans << endl;
}
