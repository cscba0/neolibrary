#pragma once
#include <array>
#include <cstdint>
#include <cstring>

#include "../base.hpp"

namespace cscba {

namespace FastIO {

static auto table = [] {
    std::array<std::array<char, 4>, 10000> res;
    for (int i = 0; i < 10000; ++i) {
        res[i][0] = '0' + i / 1000;
        res[i][1] = '0' + i / 100 % 10;
        res[i][2] = '0' + i / 10 % 10;
        res[i][3] = '0' + i % 10;
    }
    return res;
}();

inline void write_(cscba::FastIO::FastIO& io, uint16_t x) noexcept {
    memcpy(io.opos, &table[x], 4);
    io.opos += 4;
}

inline void write__(cscba::FastIO::FastIO& io, uint16_t x) noexcept {
    if (x > 999) {
        memcpy(io.opos, &table[x], 4);
        io.opos += 4;
    } else if (x > 99) {
        memcpy(io.opos, &table[x * 10], 3);
        io.opos += 3;
    } else if (x > 9) {
        memcpy(io.opos, &table[x * 100], 2);
        io.opos += 2;
    } else {
        memcpy(io.opos, &table[x * 1000], 1);
        io.opos += 1;
    }
}

template <std::unsigned_integral T>
inline void write(cscba::FastIO::FastIO& io, T x) noexcept {
    if (9999'9999'9999'9999 < x) {
        write__(io, x / 10000'0000'0000'0000);
        write_(io, x / 10000'0000'0000 % 10000);
        write_(io, x / 10000'0000 % 10000);
        write_(io, x / 10000 % 10000);
        write_(io, x % 10000);
    } else if (9999'9999'9999 < x) {
        write__(io, x / 10000'0000'0000);
        write_(io, x / 10000'0000 % 10000);
        write_(io, x / 10000 % 10000);
        write_(io, x % 10000);
    } else if (9999'9999 < x) {
        write__(io, x / 10000'0000);
        write_(io, x / 10000 % 10000);
        write_(io, x % 10000);
    } else if (9999 < x) {
        write__(io, x / 10000);
        write_(io, x % 10000);
    } else {
        write__(io, x);
    }
}

}  // namespace FastIO

}  // namespace cscba

template <std::unsigned_integral T>
inline cscba::FastIO::FastIO& operator<<(cscba::FastIO::FastIO& io, T x) noexcept {
    io.reserve(20);
    cscba::FastIO::write(io, x);
    return io;
}
