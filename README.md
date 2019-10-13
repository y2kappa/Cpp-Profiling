# Complexity testing with Google Benchmarks

Demo usage of [Google Benchmark](https://github.com/google/benchmark) and [Google Test](https://github.com/google/googletest) to illustrate correctness and complexity of algorithms and implementations.

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

Behchmarking:

```

```

Can see where it's exponential, where it's squared and where it's logarithmic.



## Build
```sh
git clone https://github.com/google/benchmark.git
g++ benching.cpp bubblesort.cpp fibonnaci.cpp quicksort.cpp -o benching.tsk --std=c++11  -lbenchmark -L benchmark/
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