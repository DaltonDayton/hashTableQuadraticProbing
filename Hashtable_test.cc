#include <gtest/gtest.h>
#include "Hashtable.h"

// Test for the default constructor
TEST(HashtableConstructor, DefaultConstructor)
{
    Hashtable h1;
    EXPECT_EQ(h1.size(), 0);
    EXPECT_EQ(h1.capacity(), 7);
    EXPECT_DOUBLE_EQ(h1.getLoadFactorThreshhold(), .65);
}
