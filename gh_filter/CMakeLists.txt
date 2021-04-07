cmake_minimum_required(VERSION 3.2.0)
project(gh_filter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3 3.3 REQUIRED NO_MODUlE)
find_package(sciplot)

include_directories(include)

# add executables from here
add_executable(test_1 tests/test_1.cpp src/GHFilter.cpp)
target_link_libraries(test_1 sciplot::sciplot)

add_executable(test_2 tests/test_2.cpp src/GHFilter.cpp)
target_link_libraries(test_2 sciplot::sciplot)