#pragma once
#include "../base.hpp"

inline cscba::FastIO::FastIO& operator<<(cscba::FastIO::FastIO& io, char c) noexcept {
    io.reserve(1);
    *io.opos++ = c;
    return io;
}
