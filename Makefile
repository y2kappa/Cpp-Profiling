: mkdir -p build/fibonnaci
[01:45:30 pm][sanchez]@sanchezs-MacBook-Pro ~/Projects/cpp/cppcon/perfstat (master)
: g++ fibonnaci/fibonnaci.t.cpp fibonnaci/fibonnaci.cpp -o build/fibonnaci/fibonnaci.t.tsk --std=c++14 -L googletest/ -l gtest

: mkdir -p _build/quicksort
[02:52:25 pm][sanchez]@sanchezs-MacBook-Pro ~/Projects/cpp/cppcon/perfstat (master)


: g++ quicksort/quicksort.b.cpp quicksort/quicksort.cpp -o _build/fibonnaci/quicksort.b.tsk --std=c++14 -L benchmark/ -lbenchmark
: g++ quicksort/quicksort.t.cpp quicksort/quicksort.cpp -o _build/quicksort/quicksort.t.tsk --std=c++14 -L googletest/ -l gtest