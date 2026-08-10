//
// Created by awseder on 10.08.2026.
//

// this test checks different paths to create a common fraction

#include "../include/Core.h"

using cfr = fr::CommonFraction;

int main() {
    std::cout << "Test 1: creating common fractions" << std::endl;
    cfr f1(3,4);
    cfr f2(75,125);
    cfr f3(2);
    cfr f4(0.25);
    cfr f5(1.25);
    cfr f6(3.45, 6.005);
    cfr f7(cfr(3,4), cfr(0.4));
    f1.print("f1: ","\n");
    f2.print("f2: ","\n");
    f3.print("f3: ","\n");
    f4.print("f4: ","\n");
    f5.print("f5: ","\n");
    f6.print("f6: ","\n");
    f7.print("f7: ","\n");
    return 0;
}