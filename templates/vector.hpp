#pragma once
#include <iostream>
#include <vector>

template <typename T>
void operator--(std::vector<T>& v) {
    for (auto& e : v) {
        --e;
    }
}

template <typename T>
void operator++(std::vector<T>& v) {
    for (auto& e : v) {
        ++e;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    for (uint i = 0, siz = v.size(); i < siz; ++i) {
        os << v[i] << (i + 1 == siz ? "" : " ");
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& st, std::vector<T>& v) {
    for (auto& x : v) {
        st >> x;
    }
    return st;
}
