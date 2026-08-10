//
// Created by awseder on 10.08.2026.
//

#pragma once
#include <cstddef>
#include <cstdint>
#include <version>

#if __cplusplus < 201703L
    #error "This library requires C++17 or later"
#endif

#define MY_LIBRARY_API inline

#ifdef MY_LIBRARY_COMPILER_MSVC
    #define MY_LIBRARY_NO_DISCARD _NODISCARD
#else
    #define MY_LIBRARY_NO_DISCARD [[nodiscard]]
#endif

namespace my_library::config {
    constexpr std::size_t DEFAULT_BUFFER_SIZE = 4096;
    constexpr bool ENABLE_DEBUG_ASSERTS =
        #ifdef NDEBUG
            false;
        #else
                true;
        #endif
}