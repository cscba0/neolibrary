#pragma once
#include "../base.hpp"

inline FASTIO& operator>>(FASTIO& io, char& c) noexcept {
    io.seek();
    c = *io.ipos++;
    return io;
}
