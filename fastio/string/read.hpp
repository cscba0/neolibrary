#pragma once
#include <string>

#include "../char/read.hpp"

namespace cscba {

namespace FastIO {

inline FastIO& operator>>(FastIO& io, std::string& s) noexcept {
    io.seek();
    s = "";
    while (' ' < *io.ipos) {
        s += *io.ipos++;
    }
    return io;
}
}  // namespace FastIO
}  // namespace cscba
