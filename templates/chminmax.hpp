#pragma once

namespace cscba {

namespace templates {

template <typename T>
inline bool chmin(T& x, const T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template <typename T>
inline bool chmax(T& x, const T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

}  // namespace templates

}  // namespace cscba
