#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <fastio/base.hpp>
#include <fastio/char/write.hpp>
#include <fastio/signed/write.hpp>
#include <fastio/string/read.hpp>
#include <fastio/string/write.hpp>
#include <fastio/vector/write.hpp>
#include <string/suffix_array.hpp>
#include <string>
#include <templates/macro/endl.hpp>
#include <vector>

#include "templates/template.hpp"  // IWYU pragma: keep

int main() {
    string s;
    cin >> s;
    vector ans = suffix_array(s);
    cout << ans << endl;
}
