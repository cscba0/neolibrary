#pragma once

#include <vector>

namespace cscba {

namespace math {

template <typename T>
struct Permutation {
    std::vector<T> p;

    Permutation() : p({T{1}, T{1}}) {}

    T operator[](std::size_t n) {
        while (p.size() <= n) {
            p.emplace_back(p.back() * T{p.size()});
        }
        return p[n];
    }
};

}  // namespace math
}  // namespace cscba
