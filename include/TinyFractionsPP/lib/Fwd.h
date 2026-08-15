//
// Created by awseder on 10.08.2026.
//

#pragma once
#include <utility>

using int64 = long long;
using uint64 = unsigned long long;

namespace fr {
    class CommonFraction;


    [[nodiscard]] inline std::pair<CommonFraction,CommonFraction> bring(CommonFraction &, CommonFraction &);
    [[nodiscard]] inline CommonFraction power(CommonFraction &, int);
    inline int64 _pow(int64, int);
    inline uint64 _pow(uint64, int);
    inline int64 _gcd(int64, int64);
    inline uint64 _gcd(uint64, uint64);
    inline int64 _lcm(int64, int64);
    inline uint64 _lcm(uint64, uint64);

    constexpr bool operator==(int64, const CommonFraction &) noexcept;
    inline bool operator==(double, const CommonFraction &) noexcept;
    constexpr bool operator!=(int64, const CommonFraction &) noexcept;
    inline bool operator!=(double, const CommonFraction &) noexcept;
    constexpr bool operator>(int64, const CommonFraction &) noexcept;
    inline bool operator>(double, const CommonFraction &) noexcept;
    constexpr bool operator>=(int64, const CommonFraction &) noexcept;
    inline bool operator>=(double, const CommonFraction &) noexcept;
    constexpr bool operator<(int64, const CommonFraction &) noexcept;
    inline bool operator<(double, const CommonFraction &) noexcept;
    constexpr bool operator<=(int64, const CommonFraction &) noexcept;
    inline bool operator<=(double, const CommonFraction &) noexcept;
    inline CommonFraction operator*(int64, const CommonFraction &) noexcept;
    inline CommonFraction operator*(double, const CommonFraction &) noexcept;
    inline CommonFraction operator/(int64, const CommonFraction &) noexcept;
    inline CommonFraction operator/(double, const CommonFraction &) noexcept;
    inline CommonFraction operator+(int64, const CommonFraction &) noexcept;
    inline CommonFraction operator+(double, const CommonFraction &) noexcept;
    inline CommonFraction operator-(int64, const CommonFraction &) noexcept;
    inline CommonFraction operator-(double, const CommonFraction &) noexcept;

}
