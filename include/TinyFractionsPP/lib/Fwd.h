//
// Created by awseder on 10.08.2026.
//

#pragma once
#include <utility>

#include "CommonFraction.h"

using int64 = long long;
using uint64 = unsigned long long;

namespace fr {
    class CommonFraction {
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
            [[nodiscard]] CommonFraction reversed() const;


            // operators
            constexpr bool operator==(const CommonFraction &) const noexcept;
            constexpr bool operator==(int64) const noexcept;
            bool operator==(double) const noexcept;

            constexpr bool operator!=(const CommonFraction &) const noexcept;
            constexpr bool operator!=(int64) const noexcept;
            bool operator!=(double) const noexcept;

            constexpr bool operator>(const CommonFraction &) const noexcept;
            constexpr bool operator>(int64) const noexcept;
            bool operator>(double) const noexcept;

            constexpr bool operator<(const CommonFraction &) const noexcept;
            constexpr bool operator<(int64) const noexcept;
            bool operator<(double) const noexcept;

            constexpr bool operator>=(const CommonFraction &) const noexcept;
            constexpr bool operator>=(int64) const noexcept;
            bool operator>=(double) const noexcept;

            constexpr bool operator<=(const CommonFraction &) const noexcept;
            constexpr bool operator<=(int64) const noexcept;
            bool operator<=(double) const noexcept;

            CommonFraction operator+(const CommonFraction &) const noexcept;
            CommonFraction operator+(int64) const noexcept;
            CommonFraction operator+(double) const noexcept;

            CommonFraction operator-(const CommonFraction &) const noexcept;
            CommonFraction operator-(int64) const noexcept;
            CommonFraction operator-(double) const noexcept;

            CommonFraction operator*(const CommonFraction &) const noexcept;
            CommonFraction operator*(int64) const noexcept;
            CommonFraction operator*(double) const noexcept;

            CommonFraction operator/(const CommonFraction &) const noexcept;
            CommonFraction operator/(int64) const noexcept;
            CommonFraction operator/(double) const noexcept;

        private:
            int64 m_num;
            uint64 m_denom;
            void _bring();
    };


    [[nodiscard]] inline std::pair<CommonFraction,CommonFraction> bring(CommonFraction &, CommonFraction &);
    [[nodiscard]] inline CommonFraction power(CommonFraction &, int);
    inline int64 _pow(int64, int);
    inline uint64 _pow(uint64, int);
    inline int64 _gcd(int64, int64);
    inline uint64 _gcd(uint64, uint64);
    inline int64 _lcm(int64, int64);
    inline uint64 _lcm(uint64, uint64);

    constexpr bool operator==(int64, const CommonFraction &) noexcept;
    constexpr bool operator==(int, const CommonFraction &) noexcept;
    inline bool operator==(double, const CommonFraction &) noexcept;
    constexpr bool operator!=(int64, const CommonFraction &) noexcept;
    constexpr bool operator!=(int, const CommonFraction &) noexcept;
    inline bool operator!=(double, const CommonFraction &) noexcept;
    constexpr bool operator>(int64, const CommonFraction &) noexcept;
    constexpr bool operator>(int, const CommonFraction &) noexcept;
    inline bool operator>(double, const CommonFraction &) noexcept;
    constexpr bool operator>=(int64, const CommonFraction &) noexcept;
    constexpr bool operator>=(int, const CommonFraction &) noexcept;
    inline bool operator>=(double, const CommonFraction &) noexcept;
    constexpr bool operator<(int64, const CommonFraction &) noexcept;
    constexpr bool operator<(int, const CommonFraction &) noexcept;
    inline bool operator<(double, const CommonFraction &) noexcept;
    constexpr bool operator<=(int64, const CommonFraction &) noexcept;
    constexpr bool operator<=(int, const CommonFraction &) noexcept;
    inline bool operator<=(double, const CommonFraction &) noexcept;
    inline CommonFraction operator*(int64, const CommonFraction &) noexcept;
    inline CommonFraction operator*(int, const CommonFraction &) noexcept;
    inline CommonFraction operator*(double, const CommonFraction &) noexcept;
    inline CommonFraction operator/(int64, const CommonFraction &) noexcept;
    inline CommonFraction operator/(int, const CommonFraction &) noexcept;
    inline CommonFraction operator/(double, const CommonFraction &) noexcept;
    inline CommonFraction operator+(int64, const CommonFraction &) noexcept;
    inline CommonFraction operator+(int, const CommonFraction &) noexcept;
    inline CommonFraction operator+(double, const CommonFraction &) noexcept;
    inline CommonFraction operator-(int64, const CommonFraction &) noexcept;
    inline CommonFraction operator-(int, const CommonFraction &) noexcept;
    inline CommonFraction operator-(double, const CommonFraction &) noexcept;

}
