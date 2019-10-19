#include <gtest/gtest.h>
#include <iostream>
#include "vector.h"



TEST(Partition, Works1)
{
    EXPECT_EQ((Vector<int>()).size(), 0);
}

TEST(Partition, Works2)
{
    Vector<float> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(5);

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.get(0), 1);
    EXPECT_EQ(v.get(1), 1);
    EXPECT_EQ(v.get(2), 5);
}

TEST(Partition, Works3)
{

    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(20);

    // std::cout << v[v.size()-1] << std::endl;

    EXPECT_EQ(v[v.size()-1], 20);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
