cmake_minimum_required(VERSION 3.2.0)
project(filter_math)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

find_package(Eigen3 3.3 REQUIRED NO_MODUlE)
find_package(sciplot)

set(SOURCE test/test_1.cpp src/calculus.cpp src/gaussian.cpp)
set(SOURCE2 test/test_2.cpp src/calculus.cpp src/gaussian.cpp)
add_executable(test_math_1 ${SOURCE})
target_link_libraries(test_math_1 sciplot::sciplot)

add_executable(test_math_2 ${SOURCE2})
target_link_libraries(test_math_2 sciplot::sciplot)

add_executable(test_math_3 test/test_3.cpp src/gaussianXd.cpp)
target_link_libraries(test_math_3 sciplot::sciplot)

add_library(Gaussian src/gaussian.cpp)

