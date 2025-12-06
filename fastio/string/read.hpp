#pragma once
#include <string>

#include "../char/read.hpp"

inline cscba::FastIO::FastIO& operator>>(cscba::FastIO::FastIO& io, std::string& s) noexcept {
    io.seek();
    s = "";
    while (' ' < *io.ipos) {
        s += *io.ipos++;
    }
    return io;
}
