#include <benchmark/benchmark.h>
#include <iostream>
#include <random>
#include "vector.h"
#include "../quicksort/quicksort.h"

using namespace std;

void fillVector(Vector<int>& vect)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 10.0);

    for(auto& elem : vect)
        elem = dist(mt);
}

static void Find(benchmark::State& state)
{
    for (auto _ : state)
    {
        Vector<int> numbers(state.range(0));
        fillVector(numbers);
        // quicksort(numbers);
        for(auto& elem : numbers)
        {
            std::cout << elem << std::endl;
        }
    }
}

BENCHMARK(Quicksort)->RangeMultiplier(5)->Range(2, 10000);
BENCHMARK(Quicksort)->RangeMultiplier(5)->Range(2, 1000000);

BENCHMARK_MAIN();
