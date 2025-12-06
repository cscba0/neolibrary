#pragma once
#include <cstring>
#include <string>

#include "../char/write.hpp"

inline FASTIO& operator<<(FASTIO& io, const std::string& s) noexcept {
    io.reserve(s.size());
    memcpy(io.opos, s.data(), s.size());
    io.opos += s.size();
    return io;
}
