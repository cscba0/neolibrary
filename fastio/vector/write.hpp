#pragma once
#include <vector>

#include "../base.hpp"

namespace cscba {

namespace FastIO {

template <typename T>
inline FastIO& operator<<(FastIO& os, const std::vector<T>& v) {
    for (uint i = 0, siz = v.size(); i < siz; ++i) {
        os << v[i] << (i + 1 == siz ? "" : " ");
    }
    return os;
}
}  // namespace FastIO
}  // namespace cscba
