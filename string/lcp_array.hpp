#pragma once

#include <string>
#include <vector>

namespace cscba {

namespace string {

inline std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
    int n = s.size();
    std::vector<int> pos(n), lcp(n - 1);
    for (int i = 0; i < n; ++i) {
        pos[sa[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (pos[i] == n - 1) continue;
        int st = std::max(0, ((i == 0 or pos[i - 1] == n - 1) ? 0 : lcp[pos[i - 1]] - 1));
        lcp[pos[i]] = st;
        for (int j = 0; j < std::min(n - i, n - sa[pos[i] + 1]); ++j) {
            if (s[i + st + j] != s[sa[pos[i] + 1] + st + j]) {
                break;
            }
            ++lcp[pos[i]];
        }
    }
    return lcp;
}
}  // namespace string
}  // namespace cscba
