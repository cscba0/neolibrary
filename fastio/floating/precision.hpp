#pragma once

#include "../base.hpp"

namespace cscba {

namespace FastIO {

static int FastIOPrecision = 10;

struct precision {
    int n;
    constexpr precision(int _n) : n(_n) {}
};

}  // namespace FastIO
}  // namespace cscba

inline cscba::FastIO::FastIO& operator<<(cscba::FastIO::FastIO& io, const cscba::FastIO::precision p) {
    cscba::FastIO::FastIOPrecision = p.n;
    return io;
}
