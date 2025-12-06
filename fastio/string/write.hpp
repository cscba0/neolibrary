#pragma once
#include <cstring>
#include <string>

#include "../char/write.hpp"

inline cscba::FastIO::FastIO& operator<<(cscba::FastIO::FastIO& io, const std::string& s) noexcept {
    io.reserve(s.size());
    memcpy(io.opos, s.data(), s.size());
    io.opos += s.size();
    return io;
}
