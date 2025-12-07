#pragma once
#include "../base.hpp"

namespace cscba {

namespace FastIO {

inline FastIO& operator>>(FastIO& io, char& c) noexcept {
    io.seek();
    c = *io.ipos++;
    return io;
}

}  // namespace FastIO
}  // namespace cscba
