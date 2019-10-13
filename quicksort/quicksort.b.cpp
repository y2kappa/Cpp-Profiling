#include <benchmark/benchmark.h>
#include <iostream>
#include <random>
#include "quicksort.h"

using namespace std;

void fillVector(vector<int>& vect)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 10.0);

    for(auto& elem : vect)
        elem = dist(mt);
}

static void Quicksort(benchmark::State& state)
{
    for (auto _ : state)
    {
        vector<int> numbers(state.range(0));
        fillVector(numbers);
        quicksort(numbers);
    }
}

BENCHMARK(Quicksort)->RangeMultiplier(5)->Range(2, 10000);
BENCHMARK(Quicksort)->RangeMultiplier(5)->Range(2, 1000000);

BENCHMARK_MAIN();
