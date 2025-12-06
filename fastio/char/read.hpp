#pragma once
#include "../base.hpp"

inline cscba::FastIO::FastIO& operator>>(cscba::FastIO::FastIO& io, char& c) noexcept {
    io.seek();
    c = *io.ipos++;
    return io;
}
