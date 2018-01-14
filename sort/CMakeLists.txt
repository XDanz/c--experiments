
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()
find_package(Threads REQUIRED)
add_executable(quick_sort QuickSort.cpp)
add_executable(quick_sort2 QuickSort2.cpp)

add_executable(merge_sort MergeSort.cpp)

add_executable(runQSortTest QSortaTest.cpp QSorta.h)
target_link_libraries(runQSortTest gtest gtest_main)
target_link_libraries(runQSortTest gtest ${CMAKE_THREAD_LIBS_INIT})

add_executable(quickSortTest QSortTest.cpp)
target_link_libraries(quickSortTest gtest gtest_main)
target_link_libraries(quickSortTest gtest ${CMAKE_THREAD_LIBS_INIT})


add_executable(quickSortTest2 QSortTest2.cpp)
target_link_libraries(quickSortTest2 gtest gtest_main)
target_link_libraries(quickSortTest2 gtest ${CMAKE_THREAD_LIBS_INIT})
