#pragma once
#include "../base.hpp"

namespace cscba {

namespace FastIO {

inline FastIO& operator<<(FastIO& io, char c) noexcept {
    io.reserve(1);
    *io.opos++ = c;
    return io;
}
}  // namespace FastIO
}  // namespace cscba
