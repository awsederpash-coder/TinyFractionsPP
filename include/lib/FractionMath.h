//
// Created by awseder on 09.08.2026.
//

#pragma once

#include "Fwd.h"
#include "CommonFraction.h"
#include <utility>

using int64 = long long;
using uint64 = unsigned long long;


[[nodiscard]] inline std::pair<fr::CommonFraction, fr::CommonFraction> fr::bring(CommonFraction & a, CommonFraction & b) {
    uint64 l {_lcm(a.getDenominator(),b.getDenominator())};
    int64 k1{static_cast<int64>(l/a.getDenominator())}, k2{static_cast<int64>(l/b.getDenominator())};
    return {{static_cast<int64>(a.getNumerator()*k1),static_cast<int64>(l)}, {static_cast<int64>(b.getNumerator()*k2),static_cast<int64>(l)}};
}

[[nodiscard]] inline fr::CommonFraction fr::power(CommonFraction & a, int n) {
    return {static_cast<int64>(_pow(a.getNumerator(),n)),static_cast<int64>(_pow(a.getDenominator(),n))};
}

inline int64 fr::_pow(int64 a, int n) {
    int64 b{1LL};
    while (n > 0) {
        if (n & 1) b *= a;
        a *= a;
        n >>= 1;
    }
    return b;
}

inline uint64 fr::_pow(uint64 a, int n) {
    uint64 b{1ULL};
    while (n > 0) {
        if (n & 1) b *= a;
        a *= a;
        n >>= 1;
    }
    return b;
}

inline int64 fr::_gcd(int64 a, int64 b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    return static_cast<int64>(_gcd(static_cast<uint64>(a),static_cast<uint64>(b)));
}

inline uint64 fr::_gcd(uint64 a, uint64 b) {
    uint64 t;
    while (b != 0) {
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}

inline int64 fr::_lcm(int64 a, int64 b) {
    int64 g {_gcd(a,b)};
    int64 c {a*b};
    if (c < 0) c = -c;
    return c/g;
}

inline uint64 fr::_lcm(uint64 a, uint64 b) {
    uint64 g {_gcd(a,b)};
    uint64 c {a*b};
    return c/g;
}
