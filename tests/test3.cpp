//
// Created by awseder on 10.08.2026.
//

// this test checks additional methods of common fractions

#include "../include/Core.h"

using cfr = fr::CommonFraction;

int main() {
    cfr fr1(-5,8);
    std::cout << "Numerator = " << fr1.getNumerator() << "; denominator = " << fr1.getDenominator() << std::endl;
    std::cout << "Full: " << fr1.getFull().first << "/" << fr1.getFull().second << std::endl;
    std::cout << "Decimal: " << fr1.getDecimal() << std::endl;
    std::cout << "Is positive: " << (fr1.isPositive() ? "YES" : "NO") << std::endl;
    std::cout << "Is negative: " << (fr1.isNegative() ? "YES" : "NO") << std::endl;
    return 0;
}