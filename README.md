# Complexity & Unit testing with Google Benchmarks & Tests


## What's it about

Demo usage of [Google Benchmark](https://github.com/google/benchmark) and [Google Test](https://github.com/google/googletest) to illustrate correctness and complexity of algorithms and implementations. **It's easy conceptually to understand what O(logn) complexity means but it's doesn't really relate to any real life values. How bad is O(n2) vs O(logn) in real life, in what situations, what inputs?**

**For example recursive fibonnaci (exponential took) 91.138250241 seconds for 50 elements, whereas the linear complexity algo took 0.000002 seconds. That's like 10^8 longer.**

Example:
- Fibonnaci recursive where it's exponential:
```cpp
unsigned int fib_recursive(const unsigned int n)
{
    if (n <= 1)
        return n;

    return (fib_recursive(n-1) + fib_recursive(n-2));
}
```
- Fibonacci linear with vectors
```cpp
unsigned int fib_iterative(const unsigned int n)
{
    if (n <= 1) return n;

    std::vector<unsigned int> f{0, 1};

    for (size_t i=2; i <= n; ++i) { f.push_back(f[i-1] + f[i-2]); }
    return f[n];
}
```

Test:

```
: g++ fibonnaci.t.cpp fibonnaci.cpp -o fibonnaci.t.tsk --std=c++14 -L googletest/ -l gtest
: ./fibonnaci.t.tsk
[==========] Running 7 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 3 tests from Iterative
[ RUN      ] Iterative.Works0
[       OK ] Iterative.Works0 (0 ms)
[ RUN      ] Iterative.Works1
[       OK ] Iterative.Works1 (0 ms)
[ RUN      ] Iterative.Works2
[       OK ] Iterative.Works2 (0 ms)
[----------] 3 tests from Iterative (0 ms total)

[----------] 3 tests from Recursive
[ RUN      ] Recursive.Works0
[       OK ] Recursive.Works0 (0 ms)
[ RUN      ] Recursive.Works1
[       OK ] Recursive.Works1 (0 ms)
[ RUN      ] Recursive.Works2
[       OK ] Recursive.Works2 (0 ms)
[----------] 3 tests from Recursive (0 ms total)

[----------] 1 test from Both
[ RUN      ] Both.Work
[       OK ] Both.Work (0 ms)
[----------] 1 test from Both (0 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 3 test cases ran. (0 ms total)
[  PASSED  ] 7 tests.
```

Benchmarking:

```
: _build/fibonnaci/fibonnaci.b.tsk
Run on (4 X 2900 MHz CPU s)
2019-10-13 14:30:34
***WARNING*** Library was built as DEBUG. Timings may be affected.
--------------------------------------------------------------
Benchmark                       Time           CPU Iterations
--------------------------------------------------------------
FibonnaciRecursive/2           14 ns         14 ns   48074282
FibonnaciRecursive/4           28 ns         28 ns   23950293
FibonnaciRecursive/8          157 ns        156 ns    4488417
FibonnaciRecursive/16        7073 ns       7066 ns      98453
FibonnaciRecursive/32    15670324 ns   15598578 ns         45
FibonnaciRecursive/40   744359036 ns  739870000 ns          1
FibonnaciIterative/2          425 ns        425 ns    1633571
FibonnaciIterative/4          762 ns        760 ns     925583
FibonnaciIterative/8         1150 ns       1148 ns     602830
FibonnaciIterative/16        1661 ns       1643 ns     433152
FibonnaciIterative/32        2372 ns       2361 ns     296665
FibonnaciIterative/40        2551 ns       2546 ns     275310
FibonnaciRecursive/2           14 ns         14 ns   48525181
FibonnaciRecursive/4           28 ns         28 ns   24806773
FibonnaciRecursive/8          156 ns        156 ns    4402820
FibonnaciRecursive/16        7095 ns       7075 ns      98825
FibonnaciRecursive/32    15637451 ns   15610444 ns         45
FibonnaciRecursive/50  91138250241 ns 90809938000 ns          1
FibonnaciIterative/2          507 ns        499 ns    1401595
FibonnaciIterative/4          812 ns        802 ns     816041
FibonnaciIterative/8         1316 ns       1287 ns     607602
FibonnaciIterative/16        1719 ns       1705 ns     434119
FibonnaciIterative/32        2668 ns       2649 ns     276627
FibonnaciIterative/50        2828 ns       2809 ns     235543
FibonnaciRecursive/2           16 ns         15 ns   46622531
FibonnaciRecursive/4           30 ns         30 ns   23499080
FibonnaciRecursive/8          172 ns        170 ns    4459082
FibonnaciRecursive/16        7724 ns       7612 ns      87275
FibonnaciRecursive/32    17876766 ns   17641286 ns         42
^C

```

**Had to cancel just because it took 30 minutes and nothing happened.**


## Build
```
git clone git@github.com:y2kappa/CppProfiling.git
cd CppProfiling
git clone git@github.com:google/benchmark.git
git clone git@github.com:google/googletest.git

mkdir -p _build/fibonnaci
g++ fibonnaci/fibonnaci.b.cpp fibonnaci/fibonnaci.cpp -o _build/fibonnaci/fibonnaci.b.tsk --std=c++14 -L benchmark/ -lbenchmark

```


## run

```log

: ./benching.tsk
Run on (4 X 2900 MHz CPU s)
2019-08-25 04:09:16
***WARNING*** Library was built as DEBUG. Timings may be affected.
-------------------------------------------------------------
Benchmark                      Time           CPU Iterations
-------------------------------------------------------------
FibonnaciRecursive/2          15 ns         15 ns   45976106
FibonnaciRecursive/4          32 ns         32 ns   22769189
FibonnaciRecursive/8         168 ns        167 ns    4273896
FibonnaciRecursive/16       7225 ns       7219 ns      90525
FibonnaciRecursive/32   16053097 ns   15963143 ns         42
FibonnaciRecursive/40  766053148 ns  760997000 ns          1
FibonnaciIterative/2         695 ns        683 ns     913171
FibonnaciIterative/4        1023 ns       1019 ns     646669
FibonnaciIterative/8        1676 ns       1667 ns     483920
FibonnaciIterative/16       1930 ns       1924 ns     352033
FibonnaciIterative/32       2729 ns       2724 ns     262076
FibonnaciIterative/40       2894 ns       2884 ns     241814
Quicksort/2                15890 ns      15849 ns      41328
Quicksort/5                16186 ns      16148 ns      41710
Quicksort/25               19497 ns      19470 ns      35396
Quicksort/125              36053 ns      35748 ns      19792
Quicksort/625             113887 ns     113776 ns       5709
Quicksort/3125            533726 ns     531958 ns       1138
Quicksort/10000          1733108 ns    1731115 ns        381
Bubblesort/2               15842 ns      15822 ns      42745
Bubblesort/5               16512 ns      16458 ns      41593
Bubblesort/25              20462 ns      20440 ns      31675
Bubblesort/125             66807 ns      66549 ns       9514
Bubblesort/625            878584 ns     875883 ns        735
Bubblesort/3125         19957159 ns   19880171 ns         35
Bubblesort/10000       197616120 ns  197015667 ns          3

```

## TODO

- [ ] Create table for execution time for diff algos & impls
- [ ] Add tests for:
  - [ ] Heapsort
  - [ ] N Body Problem Calculations
  - [ ] FizzBuzz
  - [ ] Matrix Multiplication
  - [ ] Sudoku solver
  - [ ] Multi threading test
  - [ ] Concurrent Hash Maps
  - [ ]

- [ ] Check new releases from lib and test use them
  - [ ] test https://github.com/google/googletest
  - [ ] bench https://github.com/google/benchmark
- [ ] Check property base testing in C++
- [ ] Try to call into Rust (FFI)
- [ ] Contribute to the same lib for Rust
  - [ ] https://github.com/bheisler/criterion.rs
- [ ] Property based testing Rust
  - [ ] https://github.com/BurntSushi/quickcheck
  - [ ] https://github.com/AltSysrq/proptest
- [ ] Add CMake
- [ ]