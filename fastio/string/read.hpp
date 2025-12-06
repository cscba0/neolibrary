#pragma once
#include <string>

#include "../char/read.hpp"

inline FASTIO& operator>>(FASTIO& io, std::string& s) noexcept {
    io.seek();
    s = "";
    while (' ' < *io.ipos) {
        s += *io.ipos++;
    }
    return io;
}
