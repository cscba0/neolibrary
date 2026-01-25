#include "../../math/fraction.hpp"
#include "../floating/write.hpp"

namespace cscba {

namespace FastIO {

template <typename T>
inline FastIO& operator<<(FastIO& io, cscba::math::Fraction<T> x) {
    io << (long double){x.x} / (long double){x.y};
    return io;
}

}  // namespace FastIO

}  // namespace cscba
