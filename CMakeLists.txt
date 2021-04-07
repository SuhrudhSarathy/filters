cmake_minimum_required(VERSION 3.2.0)
project(filters)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(sciplot)

add_subdirectory(filter_math)
add_subdirectory(kalman)
add_subdirectory(gh_filter)

