#pragma once
#include "../base.hpp"

template <typename T1, typename T2>
inline cscba::FastIO::FastIO& operator>>(cscba::FastIO::FastIO& io, std::pair<T1, T2>& P) noexcept {
    io >> P.first >> P.second;
    return io;
}
