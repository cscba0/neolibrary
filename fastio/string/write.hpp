#pragma once
#include <cstring>
#include <string>

#include "../char/write.hpp"

namespace cscba {

namespace FastIO {

inline FastIO& operator<<(FastIO& io, const std::string& s) noexcept {
    io.reserve(s.size());
    memcpy(io.opos, s.data(), s.size());
    io.opos += s.size();
    return io;
}
}  // namespace FastIO
}  // namespace cscba
