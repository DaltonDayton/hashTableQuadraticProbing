#include <gtest/gtest.h>
#include "Hashtable.h"

// Test for inserting into the Hashtable
TEST(HashtableFunctions, Insert)
{
    Hashtable h;
    h.insert(10);
    EXPECT_EQ(h.size(), 1);
    EXPECT_NE(h.indexOf(10), -1);
    h.insert(17); // Should hash to the same index as 10 (because 10 % 7 == 17 % 7) and be resolved by quadratic probing.
    EXPECT_EQ(h.size(), 2);
    EXPECT_NE(h.indexOf(17), -1);
}

// Test for removing from the Hashtable
TEST(HashtableFunctions, Remove)
{
    Hashtable h;
    h.insert(10);
    h.insert(17);
    h.remove(10);
    EXPECT_EQ(h.size(), 1);
    EXPECT_EQ(h.indexOf(10), -1);
    h.remove(17);
    EXPECT_EQ(h.size(), 0);
    EXPECT_EQ(h.indexOf(17), -1);
    // Removing a non-existent value should not change the size.
    h.remove(25);
    EXPECT_EQ(h.size(), 0);
    EXPECT_EQ(h.indexOf(25), -1);
}

// Test for indexOf method
TEST(HashtableFunctions, IndexOf)
{
    Hashtable h;
    h.insert(10);
    h.insert(17);
    EXPECT_NE(h.indexOf(10), -1);
    EXPECT_NE(h.indexOf(17), -1);
    EXPECT_EQ(h.indexOf(25), -1); // Value not in table
}

// Test for clearing the Hashtable
TEST(HashtableFunctions, Clear)
{
    Hashtable h;
    h.insert(10);
    h.insert(17);
    h.clear();
    EXPECT_EQ(h.size(), 0);
    EXPECT_EQ(h.indexOf(10), -1);
    EXPECT_EQ(h.indexOf(17), -1);
}

// Test for quadratic probing
TEST(HashtableFunctions, QuadraticProbing)
{
    Hashtable h;
    h.insert(10);
    int index10 = h.indexOf(10);
    h.insert(17);
    int index17 = h.indexOf(17);
    h.insert(24);
    int index24 = h.indexOf(24);
    EXPECT_EQ(h.size(), 3);
    EXPECT_NE(index10, index17); // Ensure different indices due to probing
    EXPECT_NE(index10, index24);
    EXPECT_NE(index17, index24);
}

// Test for hashing function
TEST(HashtableFunctions, HashFunction)
{
    Hashtable h;
    EXPECT_EQ(h.capacity(), 7); // Assuming the hashing function works with mod 7, we can test some specific values
    h.insert(7);                // Should go to index 0, since 7 % 7 = 0
    h.insert(14);               // Should also go to index 0, since 14 % 7 = 0 but will be moved due to quadratic probing
    EXPECT_EQ(h.size(), 2);
    EXPECT_NE(h.indexOf(7), -1);
    EXPECT_NE(h.indexOf(14), -1);
}

// Test for Rehashing
TEST(HashtableFunctions, Rehash)
{
    Hashtable h;
    int initialCapacity = h.capacity();
    for (int i = 0; i < initialCapacity; ++i)
    {
        h.insert(i);
    }
    // After inserting elements equal to initialCapacity, it should have been rehashed
    EXPECT_GT(h.capacity(), initialCapacity);
}

// Test for handling non-positive values
TEST(HashtableFunctions, HandleNonPositiveValues)
{
    Hashtable h;
    h.insert(-1);
    EXPECT_EQ(h.size(), 1);
    EXPECT_NE(h.indexOf(-1), -1);
    h.insert(0);
    EXPECT_EQ(h.size(), 2);
    EXPECT_NE(h.indexOf(0), -1);
}
