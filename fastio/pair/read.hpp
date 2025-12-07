#pragma once
#include "../base.hpp"

namespace cscba {

namespace FastIO {

template <typename T1, typename T2>
inline FastIO& operator>>(FastIO& io, std::pair<T1, T2>& P) noexcept {
    io >> P.first >> P.second;
    return io;
}
}  // namespace FastIO
}  // namespace cscba
