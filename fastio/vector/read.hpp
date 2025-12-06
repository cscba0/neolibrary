#pragma once
#include <vector>

#include "../base.hpp"

template <typename T>
inline cscba::FastIO::FastIO& operator>>(cscba::FastIO::FastIO& io, std::vector<T>& v) noexcept {
    for (auto& x : v) {
        io >> x;
    }
    return io;
}
