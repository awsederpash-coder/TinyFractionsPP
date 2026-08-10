# TinyFractionsPP
C++ library allowing create fractions and perform calculations with them. Perfect for mathematicians and physicists.

## Description
This light library made for easy work with common fractions. You can crate them from two integer, double and even two other fractions. Its possible to compare, sum, subtract, multiply, divide and raise to a power. Fractions are necessary for mathematicians and physicists to very accurate calculations, so they aren't convert to decimal.

## Istallation
Clone this repository by https or ssh:
```bash
git clone https://github.com/awsederpash-coder/TinyFractionsPP.git
git clone git@github.com:awsederpash-coder/TinyFractionsPP.git
```
Move lib to any directory you like.
Import:
```C++
#include "/path/to/lib/include/Core.h"
```
In CMakeLists.txt paste:
```CMake
add_library(tiny_fractions INTERFACE)
target_include_directories(tiny_fractions INTERFACE /path/to/lib/)
target_link_libraries(your_app_or_lib PRIVATE tiny_fractions)
```

## Usage
All methods and classes are int namespace fr.
Fractions class: fr::CommonFraction
Constructors:
 - (int64,int64)
 - (int64)
 - (double,double)
 - (double)
 - (CommonFraction, CommonFraction)

Methods:
 - print(string start, string end) -> void
 - getFull() -> pair(int64,int64)
 - getNumerator() -> int64
 - getDenominator() -> unsigned int64
 - getDecimal() -> double

Functions:
 - fr::power(fr::CommonFraction, int) -> fr::CommomFraction
 - fr::bring(fr::CommonFraction, fr::CommonFraction) -> pair<CommonFraction,CommonFraction>

Operators:
 - \+
 - \-
 - \*
 - \/

```C++
using cfr = fr::CommonFraction;
using int64 = long long;
using uint64 = unsigned long long;

int main() {
    cfr fr1(3,5);
    cfr fr2(-0.7);
    cfr fr3(fr1,fr2);
    (cfr1*cf2).print("Res1: ","\n");
    (cfr1+cf3).print("Res2: ","\n");
    (cfr1-cf2).print("Res3: ","\n");
    fr::power(fr2,3).print("Res4: ","\n");
    return 0;
}
```

## License
Apache2.0 © Apache Software Foundation
