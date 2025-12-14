#pragma once
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif

namespace std {}
namespace cscba {
namespace templates {}
namespace math {}
namespace data_structure {
namespace segment_tree {}
}  // namespace data_structure
namespace string {};
}  // namespace cscba

using namespace std;
using namespace cscba::templates;
using namespace cscba::math;
using namespace cscba::data_structure;
using namespace cscba::data_structure::segment_tree;
using namespace cscba::string;
