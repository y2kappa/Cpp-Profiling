#include <gtest/gtest.h>
#include <vector>
#include "quicksort.h"
#include <algorithm>

using namespace anon;
using namespace std;

TEST(Partition, ThorwsRange0)
{
    vector<int> v;
    EXPECT_THROW(partition(v, 0, 0), out_of_range);
}

TEST(Partition, ThrowRange1)
{
    vector<int> v;
    EXPECT_THROW(partition(v, -1, 2), out_of_range);
}

TEST(Partition, LeftGreaterThanRight)
{
    vector<int> v;
    v.resize(5);
    EXPECT_THROW(partition(v, 4, 2), invalid_argument);
}

TEST(Partition, ValidArgs)
{
    vector<int> v;
    v.resize(5);
    EXPECT_NO_THROW(partition(v, 2, 4));
    EXPECT_NO_THROW(partition(v, 2, 2));
    EXPECT_NO_THROW(partition(v, 4, 4));
    EXPECT_NO_THROW(partition(v, 4, 5));
}

TEST(Partition, Works0)
{
    vector<int> given = {2, 1}; 
    vector<int> expected = {1, 2};

    EXPECT_NE(given, expected);
    size_t pivot = partition(given, 0, 1);

    EXPECT_EQ(given, expected);
    EXPECT_EQ(pivot, 1);
}

TEST(Partition, Works1)
{
    vector<int> given = {3, 2, 1}; 
    vector<int> expected = {1, 2, 3};

    EXPECT_NE(given, expected);
    int pivot = partition(given, 0, 2);

    EXPECT_EQ(given, expected);
    EXPECT_EQ(pivot, 2);
}

TEST(Partition, Works2)
{
    vector<int> given = {-2, 0, 3, 2, 1}; 
    vector<int> expected = {-2, 0, 1, 2, 3};

    EXPECT_NE(given, expected);
    int pivot = partition(given, 0, 4);

    EXPECT_EQ(given, expected);
    EXPECT_EQ(pivot, 4);
}

TEST(SwapVectElems, Works)
{
    vector<int> v1 = {0, 1};
    vector<int> v2 = {1, 0};

    swap(v1[0], v1[1]);
    EXPECT_EQ(v1, v2);
}

TEST(Quicksort, Works0)
{
    std::vector<int> sorted = {0, 1, 2, 3, 4};
    std::vector<int> unsorted = {4, 2, 1, 3, 0};

    EXPECT_NE(sorted, unsorted);
    
    quicksort(unsorted);

    EXPECT_EQ(sorted, unsorted);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
