#pragma once
#include "../unsigned/write.hpp"

template <std::signed_integral T>
inline cscba::FastIO::FastIO& operator<<(cscba::FastIO::FastIO& io, T x) noexcept {
    io.reserve(20);
    if (x < 0) {
        *io.opos++ = '-';
        FastWrite(io, std::make_unsigned_t<T>(-x));
    } else {
        FastWrite(io, std::make_unsigned_t<T>(x));
    }
    return io;
}
