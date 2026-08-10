//
// Created by awseder on 07.08.2026.
//

#pragma once

#include "Fwd.h"
#include <utility>
#include <stdexcept>
#include <cmath>
#include <iostream>


using int64 = long long;
using uint64 = unsigned long long;

class fr::CommonFraction {
public:
    // constructors
    CommonFraction(int64, int64);
    CommonFraction(int, int);
    CommonFraction(int64);
    CommonFraction(int);
    CommonFraction(double);
    CommonFraction(double,double);
    CommonFraction(const CommonFraction &, const CommonFraction &);
    // print
    void print(std::string_view, std::string_view) const;
    // get
    [[nodiscard]] std::pair<int64,int64> getFull() const;
    [[nodiscard]] double getDecimal() const;
    [[nodiscard]] uint64 getNumerator() const;
    [[nodiscard]] uint64 getDenominator() const;
    [[nodiscard]] bool isPositive() const;
    [[nodiscard]] bool isNegative() const;
    // operators
    bool operator==(const CommonFraction &) const;
    bool operator!=(const CommonFraction &) const;
    bool operator>(const CommonFraction &) const;
    bool operator<(const CommonFraction &) const;
    bool operator>=(const CommonFraction &) const;
    bool operator<=(const CommonFraction &) const;
    CommonFraction operator+(const CommonFraction &) const;
    CommonFraction operator-(const CommonFraction &) const;
    CommonFraction operator*(const CommonFraction &) const;
    CommonFraction operator/(const CommonFraction &) const;

private:
    int64 m_num;
    uint64 m_denom;
    void _bring();
};

inline fr::CommonFraction::CommonFraction(int64 numerator, int64 denominator) {
    if (denominator == 0) throw std::runtime_error("denominator cannot be 0!");
    if (denominator < 0) {numerator = -numerator; denominator = -denominator;}
    m_num = numerator;
    m_denom = static_cast<uint64>(denominator);
    _bring();
}

inline fr::CommonFraction::CommonFraction(int numerator, int denominator) : CommonFraction(static_cast<int64>(numerator), static_cast<int64>(denominator)) {}

inline fr::CommonFraction::CommonFraction(int64 numerator) {
    m_num = numerator;
    m_denom = 1ULL;
}

inline fr::CommonFraction::CommonFraction(int numerator) : CommonFraction(static_cast<int64>(numerator)){}

inline fr::CommonFraction::CommonFraction(double x) {
    uint64 d{1};
    double intP;
    while (std::abs(std::modf(x,&intP)) > 1e-9) {
        d *= 10;
        x *=10;
    }
    m_num = static_cast<int64>(x);
    m_denom = d;
    _bring();
}

inline fr::CommonFraction::CommonFraction(double x, double y) : CommonFraction(CommonFraction(x),CommonFraction(y)){}

inline fr::CommonFraction::CommonFraction(const CommonFraction & numerator, const CommonFraction & denominator) {
    m_num = numerator.m_num * static_cast<int64>(denominator.m_denom);
    int64 denom = static_cast<int64>(numerator.m_denom) * denominator.m_num;
    if (denom == 0) throw std::runtime_error("denominator cannot be 0!");
    if (denom < 0) {denom = -denom;m_num = -m_num;}
    m_denom = static_cast<uint64>(denom);
    _bring();
}

inline void fr::CommonFraction::print(std::string_view start="", std::string_view end = "") const {
    std::cout << start << m_num << '/' << m_denom << end;
}

inline std::pair<int64, int64> fr::CommonFraction::getFull() const {
    return {m_num,m_denom};
}
inline uint64 fr::CommonFraction::getNumerator() const {
    return static_cast<uint64>(std::abs(m_num));
}
inline uint64 fr::CommonFraction::getDenominator() const {
    return m_denom;
}
inline bool fr::CommonFraction::isPositive() const {
    return m_num > 0;
}
inline bool fr::CommonFraction::isNegative() const {
    return m_num < 0;
}
inline double fr::CommonFraction::getDecimal() const {
    return static_cast<double>(m_num)/static_cast<double>(m_denom);
}


inline bool fr::CommonFraction::operator==(const CommonFraction &other) const {
    return m_num*other.m_denom == m_denom*other.m_num;
}

inline bool fr::CommonFraction::operator!=(const CommonFraction &other) const {
    return m_num*other.m_denom != m_denom*other.m_num;
}

inline bool fr::CommonFraction::operator>(const CommonFraction &other) const {
    return m_num*other.m_denom > m_denom*other.m_num;
}
inline bool fr::CommonFraction::operator<(const CommonFraction &other) const {
    return m_num*other.m_denom < m_denom*other.m_num;
}
inline bool fr::CommonFraction::operator>=(const CommonFraction &other) const {
    return m_num*other.m_denom >= m_denom*other.m_num;
}
inline bool fr::CommonFraction::operator<=(const CommonFraction &other) const {
    return m_num*other.m_denom <= m_denom*other.m_num;
}
inline fr::CommonFraction fr::CommonFraction::operator*(const CommonFraction &other) const {
    return {m_num*other.m_num, static_cast<int64>(m_denom*other.m_denom)};
}
inline fr::CommonFraction fr::CommonFraction::operator/(const CommonFraction &other) const {
    return {static_cast<int64>(m_num*other.m_denom), static_cast<int64>(m_denom*other.m_num)};
}

inline fr::CommonFraction fr::CommonFraction::operator+(const CommonFraction &other) const {
    uint64 l = _lcm(m_denom, other.m_denom);
    uint64 k1{l/m_denom}, k2{l/other.m_denom};
    return {static_cast<int64>(m_num*k1+other.m_num*k2), static_cast<int64>(l)};
}
inline fr::CommonFraction fr::CommonFraction::operator-(const CommonFraction &other) const {
    uint64 l = _lcm(m_denom, other.m_denom);
    uint64 k1{l/m_denom}, k2{l/other.m_denom};
    return {static_cast<int64>(m_num*k1-other.m_num*k2), static_cast<int64>(l)};
}


inline void fr::CommonFraction::_bring() {
    uint64 abs_num {static_cast<uint64>(m_num < 0 ? -m_num : m_num)};
    uint64 g = _gcd(abs_num, m_denom);
    m_num /= static_cast<int64>(g);
    m_denom /= g;
}
