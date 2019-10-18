#ifndef KW_TESTLIB_HPP
#define KW_TESTLIB_HPP
// Head files
#ifndef STD_BITS_STDCPP_H
#define STD_BITS_STDCPP_H
#include <bits/stdc++.h>
#endif
#ifndef STD_WINDOWS_H
#define STD_WINDOWS_H
#include <windows.h>
#endif
// Function Definition
namespace kw {
    long long random(long long, long long);
}
// Function Realization
namespace kw {
    inline long long random(long long a, long long b) {
        return (((rand() * 1ll) << 45) | ((rand() * 1ll) << 30) | ((rand() * 1ll) << 15) | (rand() * 1ll)) % (b - a + 1) + a;
    }
}
#endif