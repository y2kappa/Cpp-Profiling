#include <vector>
#include <iostream>
#include "fibonnaci.h"

unsigned int fib_iterative(const unsigned int n)
{
    if (n <= 1)
        return n;

    std::vector<unsigned int> f;
    f.push_back(0);
    f.push_back(1);

    for (int i=2; i <= n; ++i)
    {
        f.push_back(f[i-1] + f[i-2]);
    }
    return f[n];
}

unsigned int fib_recursive(const unsigned int n)
{
    if (n <= 1)
        return n;

    return (fib_recursive(n-1) + fib_recursive(n-2));
}

