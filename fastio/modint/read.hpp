#pragma once

#include "../../math/modint.hpp"
#include "../signed/read.hpp"

template <uint32_t Mod>
inline cscba::FastIO::FastIO& operator>>(cscba::FastIO::FastIO& io, cscba::math::Modint<Mod>& x) {
    io >> x.x;
    x.x %= Mod;
    return io;
}
