#include <fastio/base.hpp>
#include <fastio/char/write.hpp>
#include <fastio/signed/read.hpp>
#include <fastio/signed/write.hpp>
#include <templates/macro/endl.hpp>

#include "templates/template.hpp"  // IWYU pragma: keep

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}
