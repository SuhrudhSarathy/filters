cmake_minimum_required(VERSION 3.2.0)
project(kalman)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(sciplot)

include_directories(include)

# Add Executables from here
add_executable(test1 test/test_cmake.cpp)

add_executable(test2 test/test_sciplot.cpp)
target_link_libraries(test2 sciplot::sciplot)

add_executable(test3 test/test_eigen.cpp)
target_link_libraries(test3 Eigen3::Eigen)

add_executable(test4 test/test_kalman_one_dim.cpp src/kalman_one_dim.cpp)
target_link_libraries(test4 sciplot::sciplot)

# add_executable(test5 test/test_gaussian.cpp)
# target_link_libraries(test5 LINK_PUBLIC gaussian)

