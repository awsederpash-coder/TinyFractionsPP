//
// Created by awseder on 12.08.2026.
//

#pragma once

#include "Fwd.h"


using int64 = long long;

constexpr bool fr::operator==(int64 x, const CommonFraction & frc) noexcept {
    return frc.operator==(x);
}
constexpr bool fr::operator==(int x, const CommonFraction & frc) noexcept {
    return frc.operator==(static_cast<int64>(x));
}
inline bool fr::operator==(double x, const CommonFraction & frc) noexcept {
    return frc == x;
}
constexpr bool fr::operator!=(int64 x, const CommonFraction & frc) noexcept {
    return frc != x;
}

constexpr bool fr::operator!=(int x, const CommonFraction & frc) noexcept {
    return frc != static_cast<int64>(x);
}

inline bool fr::operator!=(double x, const CommonFraction & frc) noexcept {
    return frc != x;
}
constexpr bool fr::operator>(int64 x, const CommonFraction & frc) noexcept {
    return frc > x;
}

constexpr bool fr::operator>(int x, const CommonFraction & frc) noexcept {
    return frc > static_cast<int64>(x);
}

inline bool fr::operator>(double x, const CommonFraction & frc) noexcept {
    return frc > x;
}
constexpr bool fr::operator>=(int64 x, const CommonFraction & frc) noexcept {
    return frc >= x;
}

constexpr bool fr::operator>=(int x, const CommonFraction & frc) noexcept {
    return frc >= static_cast<int64>(x);
}

inline bool fr::operator>=(double x, const CommonFraction & frc) noexcept {
    return frc >= x;
}
constexpr bool fr::operator<(int64 x, const CommonFraction & frc) noexcept {
    return frc < x;
}

constexpr bool fr::operator<(int x, const CommonFraction & frc) noexcept {
    return frc < static_cast<int64>(x);
}

inline bool fr::operator<(double x, const CommonFraction & frc) noexcept {
    return frc < x;
}
constexpr bool fr::operator<=(int64 x, const CommonFraction & frc) noexcept {
    return frc <= x;
}

constexpr bool fr::operator<=(int x, const CommonFraction & frc) noexcept {
    return frc <= static_cast<int64>(x);
}

inline bool fr::operator<=(double x, const CommonFraction & frc) noexcept {
    return frc <= x;
}
inline fr::CommonFraction fr::operator*(int64 x, const CommonFraction & frc) noexcept {
    return frc * x;
}

inline fr::CommonFraction fr::operator*(int x, const CommonFraction & frc) noexcept {
    return frc * static_cast<int64>(x);
}

inline fr::CommonFraction fr::operator*(double x, const CommonFraction & frc) noexcept {
    return frc * x;
}
inline fr::CommonFraction fr::operator/(int64 x, const CommonFraction & frc) noexcept {
    return frc / x;
}

inline fr::CommonFraction fr::operator/(int x, const CommonFraction & frc) noexcept {
    return frc / static_cast<int64>(x);
}

inline fr::CommonFraction fr::operator/(double x, const CommonFraction & frc) noexcept {
    return frc / x;
}
inline fr::CommonFraction fr::operator+(int64 x, const CommonFraction & frc) noexcept {
    return frc + x;
}

inline fr::CommonFraction fr::operator+(int x, const CommonFraction & frc) noexcept {
    return frc + static_cast<int64>(x);
}

inline fr::CommonFraction fr::operator+(double x, const CommonFraction & frc) noexcept {
    return frc + x;
}
inline fr::CommonFraction fr::operator-(int64 x, const CommonFraction & frc) noexcept {
    return frc - x;
}

inline fr::CommonFraction fr::operator-(int x, const CommonFraction & frc) noexcept {
    return frc - static_cast<int64>(x);
}

inline fr::CommonFraction fr::operator-(double x, const CommonFraction & frc) noexcept {
    return frc - x;
}