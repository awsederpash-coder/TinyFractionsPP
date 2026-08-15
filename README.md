# TinyFractionsPP
C++ library allowing to create fractions and perform calculations with them. Perfect for mathematicians and physicists.

## Description
This light library made for easy work with common fractions. You can crate them from two integer, double and even two other fractions. It's possible to compare, sum, subtract, multiply, divide and raise to a power. Fractions are necessary for mathematicians and physicists to very accurate calculations, so they aren't convert to decimal every operation.

## Install
Clone this repository by https or ssh:
```bash
git clone https://github.com/awsederpash-coder/TinyFractionsPP.git
git clone git@github.com:awsederpash-coder/TinyFractionsPP.git
сd TinyFractionsPP
```
Configure:
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
```
And build:
```bash
cmake --build build --target install
```
In CMakeLists.txt at your project insert:
```cmake
find_package(TinyFractionsPP 0.2 REQUIRED)
add_executable(my_program main.cpp)
target_link_libraries(my_program PRIVATE TinyFractionsPP::TinyFractionsPP)
```
Now it's easy to import my library from any source file:
```c++
#include <TinyFractions/Core.h>
```

## Usage
All methods and classes are int namespace *fr*.
Fractions class: fr::CommonFraction.
Constructors:
 - (int64,int64)
 - (int64)
 - (double,double)
 - (double)
 - (CommonFraction, CommonFraction)

Methods:
 - print(string start, string end) → void
 - getFull() → pair(int64,int64)
 - getNumerator() → int64
 - getDenominator() → unsigned int64
 - getDecimal() → double

Functions:
 - fr::power(fr::CommonFraction, int) → fr::CommonFraction
 - fr::bring(fr::CommonFraction, fr::CommonFraction) → pair<CommonFraction,CommonFraction>

Operators:
 - \+
 - \-
 - \*
 - \/

Comparison and arithmetic operators work between fractions as well as with *int* and *double*.

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
