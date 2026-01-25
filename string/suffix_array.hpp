#pragma once

#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>

namespace cscba {

namespace string {

inline void induced(std::vector<int>& ind, const std::vector<int>& v, int upper, const std::vector<int>& ls, const std::vector<int>& lms) {
    std::vector<int> cnt(upper);
    std::fill(ind.begin(), ind.begin() + v.size(), -1);
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        ++cnt[v[i]];
    }
    std::vector<int> sum(upper, 0);
    for (int i = 1; i < upper; ++i) {
        cnt[i] += cnt[i - 1];
    }
    {
        for (int i : lms | std::ranges::views::reverse) {
            ind[cnt[v[i]] - sum[v[i]] - 1] = i;
            ++sum[v[i]];
        }
    }
    {
        std::fill(sum.begin(), sum.end(), 0);
        if (!ls[n - 1]) {
            ind[cnt[v[n - 1] - 1] + sum[v[n - 1]]] = n - 1;
            ++sum[v[n - 1]];
        }
        for (int i = 0; i < n; ++i) {
            if (ind[i] == -1 or ind[i] == 0) {
                continue;
            }
            if (ls[ind[i] - 1]) {
                continue;
            }
            ind[cnt[v[ind[i] - 1] - 1] + sum[v[ind[i] - 1]]] = ind[i] - 1;
            ++sum[v[ind[i] - 1]];
        }
    }
    {
        std::fill(sum.begin(), sum.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            if (ind[i] == 0) {
                continue;
            }
            if (!ls[ind[i] - 1]) {
                continue;
            }
            ind[cnt[v[ind[i] - 1]] - sum[v[ind[i] - 1]] - 1] = ind[i] - 1;
            ++sum[v[ind[i] - 1]];
        }
    }
}

inline void sa_is(std::vector<int>& ind, std::vector<int>& v, int upper) {
    if (v.size() == 1UZ) {
        ind = {0};
        return;
    }
    if (v.size() == 2UZ) {
        if (v[0] < v[1]) {
            ind = {0, 1};
            return;
        }
        ind = {1, 0};
        return;
    }
    int n = v.size();
    std::vector<int> ls(n), lms, lms_flg(n);
    // true : S
    // false: L
    for (int i = n - 2; i >= 0; --i) {
        if (v[i] == v[i + 1]) {
            ls[i] = ls[i + 1];
        } else {
            ls[i] = v[i] < v[i + 1];
        }
        if (!ls[i] and ls[i + 1]) {
            lms_flg[i + 1] = true;
            lms.emplace_back(i + 1);
        }
        if (i == 0 and ls[i]) {
            lms_flg[0] = true;
            lms.emplace_back(0);
        }
    }
    std::vector<int> len(n);
    std::reverse(lms.begin(), lms.end());
    if (lms.empty()) {
        std::iota(ind.begin(), ind.begin() + v.size(), 0);
        reverse(ind.begin(), ind.begin() + v.size());
        return;
    }
    len[lms.back()] = n - lms.back();
    for (int i = 0; i < (int)lms.size() - 1; ++i) {
        len[lms[i]] = lms[i + 1] - lms[i] + 1;
    }
    std::vector<int> o;
    int _upper = 2;
    {
        induced(ind, v, upper, ls, lms);
        {
            std::vector<int> t(n);
            int lst = -1;
            for (int j = 0; j < (int)v.size(); ++j) {
                int i = ind[j];
                if (!lms_flg[i]) {
                    continue;
                }
                if (lst == -1) {
                    t[i] = 1;
                } else {
                    int flg = [&] -> int {
                        if (len[lst] != len[i]) return 1;
                        for (int j = 0; j < len[lst]; ++j) {
                            if (v[lst + j] != v[i + j]) {
                                return 1;
                            }
                        }
                        return 0;
                    }();
                    _upper += flg;
                    t[i] = t[lst] + flg;
                }
                lst = i;
            }
            for (int i : lms) {
                o.emplace_back(t[i]);
            }
        }
    }
    sa_is(ind, o, _upper);
    {
        std::vector<int> ordered_lms;
        for (int i = 0; i < (int)lms.size(); ++i) {
            ordered_lms.emplace_back(lms[ind[i]]);
        }
        lms = ordered_lms;
    }
    std::vector<int> res(v.size());
    induced(res, v, upper, ls, lms);
    ind = res;
    return;
}

inline std::vector<int> suffix_array(std::vector<int>& v) {
    std::vector<int> ind(v.size());
    int m = 0;
    for (auto& e : v) {
        ++e;
        m = std::max(m, e);
    }
    sa_is(ind, v, m + 1);
    return ind;
}

inline std::vector<int> suffix_array(const std::string& s) {
    std::vector<int> v(s.size());
    for (int i = 0; i < (int)s.size(); ++i) {
        v[i] = s[i] - 'a' + 1;
    }
    std::vector<int> ind(v.size());
    sa_is(ind, v, 27);
    return ind;
}

}  // namespace string
}  // namespace cscba
