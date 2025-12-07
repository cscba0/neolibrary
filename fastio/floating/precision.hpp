#pragma once

#include "../base.hpp"

namespace cscba {

namespace FastIO {

static int FastIOPrecision = 10;

struct precision {
    int n;
    constexpr precision(int _n) : n(_n) {}
};

inline FastIO& operator<<(FastIO& io, const precision p) {
    FastIOPrecision = p.n;
    return io;
}

}  // namespace FastIO
}  // namespace cscba
