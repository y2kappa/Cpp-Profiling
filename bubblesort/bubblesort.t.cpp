
#include <gtest/gtest.h>
#include <vector>
#include "bubblesort.h"
#include <algorithm>

using namespace std;

TEST(Bubblesort, Works0)
{
    std::vector<int> sorted = {0, 1, 2, 3, 4};
    std::vector<int> unsorted = {4, 2, 1, 3, 0};

    EXPECT_NE(sorted, unsorted);
    
    bubblesort(unsorted);

    EXPECT_EQ(sorted, unsorted);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
