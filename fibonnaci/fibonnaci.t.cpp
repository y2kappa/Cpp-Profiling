#include <gtest/gtest.h>
#include "fibonnaci.h"


TEST(Iterative, Works0)
{
    EXPECT_EQ(fib_iterative(0), 0);
}

TEST(Iterative, Works1)
{
    EXPECT_EQ(fib_iterative(1), 1);
}

TEST(Iterative, Works2)
{
    EXPECT_EQ(fib_iterative(2), 1);
}

TEST(Recursive, Works0)
{
    EXPECT_EQ(fib_recursive(0), 0);
}

TEST(Recursive, Works1)
{
    EXPECT_EQ(fib_recursive(1), 1);
}

TEST(Recursive, Works2)
{
    EXPECT_EQ(fib_recursive(2), 1);
}

TEST(Both, Work)
{
    std::map<unsigned int, unsigned int> expected = {
        {0, 0},
        {1, 1},
        {2, 1},
        {3, 2},
        {4, 3},
        {5, 5},
        {6, 8}, 
        {7, 13},
        {8, 21},
        {9, 34},
        {10, 55},
        {11, 89},
        {12, 144},
        {13, 233},
        {14, 377},
        {14, 377},
        {15, 610},
        {16, 987},
        {17, 1597},
        {18, 2584},
        {19, 4181},
        {20, 6765}
    };

    for (auto kw : expected)
    {
        unsigned int iterative = fib_iterative(kw.first);
        unsigned int recursive = fib_recursive(kw.first);
        EXPECT_EQ(iterative, recursive);
        EXPECT_EQ(iterative, kw.second);
    }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
