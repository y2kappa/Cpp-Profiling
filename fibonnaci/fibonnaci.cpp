#include <vector>
#include <iostream>
#include "fibonnaci.h"

unsigned int fib_iterative(const unsigned int n)
{
    if (n <= 1) return n;
    std::vector<unsigned int> f{0, 1};
    for (size_t i=2; i <= n; ++i) { f.push_back(f[i-1] + f[i-2]); }
    return f[n];
}

unsigned int fib_recursive(const unsigned int n)
{
    if (n <= 1) return n;
    return (fib_recursive(n-1) + fib_recursive(n-2));
}

