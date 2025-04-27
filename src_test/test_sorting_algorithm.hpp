#pragma once

#include <vector>
#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"
#include "SortingAlgorithm.cpp"

using namespace std;

namespace SortLibrary {


// Tests for BubbleSort 
TEST(TestBubbleSort, ClassVector){
    // Testing with the vector used in class
    vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    BubbleSort<int>(v);
    vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

TEST(TestBubbleSort, MinimumAppearingMoreThanOnce){
    // Testing with a vector with its minimum appearing more than once
    vector<int> v1 = {2, 3, 0, 0, 1, 0};
    BubbleSort<int>(v1);
    vector<int> sortedV1 = {0, 0, 0, 1, 2, 3};
    EXPECT_EQ(v1, sortedV1);
}

TEST(TestBubbleSort, MaximumAppearingMoreThanOnce){
    // Testing with a vector with its minimum appearing more than once
    vector<int> v1 = {2, 3, 0, 0, 1, 0};
    BubbleSort<int>(v1);
    vector<int> sortedV1 = {0, 0, 0, 1, 2, 3};
    EXPECT_EQ(v1, sortedV1);
}

TEST(TestBubbleSort, OnlyNegativeNumbers){
    // Testing with a vector with only negative numbers
    vector<int> v3 = {-9, -13, -5, -10, -2, -7, -9, -4, -6, -12};
    BubbleSort<int>(v3);
    vector<int> sortedV3 = {-13, -12, -10, -9, -9, -7, -6, -5, -4, -2};
    EXPECT_EQ(v3, sortedV3);
}


// Tests for HeapSortNotImplemented 
TEST(TestHeapSortNotImplemented, ClassVector){
    vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    HeapSortNotImplemented<int>(v);
    vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

TEST(TestHeapSortNotImplemented, MinimumAppearingMoreThanOnce){
    vector<int> v1 = {2, 3, 0, 0, 1, 0};
    HeapSortNotImplemented<int>(v1);
    vector<int> sortedV1 = {0, 0, 0, 1, 2, 3};
    EXPECT_EQ(v1, sortedV1);
}

TEST(TestHeapSortNotImplemented, MaximumAppearingMoreThanOnce){
    vector<int> v1 = {2, 3, 0, 0, 1, 0};
    HeapSortNotImplemented<int>(v1);
    vector<int> sortedV1 = {0, 0, 0, 1, 2, 3};
    EXPECT_EQ(v1, sortedV1);
}

TEST(TestHeapSortNotImplemented, OnlyNegativeNumbers){
    vector<int> v3 = {-9, -13, -5, -10, -2, -7, -9, -4, -6, -12};
    HeapSortNotImplemented<int>(v3);
    vector<int> sortedV3 = {-13, -12, -10, -9, -9, -7, -6, -5, -4, -2};
    EXPECT_EQ(v3, sortedV3);
}


// Tests for HeapSortSemiImplemented 
TEST(TestHeapSortSemiImplemented, ClassVector){
    vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    HeapSortSemiImplemented<int>(v);
    vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

TEST(TestHeapSortSemiImplemented, MinimumAppearingMoreThanOnce){
    vector<int> v1 = {2, 3, 0, 0, 1, 0};
    HeapSortSemiImplemented<int>(v1);
    vector<int> sortedV1 = {0, 0, 0, 1, 2, 3};
    EXPECT_EQ(v1, sortedV1);
}

TEST(TestHeapSortSemiImplemented, MaximumAppearingMoreThanOnce){
    vector<int> v1 = {2, 3, 0, 0, 1, 0};
    HeapSortSemiImplemented<int>(v1);
    vector<int> sortedV1 = {0, 0, 0, 1, 2, 3};
    EXPECT_EQ(v1, sortedV1);
}

TEST(TestHeapSortSemiImplemented, OnlyNegativeNumbers){
    vector<int> v3 = {-9, -13, -5, -10, -2, -7, -9, -4, -6, -12};
    HeapSortSemiImplemented<int>(v3);
    vector<int> sortedV3 = {-13, -12, -10, -9, -9, -7, -6, -5, -4, -2};
    EXPECT_EQ(v3, sortedV3);
}


// Tests for HeapSortFullyImplemented 
TEST(TestHeapSortFullyImplemented, ClassVector){
    vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    HeapSortFullyImplemented<int>(v);
    vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

TEST(TestHeapSortFullyImplemented, MinimumAppearingMoreThanOnce){
    vector<int> v1 = {2, 3, 0, 0, 1, 0};
    HeapSortFullyImplemented<int>(v1);
    vector<int> sortedV1 = {0, 0, 0, 1, 2, 3};
    EXPECT_EQ(v1, sortedV1);
}

TEST(TestHeapSortFullyImplemented, MaximumAppearingMoreThanOnce){
    vector<int> v1 = {2, 3, 0, 0, 1, 0};
    HeapSortFullyImplemented<int>(v1);
    vector<int> sortedV1 = {0, 0, 0, 1, 2, 3};
    EXPECT_EQ(v1, sortedV1);
}

TEST(TestHeapSortFullyImplemented, OnlyNegativeNumbers){
    vector<int> v3 = {-9, -13, -5, -10, -2, -7, -9, -4, -6, -12};
    HeapSortFullyImplemented<int>(v3);
    vector<int> sortedV3 = {-13, -12, -10, -9, -9, -7, -6, -5, -4, -2};
    EXPECT_EQ(v3, sortedV3);
}

}
