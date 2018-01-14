//
// Created by danter on 2018-01-13.
//

#include "gmock/gmock.h"  // Brings in Google Mock.
#include "gtest/gtest.h"  // Brings in Google Mock.
#include "QuickSort.h"  // Brings in Google Mock.

TEST(QSortTest2, test_quick_sort)
{
    // Add this in evaluation expression (Shift+F8) (int(*)[10])a
    int a[10] = { 0, 3, 5, 1, 2, 4, 9, 6, 7, 8};
    sort::qsort2(a , 10);
    ASSERT_THAT(a, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
}

