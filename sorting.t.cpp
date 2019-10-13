#include <gtest/gtest.h>
#include "bubblesort.h"
#include "quicksort.h"

TEST(Bubblesort, Works0)
{
    std::vector<int> sorted = {0, 1, 2, 3, 4};
    std::vector<int> unsorted = {4, 2, 1, 3, 0};

    EXPECT_NE(sorted, unsorted);
    
    bubblesort(unsorted);

    EXPECT_EQ(sorted, unsorted);
}

TEST(Quicksort, Works0)
{
    std::vector<int> sorted = {0, 1, 2, 3, 4};
    std::vector<int> unsorted = {4, 2, 1, 3, 0};

    EXPECT_NE(sorted, unsorted);
    
    quicksort(unsorted);

    EXPECT_EQ(sorted, unsorted);
}

TEST(Both, Work)
{
    std::vector<int> sorted = {0, 1, 2, 3, 4};
    std::vector<int> unsorted_b = {4, 2, 1, 3, 0};
    std::vector<int> unsorted_q(unsorted_b);

    EXPECT_NE(sorted, unsorted_b);
    
    bubblesort(unsorted_b);
    quicksort(unsorted_q);

    EXPECT_EQ(sorted, unsorted_b);
    EXPECT_EQ(unsorted_b, unsorted_q);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


