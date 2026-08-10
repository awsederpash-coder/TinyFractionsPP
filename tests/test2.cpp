//
// Created by awseder on 10.08.2026.
//

// this test checks different math operations with common fractions

#include "../include/Core.h"

using cfr = fr::CommonFraction;

int main() {
    cfr fr1(6, 17);
    cfr fr2(3,5);
    auto res1 = fr1 * fr2;
    auto res2 = fr1 / fr2;
    auto res3 = fr1 + fr2;
    auto res4 = fr1 - fr2;
    auto res5 = fr::power(fr1, 3);
    auto [res6_1,res6_2] = fr::bring(res2,res5);
    res1.print("res1: ","\n");
    res2.print("res2: ","\n");
    res3.print("res3: ","\n");
    res4.print("res4: ","\n");
    res5.print("res5: ","\n");
    res6_1.print("res6_1: ","; "); res6_2.print("res6_2: ","\n");
    std::cout << (res2 == res4 ? "YES" : "NO") << std::endl;
    std::cout << (res2 != res4 ? "YES" : "NO") << std::endl;
    std::cout << (res2 > res4 ? "YES" : "NO") << std::endl;
    std::cout << (res2 >= res4 ? "YES" : "NO") << std::endl;
    std::cout << (res2 < res4 ? "YES" : "NO") << std::endl;
    std::cout << (res2 <= res4 ? "YES" : "NO") << std::endl;
    return 0;
}