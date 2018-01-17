
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()
find_package(Threads REQUIRED)

add_executable(moveA MoveA.cpp MoveA.h)
add_executable(arrayWrapper ArrayWrapper.cpp ArrayWrapper.h)
