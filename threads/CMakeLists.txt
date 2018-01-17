cmake_minimum_required(VERSION 3.5)

find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
add_executable(hello_thread HelloThread.cpp)
add_executable(lambda_thread LambdaThread.cpp)

target_link_libraries(hello_thread
        pthread
        )

target_link_libraries(lambda_thread
        pthread
        )

