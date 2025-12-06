#pragma once

namespace cscba {

namespace templates {

template <typename T>
T local(const T x, const T y) {
#ifdef LOCAL
    return x;
#else
    return y;
#endif
}

}  // namespace templates

}  // namespace cscba
