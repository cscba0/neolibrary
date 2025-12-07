#pragma once

#include "../../math/modint.hpp"
#include "../signed/write.hpp"

namespace cscba {

namespace FastIO {

template <uint32_t Mod>
inline FastIO& operator<<(FastIO& io, cscba::math::Modint<Mod> x) {
    io << x.x;
    return io;
}
}  // namespace FastIO
}  // namespace cscba
