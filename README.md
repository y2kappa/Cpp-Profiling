# Complexity testing with Google Benchmarks

Can see where it's exponential, where it's squared and where it's logarithmic.

## make
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