#include <benchmark/benchmark.h>
#include <iostream>
#include <random>
#include "fibonnaci.h"

using namespace std;

void fillVector(vector<int>& vect)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 10.0);

    for(auto& elem : vect)
        elem = dist(mt);
}

static void FibonnaciRecursive(benchmark::State& state)
{
    for (auto _ : state)
    {
        unsigned int f = fib_recursive(state.range(0));
    }

}

static void FibonnaciIterative(benchmark::State& state)
{
    for (auto _ : state)
    {
        unsigned int f = fib_iterative(state.range(0));
    }
}

BENCHMARK(FibonnaciRecursive)->RangeMultiplier(2)->Range(2, 40);
BENCHMARK(FibonnaciIterative)->RangeMultiplier(2)->Range(2, 40);

BENCHMARK_MAIN();
