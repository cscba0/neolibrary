#pragma once
#include "../unsigned/write.hpp"

namespace cscba {

namespace FastIO {

template <std::signed_integral T>
inline FastIO& operator<<(FastIO& io, T x) noexcept {
    io.reserve(20);
    if (x < 0) {
        *io.opos++ = '-';
        write(io, std::make_unsigned_t<T>(-x));
    } else {
        write(io, std::make_unsigned_t<T>(x));
    }
    return io;
}
}  // namespace FastIO
}  // namespace cscba
