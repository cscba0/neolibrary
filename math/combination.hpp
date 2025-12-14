#pragma once

#include <vector>

#include "permutation.hpp"

namespace cscba {

namespace math {

template <typename T>
struct Combination {
    Permutation<T> p;

    Combination() {}
    Combination(const Permutation<T>& _p) : p(_p) {}

    T operator()(std::size_t n, std::size_t r) {
        return p[n] / p[r] / p[n - r];
    }
};

}  // namespace math
}  // namespace cscba
