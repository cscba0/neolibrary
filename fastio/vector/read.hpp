#pragma once
#include <vector>

#include "../base.hpp"

namespace cscba {

namespace FastIO {

template <typename T>
inline FastIO& operator>>(FastIO& io, std::vector<T>& v) noexcept {
    for (auto& x : v) {
        io >> x;
    }
    return io;
}
}  // namespace FastIO
}  // namespace cscba
