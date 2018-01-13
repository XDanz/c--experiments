//
// Created by danter on 2018-01-13.
//
//
//

/**
 * 1. clone google-test
 * 2. $ make
 * 3. $ sudo make install
 * 4. Check CMakeLists.txt how to create target
 *
 */

#include "gmock/gmock.h"  // Brings in Google Mock.
#include "gtest/gtest.h"  // Brings in Google Mock.
#include "QSorta.h"  // Brings in Google Mock.


TEST(QSorta, test_swap_void)
{
    char a[] = "Test";
    char b[] = "Dani";

    qsorta::swap(a, b, 4);

    ASSERT_STREQ("Dani", a);
    ASSERT_STREQ("Test", b);
}

TEST(QSorta, test_swap_int)
{
    int a[10] = {0, 1,2,3,4,5,6,7,8,9};
    int b[10] = {10, 11,12,13,14,15,16,17,18,19};
    qsorta::swapint(a,b, 10);
    ASSERT_THAT(a, testing::ElementsAre(10, 11, 12, 13, 14, 15, 16, 17, 18, 19));
}
