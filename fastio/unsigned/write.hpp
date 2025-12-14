#pragma once
#include <array>
#include <cstdint>
#include <cstring>

#include "../base.hpp"

namespace cscba {

namespace FastIO {

template <int... Ns>
constexpr auto make_table(std::integer_sequence<int, Ns...>) {
    return std::array<std::array<char, 4>, sizeof...(Ns)>{
        std::array<char, 4>{
            char('0' + Ns / 1000),
            char('0' + (Ns / 100) % 10),
            char('0' + (Ns / 10) % 10),
            char('0' + (Ns % 10))}...};
}

constexpr static auto table =
    make_table(std::make_integer_sequence<int, 10000>{});

inline void write_(FastIO& io, uint16_t x) noexcept {
    memcpy(io.opos, &table[x], 4);
    io.opos += 4;
}

inline void write__(FastIO& io, uint16_t x) noexcept {
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
inline void write(FastIO& io, T x) noexcept {
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

template <std::unsigned_integral T>
inline FastIO& operator<<(FastIO& io, T x) noexcept {
    io.reserve(20);
    write(io, x);
    return io;
}

}  // namespace FastIO

}  // namespace cscba
