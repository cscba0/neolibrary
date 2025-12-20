#pragma once

#include <vector>

#include "factorial.hpp"

namespace cscba {

namespace math {

template <typename T>
struct Combination {
    Factorial<T> p;

    Combination() {}
    Combination(const Factorial<T>& _p) : p(_p) {}

    T operator()(std::size_t n, std::size_t r) {
        if (n < r) return T{0};
        return p[n] / p[r] / p[n - r];
    }
};

}  // namespace math
}  // namespace cscba
