#pragma once

#include "../../math/modint.hpp"
#include "../signed/read.hpp"

namespace cscba {

namespace FastIO {

template <uint32_t Mod>
inline FastIO& operator>>(FastIO& io, cscba::math::Modint<Mod>& x) {
    io >> x.x;
    x.x %= Mod;
    return io;
}
}  // namespace FastIO
}  // namespace cscba
