#pragma once
#include <vector>

#include "../base.hpp"

template <typename T>
inline cscba::FastIO::FastIO& operator<<(cscba::FastIO::FastIO& os, const std::vector<T>& v) {
    for (uint i = 0, siz = v.size(); i < siz; ++i) {
        os << v[i] << (i + 1 == siz ? "" : " ");
    }
    return os;
}
