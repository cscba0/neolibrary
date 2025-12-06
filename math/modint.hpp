#pragma once

#include <cstdint>

namespace cscba {

namespace math {

template <uint32_t Mod>
struct Modint {
    uint32_t x;

    Modint() : x(0) {}

    template <class T>
    Modint(T x_) : x(x_ % Mod) {
        if (x >= Mod) x += Mod;
    }

    friend Modint operator+(Modint a, Modint b) {
        a.x += b.x;
        if (a.x >= Mod) a.x -= Mod;
        return a;
    }

    friend Modint operator-(Modint a, Modint b) {
        a.x -= b.x;
        if (a.x >= Mod) a.x += Mod;
        return a;
    }

    friend Modint operator*(Modint a, Modint b) { return (uint64_t)a.x * b.x; }
    friend Modint operator/(Modint a, Modint b) { return a * b.inv(); }
    friend Modint& operator+=(Modint& a, Modint b) { return a = a + b; }
    friend Modint& operator-=(Modint& a, Modint b) { return a = a - b; }
    friend Modint& operator*=(Modint& a, Modint b) { return a = a * b; }
    friend Modint& operator/=(Modint& a, Modint b) { return a = a * b.inv(); }

    Modint inv() const { return pow(Mod - 2); }

    Modint pow(int64_t b) const {
        Modint a = *this, c = 1;
        while (b) {
            if (b & 1) c *= a;
            a *= a;
            b >>= 1;
        }
        return c;
    }
};

}  // namespace math

}  // namespace cscba
